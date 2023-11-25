#include "../inc/libmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {
	char *temporary = dst;
	int counter = 0;
	
	while (*src && counter < len) {
		*dst++ = *src++;
		counter++;
	}
	*dst = 0;
	
	return (char*)temporary;
}


