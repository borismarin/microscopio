#ifndef __AOLDAQ_H
#define __AOLDAQ_H

#include <stdint.h>

/**
 * This is the main header for the AOLDAQ API.
 * 
 * Written by: Eduardo Renesto
 */

// Some macro hackery so that our .dll will actually export our symbols
#ifdef AOL_WIN32
#ifdef AOL_BUILD
#define AOL_DLL __declspec(dllexport)
#else
#define AOL_DLL __declspec(dllimport)
#endif
#else
#define AOL_DLL
#endif

/// This struct holds the state of the API. We pass this around so that 
/// we don't have nasty global variables.
typedef struct aoldaq_t aoldaq_t;

/// Describes in which mode we are running.
typedef enum {
    AOLDAQ_MODE_BITMAP,     /// Bitmap mode. Used to test data reconstruction.
    AOLDAQ_MODE_RANDOM,     /// Simulated mode. Randomly generates data.
    AOLDAQ_MODE_REAL        /// Uses the real hardware.
} aoldaq_mode;

/// Describes the imaging modes.
/// See Core/data_structures/ImagingMode.m
typedef enum {
    AOLDAQ_IMAGING_MODE_RASTER,     /// Raster mode
    AOLDAQ_IMAGING_MODE_POINTING,   /// Pointing mode
    AOLDAQ_IMAGING_MODE_FUNCTIONAL, /// Functional mode
    AOLDAQ_IMAGING_MODE_MINISCAN,   /// Miniscan mode
    AOLDAQ_IMAGING_MODE_LAST        /// Don't use this one! This is just for tagging
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

    /// The running mode.
    aoldaq_mode mode;

    /// The scan parameters.
    aoldaq_scan_params_t scan_params;

    /// The number of channels to spawn. 
    uint8_t n_channels;

    /// The data of the bitmap image. Only for bitmap mode.
    uint32_t *bitmap_data;

    /// The width of the image. Only for bitmap mode.
    uint32_t bitmap_width;

    /// The height of the image. Only for bitmap mode.
    uint32_t bitmap_height;
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
AOL_DLL extern aoldaq_t *aoldaq_create_instance(aoldaq_args_t *p_args);

/// Perform cleanup and destroy an instance.
///     p_state: a pointer to an instance.
AOL_DLL extern void aoldaq_destroy_instance(aoldaq_t *p_state);

/// Start transferring data from the FPGA into the FIFO.
///     p_state: a pointer to an instance.
AOL_DLL extern void aoldaq_start(aoldaq_t *p_state);

/// Stop transferring data from the FPGA into the FIFO.
//      p_state: a pointer to an instance.
AOL_DLL extern void aoldaq_stop(aoldaq_t *p_state);

/// DEPRECATED! Use `aoldaq_get_voxels` to get voxels from each channel.
/// Pop the ramps from the FIFO.
///     p_state: a pointer to an instance.
///     n_cycles: the number of cycles to get.
///     buf: a pointer to the buffer that will receive the ramps.
//  Returns the number of ramps read.
AOL_DLL extern uint32_t aoldaq_get_ramps(aoldaq_t *p_state, uint32_t n_cycles, ramp_t *buf);

/// Get voxels from the FIFO of the dedicated channel.
///     p_state: a pointer to an instance.
///     channel: the channel to read from (TODO).
///     n_voxels: the number of voxels to read.
///     buf: a pointer to the preallocated buffer that will receive the voxels.
/// Returns the number of voxels read.
AOL_DLL extern uint32_t aoldaq_get_voxels(aoldaq_t *p_state, uint8_t channel, uint32_t *buf, uint32_t n_voxels);

/// Gets the NiFpga session object from the underlying FPGA
/// object. This is used to setup the physical acquisition FPGA
/// through Matlab. Once we deal with the initialization ourselves, 
/// this function will removed.
AOL_DLL extern uint32_t aoldaq_get_nifpga_session(aoldaq_t *p_state);

#endif 
