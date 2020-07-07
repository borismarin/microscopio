#include <stdlib.h>
#define HAVE_STRUCT_TIMESPEC
#include <pthread.h>
#include <aoldaq/aoldaq.h>

#include "os_pipe.h"

#include "fpga.h"

typedef struct {
    uint8_t channel_idx;
    aoldaq_t *p_state;
} thread_args;

/// Actual declaration of the instance struct. 
/// this should only be used internally: the clients will never
/// need to hassle directly with this.
struct aoldaq_t {
    // General stuff
    pthread_t *daq_threads;

    /// The write ends of the FIFO. One for each channel.
    os_pipe_producer_t **p_data_txs;
    /// The read ends of the FIFO. One for each channel.
    os_pipe_consumer_t **p_data_rxs;

    /// The number of channels
    uint8_t n_channels;

    /// This is our "bucket size". The thread will pull `block_size` voxels
    /// from the FPGA into the FIFO at once.
    uint32_t block_size;

    // Control flow
    /// Controls whether we are getting data from the FIFO
    volatile unsigned char running;
    /// Controls if we should terminate the thread
    volatile unsigned char quit;

    // Scan Params
    aoldaq_scan_params_t scan_params;

    // FPGA
    fpga_t *p_fpga;

    thread_args *p_thread_args;
};

static void *daq_thread_fun(void *p_args_raw); 
