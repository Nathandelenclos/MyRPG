/*
** EPITECH PROJECT, 2021
** MyRPG - Manager
** File description:
** main manager sprites
*/

#include "../include/rpg.h"

float get_distance(game_obj *first, game_obj *seconds)
{
    if (first == NULL || seconds == NULL)
        return -1;
    sfVector2f pos1 = sfSprite_getPosition(first->sprite);
    sfVector2f pos2 = sfSprite_getPosition(seconds->sprite);
    double rx =
        (pos1.x + ((first->rect.width / 2.0) * sfSprite_getScale(first->sprite).x))
        -
        (pos2.x + ((seconds->rect.width / 2.0) * sfSprite_getScale(seconds->sprite).x));
    double ry =
        (pos1.y + ((first->rect.height / 2.0) * sfSprite_getScale(first->sprite).y))
        -
        (pos2.y + ((seconds->rect.height / 2.0) * sfSprite_getScale(seconds->sprite).y));
    float range = (float)sqrt(rx * rx + ry * ry);
    return (range);
}

game_obj *get_closer_object(scene *d, game_obj *obj, group grp)
{
    node *tmp = d->objs;
    game_obj *obj_tmp = NULL;
    game_obj *result = NULL;
    float distance = -1;

    while (tmp != NULL) {
        obj_tmp = (game_obj *)tmp->data;
        if (obj_tmp->grp != grp) {
            tmp = tmp->next;
            continue;
        }
        if (distance < 0 || get_distance(obj, obj_tmp) < distance) {
            distance = get_distance(obj, obj_tmp);
            result = obj_tmp;
        }
        tmp = tmp->next;
    }
    return result;
}

void sprites_manager(scene *d)
{
    game_obj *obj;
    node *tmp = d->objs;
    int z_index = 1;

    while (tmp != NULL) {
        obj = (game_obj *) tmp->data;
        if (obj->display == z_index)
            sfRenderWindow_drawSprite(d->hub->window, obj->sprite, NULL);
        if (tmp->next == NULL && z_index <= 5) {
            z_index++;
            tmp = d->objs;
        }
        tmp = tmp->next;
    }
}
