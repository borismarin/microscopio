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
        function self = AOLDAQ(sofile, hfile, block_size, acq_mode, scan_params, bitmap_data, bitmap_width, bitmap_height)
            if not(libisloaded('libaoldaq'))
                [notfound, warnings] = loadlibrary(sofile, hfile);

                %if notfound
                    %error('Could not open %s', sofile);
                %end
            end

            args = {};
            args.block_size = block_size;
            args.mode = uint32(acq_mode);
            args.scan_params = scan_params;
            
            % Bitmap data has been passed, let's use
            if exist('bitmap_data', 'var')
                args.bitmap_data = bitmap_data;
                args.bitmap_width = bitmap_width;
                args.bitmap_height = bitmap_height;
            else
                args.bitmap_data = [];
                args.bitmap_width = 0;
                args.bitmap_height = 0;
            end

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
            nread = calllib('libaoldaq', 'aoldaq_get_voxels', self.Instance, channel, data_ptr, n_voxels);

            if not(data_ptr.isNull())
                data = data_ptr.Value;
            end

            clear data_ptr;
        end

        function delete(self)
            calllib('libaoldaq', 'aoldaq_stop', self.Instance);
            calllib('libaoldaq', 'aoldaq_destroy_instance', self.Instance);

            clear self.Instance;

            unloadlibrary('libaoldaq');
        end
    end
end
