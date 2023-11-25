#include "../inc/uls.h"

int mx_count_cols(int max, unsigned short flags) {
    int cols = 0;
    struct winsize ws;
    ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
    
    if(flags & FLAG_G){
       if (max % 2 == 0) {
            max += 1;
        }
        else {
            max += 2 - (max % 2);
        }       
    }
    else {
        if (max % 8 == 0) {
            max += 8;
        }
        else {
            max += 8 - (max % 8);
        }
    }

    if(ws.ws_col / max != 0) {
        cols = ws.ws_col / max;
    }
    else {
        cols = 1;
    }
    if(max * cols > ws.ws_col && cols != 1){
        cols--;
    }

    return cols;
}

