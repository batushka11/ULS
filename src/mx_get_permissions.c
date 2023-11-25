#include "../inc/uls.h"

char* mx_get_permissions(t_fileinfo file) {
    char perms[] = "-rwxrwxrwx ";
    char *res = (char*)malloc(11 * sizeof(char));
    acl_t acl = acl_get_file(file.path, ACL_TYPE_EXTENDED);
    ssize_t xattr = listxattr(file.path, NULL, 0, XATTR_NOFOLLOW);
  
    if(xattr > 0) {
        res[10] = '@';
    }
    else if(acl != NULL) {
        res[10] = '+';
    }
    else {
        res[10] = ' ';
    }
    acl_free(acl);
    
    res[0] = mx_get_file_type(file.st.st_mode);
    for(size_t i = 1; i < 10; i++) {
        res[i] = file.st.st_mode & (1 << (9 - i)) ? perms[i] : '-';
    }

    if(file.st.st_mode & S_ISUID) {
        res[3] = (file.st.st_mode & S_IXUSR) ? 's' : 'S';
    }
    if(file.st.st_mode & S_ISGID) {
        res[6] = (file.st.st_mode & S_IXGRP) ? 's' : 'S';
    }
    if(file.st.st_mode & S_ISVTX) {
        res[9] = (file.st.st_mode & S_IXOTH) ? 't' : 'T';
    }

    return res;
}


