#include "uls.h"

int mx_check_flags(int argc, char *argv[], unsigned short *flags) {
    int count_files = 0;

    for(int i = 1; i < argc; i++) {
        if(argv[i][0] == '-') {
            for(int j = 1; j < mx_strlen(argv[i]); j++) {
                switch(argv[i][j]) {
                    case 'l':
                        *flags = (*flags | FLAG_l) & ~(FLAG_C | FLAG_1);
                        break;
                    case 'R':
                        *flags = *flags | FLAG_R;
                        break;
                    case 'A':
                        if( !(*flags & FLAG_a)){
                            *flags = *flags | FLAG_A;
                        }
                        break;
                    case 'a':
                        *flags = (*flags | FLAG_a) & ~FLAG_A;
                        break;
                    case 'G':
                        *flags = *flags | FLAG_G;
                        break;
                    case 'h':
                        *flags = *flags | FLAG_h;
                        break;
                    case '@':
                        *flags = *flags | FLAG_AT;
                        break;
                    case 'e':
                        *flags = *flags | FLAG_e;
                        break;
                    case 'T':
                        *flags = *flags | FLAG_T;
                        break;
                    case '1':
                        *flags = (*flags | FLAG_1) & ~(FLAG_C | FLAG_l);
                        break;
                    case 'C':
                        *flags = (*flags | FLAG_C) & ~(FLAG_1 | FLAG_l);
                        break;
                    case 'r':
                        *flags = *flags | FLAG_r;
                        break;
                    case 't':
                        *flags = *flags | FLAG_t;
                        break;
                    case 'u':
                        *flags = (*flags | FLAG_u) & ~FLAG_c;
                        break;
                    case 'c':
                        *flags = (*flags | FLAG_c) & ~FLAG_u;
                        break;
                    case 'S':
                        *flags = *flags | FLAG_S;
                        break;
                    default:
                        mx_printerr("uls: invalid option -- ");
                        write(STDERR_FILENO, &argv[i][j], 1);
                        mx_printchar('\n');
                        mx_printerr("usage: uls [-@ABCFGHILOPRSTUWabcdefghiklmnopqrstuvwx1] [file ...]\n");
                        exit(EXIT_FAILURE);
                }
            }
        }
        else {
            count_files++;
        }
    }

    return count_files;
}

