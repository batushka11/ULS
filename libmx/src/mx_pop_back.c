#include "../inc/libmx.h"

void mx_pop_back(t_list **list) {
    	if (*list == NULL || list == NULL) {
        	return;
    	}

    	if ((*list)->next == NULL) {
        	free(*list);
        	*list = NULL;
        	return;
    	}
    	
    	t_list *tmp = *list; 
    	while (tmp->next->next != NULL) {
        	tmp = tmp->next;
    	}
    	free(tmp->next);
    	tmp->next = NULL;
    	tmp = NULL;
}


