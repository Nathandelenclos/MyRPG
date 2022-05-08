/*
** EPITECH PROJECT, 2021
** MyRPG - Manager
** File description:
** events manager
*/

#include "../include/rpg.h"

void events_manage(scene *d, sfEvent event)
{
    game_obj *obj;
    node *tmp = d->objs;

    while (tmp != NULL) {
        obj = (game_obj *) tmp->data;
        if (obj->event != NULL && is_on_window(obj, d))
            obj->event(obj, d, event);
        tmp = tmp->next;
    }
}
