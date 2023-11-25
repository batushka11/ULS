#include "../inc/uls.h"

DIR* mx_opendir(const char* name, int* exit_status) {
    DIR* dir = opendir(name);

    if(dir == NULL) {
        mx_printerr("uls: ");
        mx_printerr(name);
        mx_printerr(": ");
        mx_printerr(strerror(errno));
        mx_printerr("\n");
        *exit_status = EXIT_FAILURE;
    }

    return dir;
}

