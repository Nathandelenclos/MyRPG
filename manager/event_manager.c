/*
** EPITECH PROJECT, 2021
** MyRPG - Manager
** File description:
** events manager
*/

#include "../include/rpg.h"

void events_manage(scene *d)
{
    game_obj *obj;
    node *tmp = d->objs;

    while (tmp != NULL) {
        obj = (game_obj *) tmp->data;
        if (obj->event != NULL)
            obj->event(obj, d);
        tmp = tmp->next;
    }
}
