#include "../inc/uls.h"

void mx_print_link(const char *path){
    char buff[PATH_MAX];
    ssize_t len = readlink(path, buff, sizeof(buff) - 1);

    if(len != -1){
        buff[len] = '\0';
        mx_printstr(" -> ");
        mx_printstr(buff);
    }
}

