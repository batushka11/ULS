#include "../inc/libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {
    if (s1 == NULL && s2 == NULL) {
        return NULL;
    }
    if (s1 == NULL) {
        return mx_strdup(s2);
    }
    if (s2 == NULL) {
        return mx_strdup(s1);
    }

    char *new_string = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
    
    if (new_string == NULL) {
        return NULL;
    }

    mx_strcpy(new_string, s1);
    mx_strcat(new_string, s2);
    
    return new_string;
}


