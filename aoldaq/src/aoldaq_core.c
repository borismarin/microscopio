#include "aoldaq_core.h"

aoldaq_t *aoldaq_create_instance(aoldaq_args_t *p_args) {
    aoldaq_t *p_state = malloc(sizeof(aoldaq_t));

    pipe_t *pipe = pipe_new(sizeof(uint32_t), 0);

    p_state->p_data_tx = pipe_producer_new(pipe);
    p_state->p_data_rx = pipe_consumer_new(pipe);

    pipe_free(pipe);

    fpga_args_t args = { 1 };
    fpga_t *p_fpga = fpga_init_session(&args);

    if(!p_fpga) {
        // Bailing out, something happened
        pipe_consumer_free(p_state->p_data_rx);
        pipe_producer_free(p_state->p_data_tx);

        free(p_state);

        return NULL;
    }

    p_state->p_fpga = p_fpga;

    p_state->running = 0;
    p_state->quit = 0;

    if(pthread_create(&p_state->daq_thread, NULL, &daq_thread_fun, p_args) != 0) {
        // Bailing out, something happened
        pipe_consumer_free(p_state->p_data_rx);
        pipe_producer_free(p_state->p_data_tx);

        free(p_state);

        return NULL;
    }

    return p_state;
}

void aoldaq_destroy_instance(aoldaq_t *p_state) {
    if(!p_state) return;

    aoldaq_stop(p_state);

    p_state->quit = 1;
    pthread_join(p_state->daq_thread, NULL);

    free(p_state);
}

void aoldaq_start(aoldaq_t *p_state) {
    p_state->running = 1;
}

void aoldaq_stop(aoldaq_t *p_state) {
    p_state->running = 0;
}

void *daq_thread_fun(void *p_args_raw) {
    aoldaq_t *p_args = (aoldaq_t*) p_args_raw;

    uint32_t *back_buffer = (uint32_t *) malloc(sizeof(uint32_t) * p_args->block_size);

    while(!p_args->quit) {
        if(!p_args->running) continue;
        
        uint32_t read = fpga_read(p_args->p_fpga, back_buffer, p_args->block_size);

        pipe_push(p_args->p_data_tx, back_buffer, read);
    }

    free(back_buffer);

    return NULL;
}

ramp_t *aoldaq_get_ramps(aoldaq_t *p_state, uint32_t n_cycles, uint32_t *p_read) {
    // TODO read!
    return NULL;
}
