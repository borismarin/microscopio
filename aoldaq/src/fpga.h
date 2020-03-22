#ifndef __AOLDAQ_FPGA_H
#define __AOLDAQ_FPGA_H

#include <stdint.h>

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

    // For FPGA_MODE_BITMAP
    uint32_t* bitmap_data;
    uint32_t bitmap_size;
    uint32_t bitmap_cursor;
} fpga_t;

typedef struct {
    fpga_mode mode;

    // For FPGA_MODE_BITMAP
    uint32_t* bitmap_data;
    uint32_t bitmap_width;
    uint32_t bitmap_height;
} fpga_args_t;

/// Initializes a FPGA session.
fpga_t *fpga_init_session(fpga_args_t *p_args);

void fpga_destroy(fpga_t *p_session);

uint32_t fpga_read(fpga_t *p_session, uint32_t *buf, uint32_t n);

static void fpga_gen_random(uint32_t *buf, uint32_t n);

#endif
