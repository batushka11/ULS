#include "../inc/libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {
    bool end = false;
    
    while(!end){
        end = true;
        
        for(t_list* i = lst; i->next != NULL; i = i->next)
            if(cmp(i->data, i->next->data)){
                end = false;
                void *t = i->data;
                i->data = i->next->data;
                i->next->data = t;
            }
    }
    
    return lst;
}


