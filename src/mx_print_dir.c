#include "../inc/uls.h"

void mx_print_dir(char* name, unsigned short flags, int* exit_status, bool print_name) {
    if(print_name) {
        mx_printstr(name);
        mx_printstr(":\n");
    }
    DIR* dir = opendir(name);
    if(dir == NULL){
        if(flags & FLAG_l){
            mx_printstr("total 0\n");
        }
        mx_print_error(name);
        *exit_status = EXIT_FAILURE;
    }
    else {
        int size = mx_dir_size(name, flags);
        struct s_fileinfo *files = (t_fileinfo*)malloc(size * sizeof(t_fileinfo));
        
        int i = 0;
        struct dirent *entry = NULL;
        while( (entry = readdir(dir)) != NULL ) {
            if(mx_strcmp(entry->d_name, ".") == 0 || mx_strcmp(entry->d_name, "..") == 0) {
                if(!(flags & FLAG_a)) {
                    continue;
                }
            } 
            else if(entry->d_name[0] == '.') {
                if(!(flags & (FLAG_a | FLAG_A))) {
                    continue;
                }
            }
            files[i].path = mx_concat_dirs(name, entry->d_name);
            files[i].name = mx_strdup(entry->d_name);
            int res = lstat(files[i].path, &files[i].st);
            if(res == -1){
                mx_print_error(files[i].name);
                *exit_status = EXIT_FAILURE;
            }
            i++;
        }
        mx_sort_files(files, size, flags);
        
        mx_print_files(files, size, flags, true);

        if(flags & FLAG_R) {
            for(int i = 0; i < size; i++) {
                if(mx_strcmp(files[i].name, ".") != 0 && mx_strcmp(files[i].name, "..") != 0) {
                    char *path = mx_concat_dirs(name, files[i].name);
                    struct stat st;
                    int res = lstat(path, &st);

                    if(res != -1){
                        if((st.st_mode & S_IFMT) == S_IFDIR) {
                            mx_printchar('\n');
                            mx_print_dir(path, flags, exit_status, true);
                        }
                    }

                    free(path);
                }
            }
        }

        mx_free_fileinfo_arr(files, size);
        closedir(dir);
    }
}

