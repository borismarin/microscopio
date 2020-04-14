#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "pipe.h"

#define COUNT (2048*2048)
#define BUFSIZE 4

typedef uint32_t Pixel; // Tipo do pixel, igual a impl. em rust

typedef struct {
    pipe_producer_t *pProducer;
    char bSilent;
    unsigned int nBufSize;
} producer_thread_args_t;

void *producer_func(void* pArgs) {
    producer_thread_args_t *args = (producer_thread_args_t*) pArgs;
    pipe_producer_t *producer = args->pProducer;

    Pixel data = 42;

    struct timespec begin;
    memset(&begin, 0, sizeof(struct timespec));
    struct timespec end;
    memset(&end, 0, sizeof(struct timespec));

    clock_gettime(CLOCK_REALTIME, &begin);
    for(int i = 0; i < COUNT; i++) {
        pipe_push(producer, &data, 1);
    }
    clock_gettime(CLOCK_REALTIME, &end);

    double delta = (end.tv_sec - begin.tv_sec) + 
                    (end.tv_nsec - begin.tv_nsec) / 1000000000;

    double average = delta/COUNT;

    if(!args->bSilent) {
        printf("Average write: %g ns/px\n", average * 1000000000);
    } else {
        printf("%g\n", average * 1000000000);
    }

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

void *producer_buffered_func(void* pArgs) {
    producer_thread_args_t *args = (producer_thread_args_t*) pArgs;
    pipe_producer_t *producer = args->pProducer;

    struct timespec begin;
    memset(&begin, 0, sizeof(struct timespec));
    struct timespec end;
    memset(&end, 0, sizeof(struct timespec));

    Pixel *data = malloc(sizeof(Pixel) * BUFSIZE);
    memset(data, 42, sizeof(Pixel) * BUFSIZE);

    clock_gettime(CLOCK_REALTIME, &begin);
    for(int i = 0; i < COUNT / args->nBufSize; i++) {
        pipe_push(producer, data, args->nBufSize);
    }
    clock_gettime(CLOCK_REALTIME, &end);

    double delta = (end.tv_sec - begin.tv_sec) + 
                    (end.tv_nsec - begin.tv_nsec) / 1000000000;

    double average = delta/COUNT;

    if(!args->bSilent) {
        printf("Average write: %g ns/px\n", average * 1000000000);
    } else {
        printf("%g\n", average * 1000000000);
    }

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
    char bSilent = 0;
    unsigned int nBufSize = BUFSIZE;

    if(argc < 2) {
        printf("Usage: %s [nBufSize] [silent]\n", argv[0]);
        printf("\twhere\n");
        printf("\t\tnBufSize: the size of the buffer in pixels\n");
        printf("\t\tsilent: either 0 (verbose) or 1 (silent)\n");
        printf("\n");
        printf("Assuming a buffer size of %d\n", BUFSIZE);
    }

    if(argc >= 2) {
        nBufSize = atoi(argv[1]);
    }

    if(argc >= 3) {
        bSilent = (char) atoi(argv[2]);
    }

    /*if(!bSilent) printf("Running single pixel per send...\n");*/
    /*pthread_t producer_thread;*/
    /*pthread_t consumer_thread;*/

    /*pipe_t *pipe = pipe_new(sizeof(Pixel), 0);*/

    /*pipe_producer_t *producer = pipe_producer_new(pipe);*/
    /*pipe_consumer_t *consumer = pipe_consumer_new(pipe);*/

    /*pipe_free(pipe);*/

    producer_thread_args_t args;
    /*args.pProducer = producer;*/
    args.nBufSize = nBufSize;
    args.bSilent = bSilent;

    /*pthread_create(&producer_thread, NULL, &producer_func, &args);*/
    /*pthread_create(&consumer_thread, NULL, &consumer_func, consumer);*/

    /*pthread_join(producer_thread, NULL);*/
    /*pthread_join(consumer_thread, NULL);*/

    if(!bSilent) printf("Running buffered with chunks of %d pixels...\n", nBufSize);
    pthread_t producer_buffered_thread;
    pthread_t consumer_buffered_thread;

    pipe_t *pipe_buffered = pipe_new(sizeof(Pixel), 0);

    pipe_producer_t *producer_buffered = pipe_producer_new(pipe_buffered);
    pipe_consumer_t *consumer_buffered = pipe_consumer_new(pipe_buffered);

    pipe_free(pipe_buffered);

    args.pProducer = producer_buffered;

    pthread_create(&producer_buffered_thread, NULL, &producer_buffered_func, &args);
    pthread_create(&consumer_buffered_thread, NULL, &consumer_buffered_func, consumer_buffered);

    pthread_join(producer_buffered_thread, NULL);
    pthread_join(consumer_buffered_thread, NULL);
}
