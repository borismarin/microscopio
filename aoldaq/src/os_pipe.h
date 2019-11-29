#ifndef __OS_PIPE_H
#define __OS_PIPE_H

#include <stddef.h>

/***
 * This encapsulates the native pipe structure for the operating system.
 */

typedef struct os_pipe_consumer_t os_pipe_consumer_t;
typedef struct os_pipe_producer_t os_pipe_producer_t;

void os_pipe_create(os_pipe_consumer_t *p_consumer, os_pipe_producer_t *p_producer);
void os_pipe_destroy(os_pipe_consumer_t *p_consumer, os_pipe_producer_t *p_producer);

void os_pipe_write(os_pipe_producer_t *p_producer, void *data, size_t bytes);
size_t os_pipe_read(os_pipe_consumer_t *p_consumer, void *data, size_t bytes);

#endif
