#include "../inc/uls.h"

char* mx_get_time_str(t_fileinfo file, unsigned short flags) {
    time_t tm = 0;
    if(flags & FLAG_c){
        tm = file.st.st_ctime;
    }
    else if(flags & FLAG_u) {
        tm = file.st.st_atime;
    }
    else{
        tm = file.st.st_mtime;
    }
    
    char* time_str = ctime(&tm);
    
    if(flags & FLAG_T) {
        return mx_strndup(&time_str[4], 20);
    }

    time_t cur_time = time(NULL);
    time_t diff = (cur_time - tm) > 0 ? cur_time - tm : tm - cur_time;

    if(diff > 15768000) {
        char* tmp = mx_strndup(&time_str[4], 7);
        char* res = mx_strjoin(tmp, &time_str[19]);
        res[mx_strlen(res) - 1] = '\0';
        free(tmp);
        
        return res;
    }

    return mx_strndup(&time_str[4], 12);
}


