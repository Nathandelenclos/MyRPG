/*
** EPITECH PROJECT, 2021
** MyRPG - utils
** File description:
** utils function
*/

#include "../include/rpg.h"

int get_next_index(node *list)
{
    int i = 0;
    node *tmp = list;

    for (; tmp != NULL; ++i)
        tmp = tmp->next;
    return i;
}

void switch_scene(scene *d, state s)
{
    scene *new = get_scene(d, s);
    if (new->active != NULL)
        new->active(d, new);
    d->hub->state = s;
}

game_obj *get_object(scene *d, char *name)
{
    game_obj *obj;
    node *tmp = d->objs;
    while (tmp != NULL) {
        obj = (game_obj *) tmp->data;
        if (my_strcmp(name, obj->name))
            return obj;
        tmp = tmp->next;
    }
    return NULL;
}
