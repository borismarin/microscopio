/**
 * TODO:
 *  - add support for multiple channels
 */

#include "aoldaq_core.h"

aoldaq_t *aoldaq_create_instance(aoldaq_args_t *p_args) {
    aoldaq_t *p_state = malloc(sizeof(aoldaq_t));

    // Allocate data for our FIFOs
    p_state->p_data_txs = malloc(sizeof(os_pipe_producer_t*) * p_args->n_channels);
    p_state->p_data_rxs = malloc(sizeof(os_pipe_consumer_t*) * p_args->n_channels);

    p_state->p_fpgas = malloc(sizeof(fpga_t*) * p_args->n_channels);

    p_state->daq_threads = malloc(sizeof(pthread_t) * p_args->n_channels);
    p_state->p_thread_args = malloc(sizeof(thread_args) * p_args->n_channels);

    p_state->n_channels = p_args->n_channels;

    p_state->block_size = p_args->block_size;
    p_state->scan_params = p_args->scan_params;

    p_state->running = 0;
    p_state->quit = 0;

    char success = 1;
    char destroy_threads = 0;

    uint8_t i;
    for(i = 0; i < p_args->n_channels && success; i++) {
        p_state->p_data_txs[i] = os_pipe_alloc_producer();
        p_state->p_data_rxs[i] = os_pipe_alloc_consumer();

        os_pipe_create(p_state->p_data_rxs[i], p_state->p_data_txs[i]);

        fpga_args_t args;

        if(p_args->mode == AOLDAQ_MODE_RANDOM) {
            args.mode = FPGA_MODE_RANDOM;
        } else if(p_args->mode == AOLDAQ_MODE_BITMAP) {
            args.mode = FPGA_MODE_BITMAP;
            args.bitmap_data = p_args->bitmap_data;
            args.bitmap_width = p_args->bitmap_width;
            args.bitmap_height = p_args->bitmap_height;
        } else if(p_args->mode == AOLDAQ_MODE_REAL) {
            args.mode = FPGA_MODE_RANDOM;
        }

        fpga_t *p_fpga = fpga_init_session(&args);

        if(!p_fpga) {
            success = 0;
            break;
        }

        p_state->p_fpgas[i] = p_fpga;

        thread_args targs = {
            .channel_idx = i,
            .p_state = p_state,
        };

        p_state->p_thread_args[i] = targs;

        if(pthread_create(p_state->daq_threads + i, NULL, &daq_thread_fun, p_state->p_thread_args + i) != 0) {
            success = 0;
            destroy_threads = 1;
            break;
        }
    }

    if(!success) {
        // Bailing out, something happened
        if(destroy_threads) 
            p_state->quit = 1;

        for(uint8_t j = 0; j < i; j++) {
            if(destroy_threads) {
                pthread_cancel(p_state->daq_threads[i]);
                pthread_join(p_state->daq_threads[i], NULL);
            }

            os_pipe_destroy(p_state->p_data_rxs[j], p_state->p_data_txs[j]);

            os_pipe_free_consumer(p_state->p_data_rxs[j]);
            os_pipe_free_producer(p_state->p_data_txs[j]);
        }

        free(p_state->p_data_txs);
        free(p_state->p_data_rxs);
        free(p_state->p_fpgas);
        free(p_state->daq_threads);
        free(p_state->p_thread_args);
        free(p_state);

        return NULL;
    }

    return p_state;
}

void aoldaq_destroy_instance(aoldaq_t *p_state) {
    if(!p_state) return;

    aoldaq_stop(p_state);

    p_state->quit = 1;

    for(uint8_t i = 0; i < p_state->n_channels; i++) {
        pthread_cancel(p_state->daq_threads[i]);
        pthread_join(p_state->daq_threads[i], NULL);

        os_pipe_destroy(p_state->p_data_rxs[i], p_state->p_data_txs[i]);

        os_pipe_free_consumer(p_state->p_data_rxs[i]);
        os_pipe_free_producer(p_state->p_data_txs[i]);
    }

    free(p_state->p_data_txs);
    free(p_state->p_data_rxs);
    free(p_state->p_fpgas);
    free(p_state->daq_threads);
    free(p_state->p_thread_args);
    free(p_state);
}

void aoldaq_start(aoldaq_t *p_state) {
    p_state->running = 1;
}

void aoldaq_stop(aoldaq_t *p_state) {
    p_state->running = 0;
}

void *daq_thread_fun(void *p_args_raw) {
    thread_args *p_args = (thread_args*) p_args_raw;

    uint32_t *back_buffer = (uint32_t *) malloc(sizeof(uint32_t) * p_args->p_state->block_size);

    while(!p_args->p_state->quit) {
        if(!p_args->p_state->running) continue;
        
        uint32_t read = fpga_read(
                p_args->p_state->p_fpgas[p_args->channel_idx], 
                back_buffer,
                p_args->p_state->block_size
        );

        os_pipe_write(
                p_args->p_state->p_data_txs[p_args->channel_idx],
                back_buffer,
                read * sizeof(uint32_t)
        );
    }

    free(back_buffer);

    return NULL;
}

uint32_t aoldaq_get_ramps(aoldaq_t *p_state, uint32_t n_cycles, ramp_t *buf) {
#if 0
    switch(p_state->scan_params.mode) {
        case AOLDAQ_IMAGING_MODE_RASTER:
            // TODO improve
            // these are hardcoded, just for initial testing.
            buf[0].n_channels = 1;
            buf[0].voxels_per_channel = &p_state->scan_params.voxels_for_ramp;
            if(buf[0].voxels) {
                /*free(buf[0].voxels); // for some reason, RenderDOC doesnt run with this*/
            }
            buf[0].voxels = malloc(sizeof(uint32_t *) * buf[0].n_channels);
            buf[0].voxels[0] = 
                malloc(sizeof(uint32_t) * buf[0].voxels_per_channel[0]);
            
            // read
            /*fpga_read(p_state->p_fpga, buf[0].voxels[0], buf[0].voxels_per_channel[0]);*/
            uint32_t n = os_pipe_read(p_state->p_data_rx, buf[0].voxels[0], buf[0].voxels_per_channel[0] * sizeof(uint32_t));

            return n; // TODO
            break;
        default:
            return 0;
            break;
    }
#endif

    return 0;
}

uint32_t aoldaq_get_voxels(aoldaq_t *p_state, uint8_t channel, uint32_t *buf, uint32_t n_voxels) {
    if(!p_state) {
        return 0;
    }
    
    return os_pipe_read(
            p_state->p_data_rxs[channel],
            buf,
            n_voxels * sizeof(uint32_t)
     );
}
