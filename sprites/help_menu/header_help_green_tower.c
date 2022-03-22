/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** menu background sprite
*/

#include "../../include/rpg.h"

void create_header_help_green_tower(scene *d, float x, float y)
{
    sfVector2f vector[2] = {{x, y}, {0, 0}};
    sfIntRect rect = create_rect(500, 294, 1500, 0);
    game_obj *hero = create_obj(d, "help", rect, vector);
    hero->grp = HELP_TOWER_H;
    hero->display = 5;
    hero->name = "header_help_green_tower";
    sfSprite_setTextureRect(hero->sprite, hero->rect);
    sfRenderWindow_drawSprite(d->hub->window, hero->sprite, NULL);
    put_in_list(&d->objs, hero);
}
