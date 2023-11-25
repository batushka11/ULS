#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str) {
    char *temp = mx_strtrim(str);
    int count = 0;
    	
    for (int i = 0; i < mx_strlen(temp); i++) {
        if(mx_isspace(temp[i]) && !mx_isspace(temp[i + 1])) {
            count++;
        } 
        else if(!mx_isspace(temp[i])) {
            count++;
        }
    }
    	
    int j = 0;
    char *result = mx_strnew(count);
    	
    for (int i = 0; i < mx_strlen(temp); i++) {
        if (mx_isspace(temp[i]) && !mx_isspace(temp[i + 1])) {
            result[j] = ' ';
            j++;
        } else if(!mx_isspace(temp[i])){
            result[j] = temp[i];
            j++;
        }
    }
    mx_strdel(&temp);
    	
    return result;
}


