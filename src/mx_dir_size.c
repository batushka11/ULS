#include "../inc/uls.h"

int mx_dir_size(char* path, unsigned short flags) {
    DIR* dir = NULL;
    struct dirent *entry = NULL;
    int size = 0;

    dir = mx_opendir(path);
    while((entry = readdir(dir)) != NULL) {
        if(mx_strcmp(entry->d_name, ".") == 0 || mx_strcmp(entry->d_name, "..") == 0) {
            if(!(flags & FLAG_a)) {
                continue;
            }
        } else if(entry->d_name[0] == '.') {
            if(!(flags & (FLAG_a | FLAG_A))) {
                continue;
            }
        }
        size++;
    }
    closedir(dir);

    return size;
}

