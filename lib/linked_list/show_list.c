/*
** EPITECH PROJECT, 2021
** LINKED_LIST
** File description:
** show list
*/

#include "list.h"
#include "../my/my.h"
#include <stddef.h>
#include <unistd.h>

void show_list(node *list)
{
    node *tmp = list;

    my_printf(1, "{");
    while (tmp != NULL) {
        my_printf(1,"%i", tmp->data);
        tmp = tmp->next;
    }
    my_printf(1, "}");
    return;
}
