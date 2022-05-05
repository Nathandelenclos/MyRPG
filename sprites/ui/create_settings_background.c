/*
** EPITECH PROJECT, 2021
** create long button
** File description:
** Sprite - create long button
*/

#include "../include/rpg.h"

int create_sprite_bg_settings(scene *d)
{
    sfVector2f pos[2] = {{0, 0}, {0, 0}};
    game_obj *settings_bg =
        create_obj(d, NULL,
        create_rect(d->hub->mode.width, d->hub->mode.height, 0, 0), pos);
    settings_bg->name = "settings_bg";
    settings_bg->grp = UI;
    settings_bg->display = 1;
    sfSprite_setTextureRect(settings_bg->sprite, settings_bg->rect);
    put_in_end(&d->objs, settings_bg);
    return 0;
}
