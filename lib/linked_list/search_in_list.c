/*
** EPITECH PROJECT, 2021
** LINKED LIST
** File description:
** search in list
*/

#include "list.h"

node *search_in_list(node *list, void *ptr)
{
    node *tmp = list;
    while (tmp != NULL) {
        if (tmp->data == ptr)
            return tmp;
        tmp = tmp->next;
    }
    return NULL;
}
