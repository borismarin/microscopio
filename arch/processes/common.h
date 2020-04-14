#ifndef COMMON_H
#define COMMON_H

#include <stdint.h>

#include "pipe.h"

typedef uint32_t pixel_t;

/**
 * The settings for a particular ramp.
 * Do we need additional arguments here?
 * Or is the timing enough for our purposes?
 */
typedef struct {
    /* (in microseconds) */
    uint32_t dwell_time;
    uint32_t n_pixels;
} ramp_desc_t;

/**
 * The settings for a cycle.
 * A cycle basically describes a set of
 * ramps.
 */
typedef struct {
    uint32_t n_ramps;
    const ramp_desc_t *pRamps;

    /* TODO: Change this
     * i'm just using this voxels_to_read directly
     * because i'm yet to figure out the timings
     * */
    uint32_t voxels_to_read;
} cycle_info_t;

/**
 * The settings needed for data acquisition.
 * This might change a lot in the future.
 * TODO: Mirror more Core/data_structures/ScanParams.m
 */
typedef struct {
    const cycle_info_t *pCycle;

    /**
     * Since this is fixed for all AOL operations,
     * we just leave it as a acquisition argument.
     * We could hardcode it, but it's not good practice at all
     * (in microseconds)
     */
    uint32_t fill_time;


} acquire_args_t;

/**
 * This enum describes the type of control messages we
 * can send through the fifo.
 */
enum {
    AOL_SCAN_START,
    AOL_SCAN_STOP
};

#endif
