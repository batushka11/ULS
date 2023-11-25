#include "../inc/uls.h"

void mx_long_output(t_fileinfo files[], int size, unsigned short flags, bool is_dir) {
    blkcnt_t total = 0;

    char*** info = (char***)malloc(size * sizeof(char**));
    for(int i = 0 ; i < size; i++) {
        info[i] = (char**)malloc(7 * sizeof(char*));
    }

    for(int i = 0 ; i < size; i++) {
        t_fileinfo file = files[i];
        struct passwd* pwd = getpwuid(file.st.st_uid);
        struct group*  grp = getgrgid(file.st.st_gid);
        
        info[i][0] = mx_get_permissions(file);
        info[i][1] = mx_itoa(file.st.st_nlink);
        info[i][2] = mx_strdup(pwd->pw_name);
        info[i][3] = mx_strdup(grp->gr_name);
        info[i][4] = mx_itoa(file.st.st_size);
        info[i][5] = mx_get_time_str(file, flags);      
        info[i][6] = mx_strdup(file.name);
        total += file.st.st_blocks;
    }
    if(is_dir) {
        mx_printstr("total ");
        mx_printlong(total);
        mx_printchar('\n');
    }

    for(int i = 0; i < size; i++) {
        mx_printstr(info[i][0]);
        mx_printnchar(' ', mx_max_element(info, size, 1) - mx_strlen(info[i][1]) + 1);

        mx_printstr(info[i][1]);
        mx_printchar(' ');

        mx_printstr(info[i][2]);
        mx_printnchar(' ', mx_max_element(info, size, 2) - mx_strlen(info[i][2]) + 2);

        mx_printstr(info[i][3]);
        mx_printnchar(' ', mx_max_element(info, size, 3) - mx_strlen(info[i][3]));
        mx_printnchar(' ', mx_max_element(info, size, 4) - mx_strlen(info[i][4]) + 2);

        mx_printstr(info[i][4]);
        mx_printnchar(' ', mx_max_element(info, size, 5) - mx_strlen(info[i][5]) + 1);

        mx_printstr(info[i][5]);
        mx_printchar(' ');

        if(flags & FLAG_G ){
            mx_print_color_name(files[i]);
        }
        else {
            mx_printstr(info[i][6]);
        }

        if((files[i].st.st_mode & S_IFMT) == S_IFLNK){
            mx_print_link(files[i].path);
        }
        mx_printchar('\n');

        if(flags & FLAG_AT) {
            mx_print_xattr(files[i].path);
        }
    }

    for(int i = 0 ; i < size; i++) {
        for(int j = 0 ; j < 7; j++) {
            free(info[i][j]);
        }
        free(info[i]);
    }
    free(info);
}

