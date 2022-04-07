/*
** EPITECH PROJECT, 2021
** MyRPG - Manager
** File description:
** main manager sprites
*/

#include "../include/rpg.h"

void sprites_manager(scene *d)
{
    game_obj *obj;
    node *tmp = d->objs;
    int z_index = 1;
    while (tmp != NULL) {
        obj = (game_obj *) tmp->data;
        if (obj->display == z_index) {
            sfRenderWindow_drawSprite(d->hub->window, obj->sprite, NULL);
        }
        if (tmp->next == NULL && z_index <= 5) {
            z_index++;
            tmp = d->objs;
        }
        tmp = tmp->next;
    }
}
