#include "../inc/uls.h"

bool mx_cmp_atime(t_fileinfo a, t_fileinfo b) {
    if(a.st.st_atime == b.st.st_atime) {
        if(a.st.st_atimespec.tv_nsec == b.st.st_atimespec.tv_nsec){
            return !mx_cmp_name(a, b);
        }
        return a.st.st_atimespec.tv_nsec < b.st.st_atimespec.tv_nsec;
    }
    return a.st.st_atime < b.st.st_atime;
}

bool mx_cmp_ctime(t_fileinfo a, t_fileinfo b) {
    if(a.st.st_ctime == b.st.st_ctime) {
        if(a.st.st_ctimespec.tv_nsec == b.st.st_ctimespec.tv_nsec) {
            return !mx_cmp_name(a, b);
        }
        return a.st.st_ctimespec.tv_nsec < b.st.st_ctimespec.tv_nsec;
    }
    return a.st.st_ctime < b.st.st_ctime;
}

bool mx_cmp_mtime(t_fileinfo a, t_fileinfo b) {
    if(a.st.st_mtime == b.st.st_mtime) {
        if(a.st.st_mtimespec.tv_nsec == b.st.st_mtimespec.tv_nsec) {
            return !mx_cmp_name(a, b);
        }
        return a.st.st_mtimespec.tv_nsec < b.st.st_mtimespec.tv_nsec;
    }
    return a.st.st_mtime < b.st.st_mtime;
}

bool mx_cmp_name(t_fileinfo a, t_fileinfo b) {
    return mx_strcmp(a.name, b.name) > 0;
}

bool mx_cmp_size(t_fileinfo a, t_fileinfo b) {
    if(a.st.st_size == b.st.st_size) {
        return mx_cmp_name(a, b);
    }
    return a.st.st_size < b.st.st_size;
}

