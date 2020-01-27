#include "libmx.h"

void mx_pop_front(t_list **head) {
    t_list *next_list = NULL;

    if (head == NULL || *head == NULL)
        return;
    next_list = (*head)->next;
    free(*head);
    *head = next_list;
}
