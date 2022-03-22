/*
** EPITECH PROJECT, 2021
** LINKED LIST
** File description:
** reverse linked list
*/

#include <stddef.h>
#include "list.h"

void reverse_list(node **head_ref)
{
    node *prev = NULL;
    node *current = *head_ref;
    node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
