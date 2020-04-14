#include "os_pipe.h"

#define _GNU_SOURCE
#include <fcntl.h>
#include <unistd.h>

#include <stdlib.h>
#include <stdio.h>

#include <string.h>
#include <errno.h>

#define MAX_PIPE_SIZE 1048576

struct os_pipe_consumer_t {
    int fd;
    fd_set set;
};

struct os_pipe_producer_t {
    int fd;
};

os_pipe_consumer_t *os_pipe_alloc_consumer() {
    return malloc(sizeof(os_pipe_consumer_t));
}

os_pipe_producer_t *os_pipe_alloc_producer() {
    return malloc(sizeof(os_pipe_producer_t));
}

void os_pipe_free_consumer(os_pipe_consumer_t *p_consumer) {
    free(p_consumer);
}

void os_pipe_free_producer(os_pipe_producer_t *p_producer) {
    free(p_producer);
}

void os_pipe_create(os_pipe_consumer_t *p_consumer, os_pipe_producer_t *p_producer) {
    int fds[2];

    pipe(fds);
    if(errno) printf("%s:%d: %s\n", __FILE__, __LINE__, strerror(errno));

    /*fcntl(fds[1], F_SETFL, O_NONBLOCK);*/

    printf("Max pipe size: %d\n", fcntl(fds[1], F_GETPIPE_SZ));
    fcntl(fds[1], F_SETPIPE_SZ, MAX_PIPE_SIZE);
    printf("Max pipe size: %d\n", fcntl(fds[1], F_GETPIPE_SZ));

    p_consumer->fd = fds[0];
    p_producer->fd = fds[1];

    FD_ZERO(&p_consumer->set);
    FD_SET(p_consumer->fd, &p_consumer->set);
}

void os_pipe_destroy(os_pipe_consumer_t *p_consumer, os_pipe_producer_t *p_producer) {
    close(p_consumer->fd);
    close(p_producer->fd);
}

void os_pipe_write(os_pipe_producer_t *p_producer, void *data, size_t bytes) {
    do {
        write(p_producer->fd, data, bytes);
    } while(errno == EAGAIN); // TODO remove this, since we are blocking again
    
    /*printf("wrote\n");*/
}

size_t os_pipe_read(os_pipe_consumer_t *p_consumer, void *data, size_t bytes) {
    size_t nread = read(p_consumer->fd, data, bytes);
    if(nread == -1) return 0; // no data
    if(nread < 0 && errno) printf("%s:%d: %s; nread = %d\n", __FILE__, __LINE__, strerror(errno), nread);
    return nread; 
}
