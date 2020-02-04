#include "aoldaq_core.h"

aoldaq_t *aoldaq_create_instance(aoldaq_args_t *p_args) {
    aoldaq_t *p_state = malloc(sizeof(aoldaq_t));

    p_state->p_data_tx = os_pipe_alloc_producer();
    p_state->p_data_rx = os_pipe_alloc_consumer();

    os_pipe_create(p_state->p_data_rx, p_state->p_data_tx);

    fpga_args_t args = { 1 };
    fpga_t *p_fpga = fpga_init_session(&args);

    if(!p_fpga) {
        // Bailing out, something happened
        os_pipe_destroy(p_state->p_data_rx, p_state->p_data_tx);

        os_pipe_free_consumer(p_state->p_data_rx);
        os_pipe_free_producer(p_state->p_data_tx);

        free(p_state);

        return NULL;
    }

    p_state->p_fpga = p_fpga;
    p_state->scan_params = p_args->scan_params;
    p_state->block_size = p_args->block_size;

    p_state->running = 0;
    p_state->quit = 0;

    if(pthread_create(&p_state->daq_thread, NULL, &daq_thread_fun, p_state) != 0) {
        // Bailing out, something happened
        os_pipe_destroy(p_state->p_data_rx, p_state->p_data_tx);

        os_pipe_free_consumer(p_state->p_data_rx);
        os_pipe_free_producer(p_state->p_data_tx);

        free(p_state);

        return NULL;
    }

    return p_state;
}

void aoldaq_destroy_instance(aoldaq_t *p_state) {
    if(!p_state) return;

    aoldaq_stop(p_state);

    p_state->quit = 1;
    pthread_cancel(p_state->daq_thread);
    pthread_join(p_state->daq_thread, NULL);

    os_pipe_destroy(p_state->p_data_rx, p_state->p_data_tx);

    os_pipe_free_consumer(p_state->p_data_rx);
    os_pipe_free_producer(p_state->p_data_tx);


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

        os_pipe_write(p_args->p_data_tx, back_buffer, read * sizeof(uint32_t));
    }

    free(back_buffer);

    return NULL;
}

uint32_t aoldaq_get_ramps(aoldaq_t *p_state, uint32_t n_cycles, ramp_t *buf) {
    switch(p_state->scan_params.mode) {
        case AOLDAQ_IMAGING_MODE_RASTER:
            // TODO improve
            // these are hardcoded, just for initial testing.
            buf[0].n_channels = 1;
            buf[0].voxels_per_channel = &p_state->scan_params.voxels_for_ramp;
            if(buf[0].voxels) {
                free(buf[0].voxels); // for some reason, RenderDOC doesnt run with this
            }
            buf[0].voxels = malloc(sizeof(uint32_t *) * buf[0].n_channels);
            buf[0].voxels[0] = 
                malloc(sizeof(uint32_t) * buf[0].voxels_per_channel[0]);
            
            // read
            /*fpga_read(p_state->p_fpga, buf[0].voxels[0], buf[0].voxels_per_channel[0]);*/
            os_pipe_read(p_state->p_data_rx, buf[0].voxels[0], buf[0].voxels_per_channel[0] * sizeof(uint32_t));

            return 1; // TODO
            break;
        default:
            return 0;
            break;
    }
}
