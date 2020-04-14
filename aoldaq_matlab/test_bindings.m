sofile = '../aoldaq/build/libaoldaq.so';
hfile = '../aoldaq/include/aoldaq/aoldaq.h';

scan_params = {};
scan_params.mode = uint32(ImagingMode.Raster);
scan_params.voxels_for_ramp = 20;

aoldaq = AOLDAQ(sofile, hfile, 20, AcquisitionMode.Random, scan_params);

aoldaq.start();
fft(rand(10000));
aoldaq.stop();
