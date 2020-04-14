#include "fpga.h"

#include <stdlib.h>
#include <string.h>

fpga_t *fpga_init_session(fpga_args_t *p_args) {
    // check if our pointers are valid
    if(!p_args || (p_args->mode == FPGA_MODE_BITMAP && !p_args->bitmap_data)) {
        return 0;
    }

    fpga_t *p_session = (fpga_t*) malloc(sizeof(fpga_t));
    p_session->mode = p_args->mode;

    if(p_session->mode == FPGA_MODE_BITMAP) {
        p_session->bitmap_size = p_args->bitmap_width * p_args->bitmap_height;
        p_session->bitmap_cursor = 0;
        p_session->bitmap_data = malloc(sizeof(uint32_t) * p_session->bitmap_size);

        memcpy(p_session->bitmap_data, p_args->bitmap_data, sizeof(uint32_t) *
                p_session->bitmap_size);
    }

    return p_session;
}

void fpga_destroy(fpga_t *p_session) {
    free(p_session);
}

uint32_t fpga_read(fpga_t *p_session, uint32_t *buf, uint32_t n) {
    if(p_session->mode == FPGA_MODE_RANDOM) {
        fpga_gen_random(buf, n);
        return n;
    } else if(p_session->mode == FPGA_MODE_BITMAP) {
        uint32_t max = p_session->bitmap_size - p_session->bitmap_cursor;
        uint32_t offset = 0;
        uint32_t read = 0;
        while(n > max) {
            memcpy(buf + offset, 
                    p_session->bitmap_data + p_session->bitmap_cursor,
                    max * sizeof(uint32_t));
            n -= max;
            offset += max;
            read += max;
            p_session->bitmap_cursor = 0;
            max = p_session->bitmap_size;
        }
        memcpy(buf + offset,
                p_session->bitmap_data + p_session->bitmap_cursor,
                n * sizeof(uint32_t));
        read += n;
        p_session->bitmap_cursor += read;

        return n;
    } else {
        // TODO

        return 0;
    }
}

// Fill buf with random data
static void fpga_gen_random(uint32_t *buf, uint32_t n) {
    for(uint32_t i = 0; i < n; i++) {
        /*buf[i] = rand() * UINT32_MAX / RAND_MAX;*/
        buf[i] = rand() % UINT32_MAX;
    }
}
