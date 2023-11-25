#include "../inc/libmx.h"

char *mx_strndup(const char *s, size_t n) {
    if(s == NULL) {
        return NULL;
	}
 	char *dup = mx_strnew(n);
		
 	return mx_strncpy(dup, s, n);
}


