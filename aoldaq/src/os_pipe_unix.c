#include "os_pipe.h"

#define _GNU_SOURCE
#include <fcntl.h>
#include <unistd.h>

struct os_pipe_consumer_t {
    int fd;
};

struct os_pipe_producer_t {
    int fd;
};

void os_pipe_create(os_pipe_consumer_t *p_consumer, os_pipe_producer_t *p_producer) {
    int fds[2];

    pipe2(fds, O_NONBLOCK);

    p_consumer->fd = fds[0];
    p_producer->fd = fds[1];
}

void os_pipe_destroy(os_pipe_consumer_t *p_consumer, os_pipe_producer_t *p_producer) {
    close(p_consumer->fd);
    close(p_producer->fd);
}

void os_pipe_write(os_pipe_producer_t *p_producer, void *data, size_t bytes) {
    write(p_producer->fd, data, bytes);
}

size_t os_pipe_read(os_pipe_consumer_t *p_consumer, void *data, size_t bytes) {
    return read(p_consumer->fd, data, bytes);
}
