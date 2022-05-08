/*
** EPITECH PROJECT, 2021
** MyRPG - utils
** File description:
** utils function for collision
*/

#include "../include/rpg.h"

sfVector2f get_direction(sfUint32 *radar, maps *m)
{
    if (radar[0] != radar[7]) {
        if (radar[3] != radar[7])
            return create_vector2f(0, -10);
        if (radar[2] != radar[7])
            return create_vector2f(-10, 0);
        return create_vector2f(-10, -10);
    }
    if (radar[3] != radar[7]) {
        if (radar[5] != radar[7])
            return create_vector2f(10, 0);
        return create_vector2f(10, -10);
    }
    if (radar[2] != radar[7]) {
        if (radar[5] != radar[7])
            return create_vector2f(0, 10);
        return create_vector2f(-10, 10);
    }
    if (radar[5] != radar[7])
        return create_vector2f(10, 10);
    return create_vector2f(0, 0);
}

void collision_map(scene *s, game_obj *g)
{
    sfTexture *texture =
        sfTexture_create(s->hub->mode.width, s->hub->mode.height);
    sfTexture_updateFromRenderWindow(texture, s->hub->window, 0, 0);
    sfImage *i = sfTexture_copyToImage(texture);
    sfUint32 green = sfColor_toInteger(sfColor_fromRGBA(80, 155, 102, 255));
    sfUint32 top_left = sfColor_toInteger(sfImage_getPixel(i, 920, 615));
    sfUint32 middle_left = sfColor_toInteger(sfImage_getPixel(i, 920, 640));
    sfUint32 bottom_left = sfColor_toInteger(sfImage_getPixel(i, 920, 660));
    sfUint32 top_right = sfColor_toInteger(sfImage_getPixel(i, 1000, 615));
    sfUint32 middle_right = sfColor_toInteger(sfImage_getPixel(i, 1000, 640));
    sfUint32 bottom_right = sfColor_toInteger(sfImage_getPixel(i, 1000, 660));
    sfUint32 bottom_middle = sfColor_toInteger(sfImage_getPixel(i, 942, 660));
    sfUint32 all[] = {
        top_left, middle_left, bottom_left, top_right, middle_right,
        bottom_right, bottom_middle, green, 0
    };
    sfSprite_move(g->sprite, get_direction(all, get_object(s, "maps")->data));
    sfImage_destroy(i);
    sfTexture_destroy(texture);
}
