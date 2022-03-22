/*
** EPITECH PROJECT, 2021
** LINKED LIST
** File description:
** delete in list
*/

#include "list.h"
#include <stdlib.h>

void delete_in_list(node **head_ref, void *key)
{
    node *temp = *head_ref, *prev;

    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}
