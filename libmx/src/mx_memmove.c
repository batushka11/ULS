#include "../inc/libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    unsigned char *temp_dst = (unsigned char*)dst;
    unsigned char *temp_src = (unsigned char*)src;
	
	while (*temp_src && len--) {
		*temp_dst++ = *temp_src++;
	}
	
	return dst;
}


