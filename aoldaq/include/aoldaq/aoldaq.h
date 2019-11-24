#ifndef __AOLDAQ_H
#define __AOLDAQ_H

#include <stdint.h>

/**
 * This is the main header for the AOLDAQ API.
 * 
 * Written by: Eduardo Renesto
 */

/// This struct holds the state of the API. We pass this around so that 
/// we don't have nasty global variables.
typedef struct aoldaq_t aoldaq_t;

/// Describes the imaging modes.
// TODO add more imaging modes
typedef enum {
    AOLDAQ_IMAGING_MODE_RASTER /// Raster mode
} aoldaq_imaging_mode;

/// Describes the scan parameters. Based on ScanParams.m from the MATLAB toolbox.
// TODO improve
typedef struct {
    aoldaq_imaging_mode mode;
    uint32_t voxels_for_ramp;
} aoldaq_scan_params_t;

/// This struct holds the initialization settings for the AOLDAQ API.
typedef struct {
    /// The size of the block used for dumping data into the fifo
    uint32_t block_size;

    aoldaq_scan_params_t scan_params;
} aoldaq_args_t;

/// This struct holds a single ramp
/// TODO make this more semantically concise with the document
typedef struct {
    /// The number of channels.
   uint8_t n_channels; 

   /// The number voxels per channel.
   uint32_t *voxels_per_channel;

   uint32_t **voxels;
} ramp_t;

/// Create an AOLDAQ instance.
///     p_args: a pointer to a aoldaq_args_t struct
extern aoldaq_t *aoldaq_create_instance(aoldaq_args_t *p_args);

/// Perform cleanup and destroy an instance.
///     p_state: a pointer to an instance.
extern void aoldaq_destroy_instance(aoldaq_t *p_state);

/// Start transferring data from the FPGA into the FIFO.
///     p_state: a pointer to an instance.
extern void aoldaq_start(aoldaq_t *p_state);

/// Stop transferring data from the FPGA into the FIFO.
//      p_state: a pointer to an instance.
extern void aoldaq_stop(aoldaq_t *p_state);

/// Pop the ramps from the FIFO.
///     p_state: a pointer to an instance.
///     n_cycles: the number of cycles to get.
///     buf: a pointer to the buffer that will receive the ramps.
//  Returns the number of ramps read.
extern uint32_t aoldaq_get_ramps(aoldaq_t *p_state, uint32_t n_cycles, ramp_t *buf);

#endif 
