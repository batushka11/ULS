#include "../inc/uls.h"

void mx_print_dir(char* name, unsigned short flags, int* exit_status) {
    DIR* dir = NULL;
    struct s_fileinfo *files = NULL;
    struct dirent *entry = NULL;
    int size = 0;

    size = mx_dir_size(name, flags);
    dir = mx_opendir(name);

    files = (t_fileinfo*)malloc(size * sizeof(t_fileinfo));

    if(mx_strcmp(name, ".") != 0){
        mx_printstr(name);
        mx_printstr(":\n");
    }

    int i = 0;
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
                        mx_print_dir(path, flags, exit_status);
                    }
                }

                free(path);
            }
        }
    }

    for(int i = 0; i < size; i++) {
        free(files[i].name);
        free(files[i].path);
    }
    free(files);

    closedir(dir);
}

