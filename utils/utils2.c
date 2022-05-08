/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** utils2
*/

#include "../include/rpg.h"

void switch_scene(scene *d, state s)
{
    scene *new = get_scene(d, s);
    if (new->active != NULL)
        new->active(d, new);
    d->hub->state = s;
}

text *search_for_n_text(scene *s, char *name, int n)
{
    text *t;
    node *tmp = s->texts;
    while (tmp != NULL) {
        t = (text *)tmp->data;
        if (t != NULL && my_strncmp(t->string, name, n))
            return t;
        tmp = tmp->next;
    }
    return NULL;
}
