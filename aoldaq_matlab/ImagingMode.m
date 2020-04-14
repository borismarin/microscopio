% This enum describes the imaging mode. TODO improve
% Currently only Raster mode is implemented.
classdef ImagingMode < uint32
    enumeration
        Raster(0),
        Poiting(1),
        Functional(2),
        Miniscan(3)
    end
end

