#include "fpga.h"

#include <stdlib.h>

fpga_t *fpga_init_session(fpga_args_t *p_args) {
    fpga_t *p_session = (fpga_t*) malloc(sizeof(fpga_t));

    p_session->simulated = p_args->simulated;

    return p_session;
}

void fpga_destroy(fpga_t *p_session) {
    free(p_session);
}

uint32_t fpga_read(fpga_t *p_session, uint32_t *buf, uint32_t n) {
    if(p_session->simulated) {
        // We're running in offline mode, generate random data
        fpga_gen_random(buf, n);
        return n;
    } else {
        return 0;
    }
}

// Fill buf with random data
static void fpga_gen_random(uint32_t *buf, uint32_t n) {
    for(uint32_t i = 0; i < n; i++) {
        buf[i] = rand() % (UINT32_MAX - 1);
    }
}
