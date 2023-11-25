#include "../inc/libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    unsigned char* s1_tmp = (unsigned char*)s1;
    unsigned char* s2_tmp = (unsigned char*)s2;

	size_t counter = 1;
	while (*s1_tmp == *s2_tmp && counter < n) {
		if (*s1_tmp == '\0' && *s2_tmp == '\0')
			return 0;
		s1_tmp++;
		s2_tmp++;
		counter++;
	}
	return *s1_tmp - *s2_tmp;
}


