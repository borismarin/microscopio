#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>

#include <string.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/stat.h>

#include <unistd.h>

#include "common.h"

static pthread_spinlock_t *run_lock;
static char run = 0;

static FILE *ctrl_fifo;
static FILE *data_fifo;

/**
 * We pass this struct to the acquisition thread
 */
typedef struct {
    /**
     * The producer object.
     */
    /*pipe_producer_t *producer;*/

    /**
     * The block size for each `send` call.
     * The greater this number is, the faster the send will be 
     * (in average). 
     * A value too high could cause buffer overflow on the FPGA!
     */
    size_t block_size;

    /**
     * This is what would matter the most for a client.
     * These are the AOL settings relevant for us, i.e. the
     * timings.
     */
    acquire_args_t *pAcquireArgs;
} thread_args_t;

void gen_random_data(pixel_t *ptr, size_t n) {
    for(size_t i = 0; i < n; i++) {
        ptr[i] = rand() % 255;
    }
}

/**
 * This is the main acquisition thread.
 */
void *acquisition_loop(void *pvArgs) {
    thread_args_t *pArgs = (thread_args_t*) pvArgs;

    pixel_t *data = (pixel_t*) malloc(sizeof(pixel_t) * pArgs->block_size);

    while(run) {
        pthread_spin_lock(run_lock);

        gen_random_data(data, pArgs->block_size);
        pipe_push(pArgs->producer, data, pArgs->block_size);

        pthread_spin_unlock(run_lock);
    }

    free(data);

    return NULL;
}

void *signal_handler(int signo) {
    switch(signo) {
        case SIGINT:
        case SIGTERM:
            pthread_spin_lock(run_lock);
            run = 0;
            pthread_spin_unlock(run_lock);
            break;
        default:
            break;
    }

    return NULL;
}

int main(int argc, char* argv[]) {
    printf("[DEBUG] Starting AOL acquisition daemon...\n");

    char *ctrl_fifo_name = getenv("AOL_CTRL_FIFO");

    if(!ctrl_fifo_name)
        ctrl_fifo_name = "/tmp/aol_ctr";

    if(mkfifo(ctrl_fifo_name, 0644)) {
        char *err = strerror(errno);
        printf("[ERR] Failed to create control FIFO %s! %s\n", ctrl_fifo_name, err);

        return -1;
    }

    ctrl_fifo = fopen(ctrl_fifo_name, "rb");

    if(!ctrl_fifo) {
        char *err = strerror(errno);
        printf("[ERR] Failed to open FIFO %s! %s", ctrl_fifo_name, err);

        return -1;
    }

    printf("[DEBUG] Using ctrl FIFO %s\n", ctrl_fifo_name);

    char *data_fifo_name = getenv("AOL_CTRL_FIFO");

    if(!data_fifo_name)
        data_fifo_name = "/tmp/aol_ctr";

    if(mkfifo(data_fifo_name, 0644)) {
        char *err = strerror(errno);
        printf("[ERR] Failed to create data FIFO %s! %s\n", data_fifo_name, err);

        return -1;
    }

    data_fifo = fopen(data_fifo_name, "rb");

    if(!data_fifo) {
        char *err = strerror(errno);
        printf("[ERR] Failed to open FIFO %s! %s", data_fifo_name, err);

        return -1;
    }

    printf("[DEBUG] Using data FIFO %s\n", data_fifo_name);

    run_lock = malloc(sizeof(pthread_spinlock_t));
    pthread_spin_init(run_lock, PTHREAD_PROCESS_PRIVATE);

    run = 1;

    acquisition_args

    pthread_t acq_thread;
    pthread_create(&acq_thread, NULL, acquisition_loop, &args);

    pthread_spin_destroy(run_lock);

    fclose(ctrl_fifo);

    return 0;
}
