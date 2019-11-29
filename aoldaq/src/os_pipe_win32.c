#include "os_pipe.h"

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

struct os_pipe_consumer_t {
    HANDLE fd;
};

struct os_pipe_producer_t {
    HANDLE fd;
};

void os_pipe_create(os_pipe_consumer_t *p_consumer, os_pipe_producer_t *p_producer) {
    CreatePipe(&p_producer->fd, &p_consumer->fd, NULL, 0);
}

void os_pipe_destroy(os_pipe_consumer_t *p_consumer, os_pipe_producer_t *p_producer) {
    CloseHandle(p_consumer->fd);
    CloseHandle(p_producer->fd);
}

void os_pipe_write(os_pipe_producer_t *p_producer, void *data, size_t bytes) {
    WriteFile(p_producer->fd, data, bytes, NULL, NULL);
}

size_t os_pipe_read(os_pipe_consumer_t *p_consumer, void *data, size_t bytes) {
    size_t n_read;

    ReadFile(p_consumer->fd, data, bytes, &n_read, NULL);

    return n_read;
}