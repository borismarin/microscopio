#include <stdlib.h>
#define HAVE_STRUCT_TIMESPEC
#include <pthread.h>
#include <aoldaq/aoldaq.h>

#include "os_pipe.h"

#include "fpga.h"

/// Actual declaration of the instance struct. 
/// this should only be used internally: the clients will never
/// need to hassle directly with this.
struct aoldaq_t {
    // General stuff
    pthread_t daq_thread;
    os_pipe_producer_t *p_data_tx;
    os_pipe_consumer_t *p_data_rx;
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
};

static void *daq_thread_fun(void *p_args_raw); 
