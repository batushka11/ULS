#include "../inc/libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
    unsigned char* dst_tmp = (unsigned char*)dst;
    unsigned char* src_tmp = (unsigned char*)src;

    for(size_t i = 0; i < n; i++) {
        dst_tmp[i] = src_tmp[i];
    }

    return dst;
}


