/*
** EPITECH PROJECT, 2021
** MyRPG - utils
** File description:
** utils function for collision
*/

#include "../include/rpg.h"

sfVector2f get_direction(int delta_time, sfUint32 *radar, maps *m)
{
    float px = (10 * (float) delta_time) / 8;
    if (radar[0] != radar[7] && radar[0] != radar[8]) {
        if (radar[3] != radar[7] && radar[3] != radar[8])
            return create_vector2f(0, -px);
        if (radar[2] != radar[7] && radar[2] != radar[8])
            return create_vector2f(-px, 0);
        return create_vector2f(-px, -px);
    }
    if (radar[3] != radar[7] && radar[3] != radar[8]) {
        if (radar[5] != radar[7] && radar[5] != radar[8])
            return create_vector2f(px, 0);
        return create_vector2f(px, -px);
    }
    if (radar[2] != radar[7] && radar[5] != radar[8]) {
        if (radar[5] != radar[7] && radar[5] != radar[8])
            return create_vector2f(0, px);
        return create_vector2f(-px, px);
    }
    if (radar[5] != radar[7] && radar[5] != radar[8])
        return create_vector2f(px, px);
    return create_vector2f(0, 0);
}

void collision_map(scene *s, game_obj *g)
{
    sfTexture *texture =
        sfTexture_create(s->hub->mode.width, s->hub->mode.height);
    sfTexture_updateFromRenderWindow(texture, s->hub->window, 0, 0);
    sfImage *i = sfTexture_copyToImage(texture);
    sfUint32 green = sfColor_toInteger(sfColor_fromRGBA(80, 155, 102, 255));
    sfUint32 green_night = sfColor_toInteger(sfColor_fromRGBA(31, 61, 40, 255));
    sfUint32 top_left = sfColor_toInteger(sfImage_getPixel(i, 920, 615));
    sfUint32 middle_left = sfColor_toInteger(sfImage_getPixel(i, 920, 640));
    sfUint32 bottom_left = sfColor_toInteger(sfImage_getPixel(i, 920, 660));
    sfUint32 top_right = sfColor_toInteger(sfImage_getPixel(i, 1000, 615));
    sfUint32 middle_right = sfColor_toInteger(sfImage_getPixel(i, 1000, 640));
    sfUint32 bottom_right = sfColor_toInteger(sfImage_getPixel(i, 1000, 660));
    sfUint32 bottom_middle = sfColor_toInteger(sfImage_getPixel(i, 942, 660));
    sfUint32 all[] = {
        top_left, middle_left, bottom_left, top_right, middle_right,
        bottom_right, bottom_middle, green, green_night, 0
    };
    sfSprite_move(g->sprite,
        get_direction(s->hub->delta_time, all, get_object(s, "maps")->data));
    sfImage_destroy(i);
    sfTexture_destroy(texture);
}
