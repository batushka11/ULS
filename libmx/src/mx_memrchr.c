#include "../inc/libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    unsigned char* temp = (unsigned char*)s + mx_strlen(s);
    size_t counter = 0;
    
    while(temp && counter < n) {
        if(*temp == (unsigned char)c) return temp;
        temp--;
        counter++;
    }

    return NULL;
}


