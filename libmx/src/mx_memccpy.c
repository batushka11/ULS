#include "../inc/libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
    unsigned char* dst_tmp = (unsigned char*)dst;
    unsigned char* src_tmp = (unsigned char*)src;

    for(size_t i = 0; i < n && src_tmp[i] != (unsigned char)c; i++) {
        dst_tmp[i] = src_tmp[i];
    }

    return dst;
}


