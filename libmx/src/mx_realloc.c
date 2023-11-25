#include "../inc/libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    if(ptr == NULL) {
        return malloc(size);
    }
    else if(size == 0) {
        free(ptr);
        return NULL;
    }

    void *temp = malloc(size);
    mx_memcpy(temp, ptr, malloc_size(ptr));
    free(ptr);
    ptr = temp;

    return ptr;
}


