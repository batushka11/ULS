#include "../inc/libmx.h"

char *mx_strdup(const char *s) {
	if(s == NULL) {
		return NULL;
	}
	char *dup = mx_strnew(mx_strlen(s));
		
	return mx_strcpy(dup, s);
}


