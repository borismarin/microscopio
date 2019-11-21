#include <stdlib.h>
#include <stdio.h>

#include <string.h>
#include <errno.h>

#include "common.h"

int main() {
    char *ctrl_fifo_name = getenv("AOL_CTRL_FIFO");

    if(!ctrl_fifo_name)
        ctrl_fifo_name = "/tmp/aol_ctr";

    FILE *ctrl_fifo = fopen(ctrl_fifo_name, "wb");

    if(!ctrl_fifo) {
        char *err = strerror(errno);
        printf("[ERR] Failed to open FIFO %s! %s", ctrl_fifo_name, err);

        return -1;
    }

    FILE *data_fifo = fopen(data_fifo_name, "rb");

    fclose(ctrl_fifo);

    return 0; //stub
}
