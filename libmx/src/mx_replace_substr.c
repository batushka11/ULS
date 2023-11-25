#include "../inc/libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    if(str == NULL || sub == NULL || replace == NULL) {
        return NULL;
    }

    int size = mx_strlen(str) - mx_count_substr(str, sub) * (mx_strlen(sub) - mx_strlen(replace));

    char *temp = mx_strdup(str);
    char *result = (char*)malloc(size + 1);

    int i = 0;
    while(*temp) {
        if(mx_strncmp(temp, sub, mx_strlen(sub)) == 0) {
            mx_strcat(result, replace);
            i += mx_strlen(replace);
            temp += mx_strlen(sub);
        }
        else {
            result[i++] = *temp++;
        }
    }
    result[size] = '\0';

    return result;
}


