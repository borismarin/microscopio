#include <dlfcn.h>

#include <stdio.h>
#include <stdlib.h>

#include <stdint.h>
#include <unistd.h>

typedef uint32_t Pixel;

int main(int argc, char* argv[]) {
    void *lib = dlopen("../server/target/debug/libserver.so", RTLD_LAZY);

    /*void* (*new_instance)(void) = dlsym(lib, "new_instance");*/
    void* (*start_thread)(size_t) = dlsym(lib, "start_thread");
    const void* (*read_data)(size_t) = dlsym(lib, "read_data");
    void* (*stop)(void) = dlsym(lib, "stop");

    /*void *instance = new_instance();*/

    const size_t buf_size = 100;

    start_thread(buf_size);

    const Pixel *data = read_data(buf_size/2);

    for(int i = 0; i < buf_size/2; i++) {
        printf("%d ", data[i]);
    }

    printf("\n");

    data = read_data(buf_size/2);

    for(int i = 0; i < buf_size/2; i++) {
        printf("%d ", data[i]);
    }

    printf("\n");

    return 0;
}
