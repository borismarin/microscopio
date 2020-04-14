% This enum describes the acquisition mode that we are using.
% `Bitmap` and `Random` are used for testing and offline usage,
% while the real rig would use the `Real` mode to interact with
% the physical FPGA.
classdef AcquisitionMode < uint32
    enumeration
        % In this mode, the API keeps sending sequentially a predefined array of data.
        % This is mainly used to test data integrity.
        Bitmap(0), 

        % In this mode, the API generates random points.
        Random(1),

        % In this mode, the API uses the real FPGA to download the data.
        Real(2)
    end
end
