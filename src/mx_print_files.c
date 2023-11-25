#include "../inc/uls.h"

void mx_print_files(t_fileinfo files[], int size, unsigned short flags, bool is_dir) {
    int max = mx_max_name_length(files, size);
    int cols = mx_count_cols(max, flags);

    int rows = size / cols;
    if(size % cols != 0) {
        rows += 1;
    }

    if(!isatty(STDOUT_FILENO) || flags & FLAG_1){
        if(flags & FLAG_l){
            mx_long_output(files, size, flags, is_dir);
        }
        else {
            for(int i = 0; i < size; i++){
                    mx_printstr(files[i].name);
                    mx_printchar('\n');
            }
        }
    }
    else if(flags & FLAG_l) {
        mx_long_output(files, size, flags, is_dir);
    }
    else {
            for(int i = 0; i < rows && size > 0; i++) {
                for(int j = 0; j < cols; j++) {
                    int index = i + j * rows;
                    if(index < size ) {
                        if(flags & FLAG_G){
                            mx_print_color_name(files[index]);
                        }
                        else {
                            mx_printstr(files[index].name);
                        }
                        mx_printnchar(' ', max - mx_strlen(files[index].name));
                    }
                    if(j != cols - 1) {
                        if(flags & FLAG_G){
                            mx_printchar(' ');
                        }
                        else{
                            mx_printchar('\t');
                        }
                    }
                }
                mx_printchar('\n');
            }
        }
    }

