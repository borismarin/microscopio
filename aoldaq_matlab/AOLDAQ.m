%% MATLAB bindings for the AOLDAQ C API
% Author(s):
%   Eduardo Renesto
% Revision date:
%   13-04-2020

% The main class for the AOLDAQ object. You will mostly use this 
classdef AOLDAQ < handle
    properties
        Instance
    end

    methods
        function self = AOLDAQ(sofile, hfile, block_size, acq_mode, scan_params, n_channels, nifpga, bitmap_data, bitmap_width, bitmap_height)
            if not(libisloaded('libaoldaq'))
                [notfound, warnings] = loadlibrary(sofile, hfile, 'addheader', 'use_nifpga.h');

                %if notfound
                    %error('Could not open %s', sofile);
                %end
            end

            args = {};
            %args.block_size = block_size;
            args.mode = uint32(acq_mode);
            %args.scan_params = scan_params;
            args.n_channels = n_channels;

            niargs = {};

            if exist('nifpga', 'var')
                %args.nifpga_bitfile = nifpga.bitfile;
                %args.nifpga_signature = nifpga.signature;
                %args.nifpga_resource = nifpga.target;
                %args.nifpga_attribute = nifpga.attribute;
                %args.nifpga_addresses = libpointer('uint32Ptr', nifpga.addresses);

                niargs.bitfile = nifpga.bitfile;
                niargs.signature = nifpga.signature;
                niargs.resource = nifpga.target;
                niargs.attribute = nifpga.attribute;
                niargs.addrs = libpointer('uint32Ptr', nifpga.addresses);
            else
                %args.nifpga_bitfile = '';
                %args.nifpga_signature = '';
                %args.nifpga_resource = '';

                niargs.bitfile = '';
                niargs.signature = '';
                niargs.resource = '';
            end

            niargs_struct = libstruct('NiFpgaArgs', niargs);
            args.nifpga = libpointer('NiFpgaArgsPtr', niargs_struct);
            
            % Bitmap data has been passed, let's use
            %if exist('bitmap_data', 'var')
                %args.bitmap_data = bitmap_data;
                %args.bitmap_width = bitmap_width;
                %args.bitmap_height = bitmap_height;
            %else
                %args.bitmap_data = [];
                %args.bitmap_width = 0;
                %args.bitmap_height = 0;
            %end

            % Create our C structure
            args = libstruct('aoldaq_args_t', args);
            
            % MATLAB, in this case, can handle conversion to pointer easily.
            self.Instance = calllib('libaoldaq', 'aoldaq_create_instance', args);

            clear args;

            if self.Instance.isNull()
                error('Could not initialize the AOLDAQ instance');
            end
        end

        function start(self)
            calllib('libaoldaq', 'aoldaq_start', self.Instance);
        end

        function stop(self)
            calllib('libaoldaq', 'aoldaq_stop', self.Instance);
        end

        function [data, nread] = get_voxels(self, channel, n_voxels)
            marker = 42; % This will show up in memory instead of meaningless 1s or 0s. This makes debugging easier.
            tmp = uint32(marker * ones(1, n_voxels));
            data_ptr = libpointer('uint32Ptr', tmp);
            nread = calllib('libaoldaq', 'aoldaq_get_data', self.Instance, channel, n_voxels, data_ptr);

            if not(data_ptr.isNull())
                data = data_ptr.Value;
            end

            clear data_ptr;
        end
                
        function flush_fifo(self, channel)
           calllib('libaoldaq', 'aoldaq_flush_fifo', self.Instance, channel);
        end

        function session = get_nifpga_session(self)
            session = calllib('libaoldaq', 'aoldaq_get_nifpga_session', self.Instance);
        end

        function flag_nifpga_initialized(self)
            calllib('libaoldaq', 'aoldaq_flag_nifpga_initialized', self.Instance);
        end

        function flag_nifpga_not_initialized(self)
            calllib('libaoldaq', 'aoldaq_flag_nifpga_not_initialized', self.Instance);
        end

        function ok = is_ok(self)
            ok = ~self.Instance.isNull();
        end

        function delete(self)
            calllib('libaoldaq', 'aoldaq_stop', self.Instance);
            calllib('libaoldaq', 'aoldaq_destroy_instance', self.Instance);

            clear self.Instance;

            unloadlibrary('libaoldaq');
        end
    end
end
