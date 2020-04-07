#include "os_pipe.h"

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct os_pipe_consumer_t {
    HANDLE fd;
};

struct os_pipe_producer_t {
    HANDLE fd;
    LPVOID sec_desc;
    LPSECURITY_ATTRIBUTES sec_attr;
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
    free(p_producer->sec_desc);
    free(p_producer->sec_attr);
    free(p_producer);
}

void os_pipe_create(os_pipe_consumer_t *p_consumer, os_pipe_producer_t *p_producer) {
    p_producer->sec_desc = malloc(sizeof(SECURITY_DESCRIPTOR));
    assert(InitializeSecurityDescriptor(p_producer->sec_desc, SECURITY_DESCRIPTOR_REVISION));
    assert(SetSecurityDescriptorDacl(p_producer->sec_desc, TRUE, NULL, FALSE));

    p_producer->sec_attr = malloc(sizeof(SECURITY_ATTRIBUTES));
    p_producer->sec_attr->nLength = (DWORD) sizeof(SECURITY_ATTRIBUTES);
    /*p_producer->sec_attr->lpSecurityDescriptor = p_producer->sec_desc;*/
    p_producer->sec_attr->lpSecurityDescriptor = NULL;
    p_producer->sec_attr->bInheritHandle = TRUE;

    BOOL err = CreatePipe(&p_consumer->fd, &p_producer->fd, p_producer->sec_attr, 0);

    if(!err) {
        DWORD code = GetLastError();
        printf("%s:%d: error %d\n", __FILE__, __LINE__, code);
        abort();
    }
}

void os_pipe_destroy(os_pipe_consumer_t *p_consumer, os_pipe_producer_t *p_producer) {
    CloseHandle(p_consumer->fd);
    CloseHandle(p_producer->fd);
}

void os_pipe_write(os_pipe_producer_t *p_producer, void *data, size_t bytes) {
    BOOL err = WriteFile(p_producer->fd, data, bytes, NULL, NULL);

    if(!err) {
        DWORD code = GetLastError();
        printf("%s:%d: error %d\n", __FILE__, __LINE__, code);
        abort();
    }
}

size_t os_pipe_read(os_pipe_consumer_t *p_consumer, void *data, size_t bytes) {
    size_t n_read;

    BOOL err = ReadFile(p_consumer->fd, data, bytes, &n_read, NULL);

    if(!err) {
        DWORD code = GetLastError();
        printf("%s:%d: error %d\n", __FILE__, __LINE__, code);
        abort();
    }

    return n_read;
}
