/*
** EPITECH PROJECT, 2021
** MyRPG - FREE
** File description:
** free
*/

#include "../include/rpg.h"

sfVector2f get_w_scale(scene *d, game_obj *obj)
{
    sfVector2u vector = sfRenderWindow_getSize(d->hub->window);
    sfVector2u mode = {d->hub->mode.width, d->hub->mode.height};
    sfVector2f result =
    {(float) vector.x / mode.x,
    (float) vector.y / mode.y};
    return result;
}
