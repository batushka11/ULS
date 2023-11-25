#include "../inc/libmx.h"

void mx_free_list(t_list **head) {
    t_list* prev = NULL;

    while ((*head)->next) {
        prev = *head;
        *head = (*head)->next;
        free(prev->data);
        free(prev);
    }
    free(*head);
}


