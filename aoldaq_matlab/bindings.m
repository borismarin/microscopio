if not(libisloaded('libaoldaq')) 
    loadlibrary('../aoldaq/build_win/libaoldaq.dll', '../aoldaq/include/aoldaq/aoldaq.h')
end

scan_params = {};
scan_params.mode = 1; % Raster
scan_params.voxels_for_ramp = 1;

args = {};
args.block_size = 20;
args.mode = 1; % Random
args.scan_params = scan_params;
args.bitmap_data = 0;
args.bitmap_width = 0;
args.bitmap_height = 0;

args_ptr = libpointer('aoldaq_args_tPtr', libstruct('aoldaq_args_t', args));

instance = calllib('libaoldaq', 'aoldaq_create_instance', args_ptr);

if instance.isNull
    "Instance is null!"
end

% Wait for some data to be generated
calllib('libaoldaq', 'aoldaq_start', instance);
fft(rand(5000)); % This pause accelerates the thermal death of the universe
calllib('libaoldaq', 'aoldaq_stop', instance);

% Let's try getting some ramps!
buf = {};
buf.n_channels = 1;
buf.voxels_per_channel = 1;
buf.voxels = zeros(1, 1);
