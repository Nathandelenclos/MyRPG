/*
** EPITECH PROJECT, 2021
** create long button
** File description:
** Sprite - create long button
*/

#include "../include/rpg.h"

int create_sprite_bg_game_over(scene *d)
{
    sfVector2f pos[2] = {{0, 0}, {0, 0}};
    game_obj *game_over =
        create_obj(d, NULL,
        create_rect(d->hub->mode.width, d->hub->mode.height, 0, 0), pos);
    game_over->name = "game_over";
    game_over->grp = UI;
    game_over->display = 1;
    sfSprite_setTextureRect(game_over->sprite, game_over->rect);
    put_in_end(&d->objs, game_over);
    return 0;
}
