#include "../inc/libmx.h"

int mx_list_size(t_list *list) {
	int length = 0;
	for(t_list *tmp = list; tmp != NULL; tmp = tmp->next) {
		length++;
	}
	
	return length;
}


