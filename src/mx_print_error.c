#include "../inc/uls.h"

void mx_print_error(const char* filename) {
    mx_printerr("uls: ");
    mx_printerr(filename);
    mx_printerr(": ");
    mx_printerr(strerror(errno));
    mx_printerr("\n");
}


