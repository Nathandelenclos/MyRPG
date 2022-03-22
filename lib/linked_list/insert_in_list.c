/*
** EPITECH PROJECT, 2021
** LINKED LIST
** File description:
** Insert
*/

#include "list.h"
#include <stdlib.h>

void insert_in_list(node *previous, void *data)
{
    node *list1 = malloc(sizeof(node)), *next = previous->next;

    list1->data = data;
    list1->next = next;
    previous->next = list1;
    return;
}
