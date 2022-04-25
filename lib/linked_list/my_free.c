/*
** EPITECH PROJECT, 2021
** LIB MY
** File description:
** free
*/

#include <stdlib.h>

void my_free(void *ptr)
{
    if (ptr == NULL)
        free(ptr);
}