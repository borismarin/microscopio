#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "pipe.h"

#define COUNT (2048*2048)
#define BUFSIZE 1

typedef uint32_t Pixel; // Tipo do pixel, igual a impl. em rust

void *producer_func(void* pProducer) {
    pipe_producer_t *producer = (pipe_producer_t*) pProducer;

    Pixel data = 42;

    clock_t begin = clock();
    for(int i = 0; i < COUNT; i++) {
        pipe_push(producer, &data, 1);
    }
    clock_t end = clock();

    clock_t elapsed = begin - end;
    int elapsed_ns = elapsed * 1000000000 / CLOCKS_PER_SEC;

    float average = ((float) elapsed_ns)/COUNT;

    printf("Average write: %g ns/px\n", average);

    pipe_producer_free(producer);
    
    return NULL;
}

void *consumer_func(void* pConsumer) {
    pipe_consumer_t *consumer = (pipe_consumer_t*) pConsumer;

    int data;

    int n_read;
    while((n_read = pipe_pop(consumer, &data, 1))) {
        // nop lmao
    }

    return NULL;
}

void *producer_buffered_func(void* pProducer) {
    pipe_producer_t *producer = (pipe_producer_t*) pProducer;

    Pixel *data = malloc(sizeof(Pixel) * BUFSIZE);
    memset(data, 42, sizeof(Pixel) * BUFSIZE);

    clock_t begin = clock();
    for(int i = 0; i < COUNT / BUFSIZE; i++) {
        pipe_push(producer, data, BUFSIZE);
    }
    clock_t end = clock();

    clock_t elapsed = begin - end;
    int elapsed_ns = elapsed * 1000000000 / CLOCKS_PER_SEC;

    float average = ((float) elapsed_ns)/COUNT;

    printf("Average write: %g ns/px\n", average);

    pipe_producer_free(producer);
    
    return NULL;
}

void *consumer_buffered_func(void* pConsumer) {
    pipe_consumer_t *consumer = (pipe_consumer_t*) pConsumer;

    Pixel *data = malloc(sizeof(Pixel) * BUFSIZE);

    int n_read;
    while((n_read = pipe_pop(consumer, data, BUFSIZE))) {
        // nop lmao
    }

    return NULL;
}

int main(int argc, char* argv[]) {
    printf("Running single pixel per send...\n");
    pthread_t producer_thread;
    pthread_t consumer_thread;

    pipe_t *pipe = pipe_new(sizeof(Pixel), 0);

    pipe_producer_t *producer = pipe_producer_new(pipe);
    pipe_consumer_t *consumer = pipe_consumer_new(pipe);

    pipe_free(pipe);

    pthread_create(&producer_thread, NULL, &producer_func, producer);
    pthread_create(&consumer_thread, NULL, &consumer_func, consumer);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    printf("Running buffered...\n");
    pthread_t producer_buffered_thread;
    pthread_t consumer_buffered_thread;

    pipe_t *pipe_buffered = pipe_new(sizeof(Pixel), 0);

    pipe_producer_t *producer_buffered = pipe_producer_new(pipe_buffered);
    pipe_consumer_t *consumer_buffered = pipe_consumer_new(pipe_buffered);

    pipe_free(pipe_buffered);

    pthread_create(&producer_buffered_thread, NULL, &producer_buffered_func, producer_buffered);
    pthread_create(&consumer_buffered_thread, NULL, &consumer_buffered_func, consumer_buffered);

    pthread_join(producer_buffered_thread, NULL);
    pthread_join(consumer_buffered_thread, NULL);
}
