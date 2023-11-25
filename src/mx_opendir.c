#include "../inc/uls.h"

DIR* mx_opendir(const char* name) {
    DIR* dir = opendir(name);

    if(dir == NULL) {
        mx_printerr("uls: ");
        mx_printerr(name);
        mx_printerr(": ");
        mx_printerr(strerror(errno));
        exit(EXIT_FAILURE);
    }

    return dir;
}

