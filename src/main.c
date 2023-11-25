#include "../inc/uls.h"

/*----------------------------------------------------------------------------------*/

int mx_get_dirs_arr_size(char* argv[], int argc, unsigned short flags, int* status) {
    int size = 0;

    for(int i = 1; i < argc; i++) {
        if(argv[i][0] != '-') {
            struct stat buf;
            int res = lstat(argv[i], &buf);
            
            if(res == -1) {
                *status = EXIT_FAILURE;
                mx_print_error(argv[i]);
            }
            else {
                if((buf.st_mode & S_IFMT) == S_IFDIR) {
                    size++;
                }
                else if((buf.st_mode & S_IFMT) == S_IFLNK) {
                    struct stat st;
                    stat(argv[i], &st);
                    
                    if((st.st_mode & S_IFMT) == S_IFDIR && !(flags & FLAG_l)) {
                        size++;
                    }
                }
            }
        }
    }

    return size;
}

int mx_get_file_arr_size(char* argv[], int argc, unsigned short flags, int* status) {
   int size = 0;

    for(int i = 1; i < argc; i++) {
        if(argv[i][0] != '-') {
            struct stat buf;
            int res = lstat(argv[i], &buf);
            if(res == -1) {
                *status = EXIT_FAILURE;
                mx_print_error(argv[i]);
            }
            else {
                if((buf.st_mode & S_IFMT) == S_IFLNK) {
                    struct stat st;
                    stat(argv[i], &st);
                    
                    if((st.st_mode & S_IFMT) == S_IFDIR && !(flags & FLAG_l)) {
                        continue;
                    }
                    else {
                        size++;
                    }
                }
                else {
                    size++;
                }
            }
        }
    }

    return size;
}

/*----------------------------------------------------------------------------------*/

int main(int argc, char *argv[]) {  
    unsigned short flags = 0;
    int exit_status = EXIT_SUCCESS;
    int count_files = mx_check_flags(argc, argv, &flags);
    // struct stat nul;
    // lstat("/dev/fbt", &nul);
    // mx_printstr(mx_nbr_to_hex(nul.st_rdev));
    // mx_printchar('\n');
    
    if(count_files > 0) {
        int files_size = 0;
        int dirs_size = 0;

        for(int i = 1; i < argc; i++) {
            if(argv[i][0] != '-') {
                struct stat buf;
                int res = lstat(argv[i], &buf);
                if(res == -1) {
                    exit_status = EXIT_FAILURE;
                    mx_print_error(argv[i]);
                }
                else {
                    if((buf.st_mode & S_IFMT) == S_IFDIR) {
                        dirs_size++;
                    }
                    else if((buf.st_mode & S_IFMT) == S_IFLNK) {
                        struct stat st;
                        stat(argv[i], &st);
                        
                        if((st.st_mode & S_IFMT) == S_IFDIR && !(flags & FLAG_l)) {
                            dirs_size++;
                        }
                        else {
                            files_size++;
                        }
                    }
                    else {
                        files_size++;
                    }
                }
            }
        }
        
        t_fileinfo *files = (t_fileinfo*)malloc(files_size * sizeof(t_fileinfo));
        t_fileinfo *dirs = (t_fileinfo*)malloc(dirs_size * sizeof(t_fileinfo));

        int i = 0;
        int j = 0;
        for(int k = 1; k < argc; k++) {
            if(argv[k][0] != '-') {
                struct stat buf;
                int res = lstat(argv[k], &buf);
            
                if(res != -1) {
                    if((buf.st_mode & S_IFMT) == S_IFDIR) {
                        dirs[i].name = mx_strdup(argv[k]);
                        dirs[i].path = mx_strdup(argv[k]);
                        lstat(argv[k], &dirs[i].st);
                        i++;
                    }
                    else if((buf.st_mode & S_IFMT) == S_IFLNK) {
                        struct stat st;
                        stat(argv[k], &st);
                        
                        if((st.st_mode & S_IFMT) == S_IFDIR && !(flags & FLAG_l)) {
                            char link[PATH_MAX];
                            ssize_t len = readlink(argv[k], link, sizeof(link) - 1);

                            if(len != -1) {
                                link[len] = '\0';
                                dirs[i].name = mx_strdup(argv[k]);
                                dirs[i].path = mx_strdup(link);
                                stat(link, &dirs[i].st);
                                i++;
                            }
                        }
                        else {
                            files[j].name = mx_strdup(argv[k]);
                            files[j].path = mx_strdup(argv[k]);
                            lstat(argv[k], &files[j].st);
                            j++;
                        }
                    }
                    else {
                        files[j].name = mx_strdup(argv[k]);
                        files[j].path = mx_strdup(argv[k]);
                        lstat(argv[k], &files[j].st);
                        j++;
                    }
                }
            }
        }
        mx_sort_files(files, files_size, flags);
        mx_sort_files(dirs, dirs_size, flags);

        if(files_size > 0){
            mx_print_files(files, files_size, flags, false);
        }
        if(dirs_size == 1 && mx_dir_size(dirs[0].path, flags, &exit_status) == 0 && count_files == 1){
            return exit_status;
        }
        for(int i = 0; i < dirs_size; i++) {
            if( i != 0 || files_size > 0){
                mx_printchar('\n');
            }
            mx_print_dir(dirs[i].name, flags, &exit_status, dirs_size > 1 || files_size > 0);
        }

        mx_free_fileinfo_arr(dirs, dirs_size);
        mx_free_fileinfo_arr(files, files_size);
    }
    else {
        mx_print_dir(".", flags, &exit_status, false);
    }
    
    return exit_status;
}

