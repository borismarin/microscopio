#include <stdlib.h>

#include "util.h"

char *read_file(FILE *f, unsigned int *len) {
    fseek(f, 0, SEEK_END);
    *len = (unsigned int) ftell(f);
    rewind(f);

    char *buf = (char*) malloc(sizeof(char) * *len);
    fread(buf, sizeof(char), *len, f);

    return buf;
}
