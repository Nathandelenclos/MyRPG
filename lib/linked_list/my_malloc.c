/*
** EPITECH PROJECT, 2021
** LIB MY
** File description:
** malloc c
*/

#include <stdlib.h>
#include "list.h"

void m_free(node *list, void *size)
{
    node *m;

    if (size == NULL)
        free_list(list, free);
    else {
        m = search_in_list(list, size);
        free(m->data);
        m->data = NULL;
    }
}

void *my_malloc(void *size, int opt)
{
    static node *list = NULL;
    void *m = NULL;

    if (opt) {
        m = malloc((size_t)size);
        if (m == NULL) {
            my_malloc(size, FREE);
            return NULL;
        }
        put_in_list(&list, m);
    } else
        m_free(list, size);
    return m;
}