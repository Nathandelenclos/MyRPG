/*
** EPITECH PROJECT, 2021
** LINKED LIST
** File description:
** put in end
*/

#include "list.h"

int put_in_end(node **list, void *data)
{
    reverse_list(list);
    put_in_list(list, data);
    reverse_list(list);
    return 0;
}
