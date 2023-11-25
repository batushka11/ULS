#include "../inc/libmx.h"

char *mx_strcpy(char *dst, const char *src) {
    char *temporary = dst;

    while (*src) {
        *dst++ = *src++;
    }
    *dst = 0;
    
    return temporary;
}


