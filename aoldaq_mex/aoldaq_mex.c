#include <string.h>

#include <mex.h>

#include "../aoldaq/include/aoldaq/aoldaq.h"

/**
 * MEX Wrapper for the AOLDAQ API.
 *
 * Written by: Eduardo Renesto
 *
 * As a rustacean, this hurts....
 */

// pRhs[0] => func_sel
// pRhs[1] => imaging_mode
// pRhs[2] => voxels_for_ramp
// pRhs[3] => block_size
static void create_instance(int nLhs, mxArray *pLhs[], int nRhs, const mxArray *pRhs[]) {
    if(nRhs < 4) {
        mexPrintf("create_instance: Too few arguments!\n");
        return;
    }

    if(nLhs != 1) {
        mexPrintf("create_instance: Expected 1 nLhs, got %d\n", nLhs);
        return;
    }

    uint32_t imaging_mode    = (uint32_t) *mxGetPr(pRhs[1]);
    uint32_t voxels_for_ramp = (uint32_t) *mxGetPr(pRhs[2]);
    uint32_t block_size      = (uint32_t) *mxGetPr(pRhs[3]);

    if(imaging_mode >= AOLDAQ_IMAGING_MODE_LAST) {
        mexPrintf("create_instance: Unknown imaging mode %d, falling back to raster\n", imaging_mode);
        imaging_mode = AOLDAQ_IMAGING_MODE_RASTER;
    }

    aoldaq_scan_params_t scan_params = {
        .mode = imaging_mode,
        .voxels_for_ramp = voxels_for_ramp
    };

    aoldaq_args_t args = {
        .block_size = block_size,
        scan_params = scan_params
    };

    aoldaq_t *result = aoldaq_create_instance(&args);

    if(!result) {
        mexPrintf("aoldaq_create_instance failed!\n");
        return;
    }

    pLhs[0] = mxCreateNumericMatrix(1,1,mxUINT32_CLASS,mxREAL);
    /*aoldaq_t *ptr = (aoldaq_t*) mxGetData(pLhs[0]);*/

    /*memcpy(result, ptr, sizeof(aoldaq_t)); // OOF*/
}

void mexFunction(int nLhs, mxArray *pLhs[], int nRhs, const mxArray *pRhs[]) {
    if(nRhs < 1) {
        mexPrintf("Too few arguments!\n");
        return;
    }

    uint32_t func_sel = (uint32_t) *mxGetPr(pRhs[0]);
    mexPrintf("func_sel: %d\n", func_sel);

    switch(func_sel) {
        case 0:
            create_instance(nLhs, pLhs, nRhs, pRhs);
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            mexPrintf("Unknown function id %d\n", func_sel);
            return;
    }
}
