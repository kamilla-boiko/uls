#include "libmx.h"

int mx_list_size(t_list *list) {
    int count = 0;
    t_list *tmp = list;
    
    if (!list)
    	return 0;
    count = 1;
    while (tmp->next != NULL) {
        count++;
        tmp = tmp->next;
    }
    return count;
}
