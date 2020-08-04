#ifndef __AOLDAQ_FPGA_H
#define __AOLDAQ_FPGA_H

#include <stdint.h>

#ifdef AOL_USE_NIFPGA
#include "NiFpga.h"
#endif

// Functions related to low-level handling of the FPGA
// TODO document this more

/// Describes how to source the data.
typedef enum {
    FPGA_MODE_RANDOM,
    FPGA_MODE_BITMAP,
    FPGA_MODE_REAL
} fpga_mode;

typedef struct {
    fpga_mode mode;

    uint8_t n_channels;

    // For FPGA_MODE_BITMAP
    uint32_t* bitmap_data;
    uint32_t bitmap_size;
    uint32_t bitmap_cursor;

#ifdef AOL_USE_NIFPGA
    volatile char nifpga_initialized;
    NiFpga_Session nifpga_session;
    uint32_t *nifpga_addresses;
#endif
} fpga_t;

typedef struct {
    fpga_mode mode;

    uint8_t n_channels;

    // For FPGA_MODE_BITMAP
    uint32_t* bitmap_data;
    uint32_t bitmap_width;
    uint32_t bitmap_height;

#ifdef AOL_USE_NIFPGA
    // For FPGA_MODE_REAL
    const char *nifpga_bitfile;
    const char *nifpga_signature;
    const char *nifpga_resource;
    uint32_t    nifpga_attribute;
    uint32_t   *nifpga_addresses;
#endif
} fpga_args_t;

/// Initializes a FPGA session.
fpga_t *fpga_init_session(fpga_args_t *p_args);

void fpga_destroy(fpga_t *p_session);

uint32_t fpga_read(fpga_t *p_session, uint8_t channel, uint32_t *buf, uint32_t n);

#ifdef AOL_USE_NIFPGA
NiFpga_Session fpga_get_nifpga(fpga_t *p_session);
void fpga_nifpga_flag_initialized(fpga_t *p_session);
void fpga_nifpga_flag_not_initialized(fpga_t *p_session);
#endif

static void fpga_gen_random(uint32_t *buf, uint32_t n);

#endif
