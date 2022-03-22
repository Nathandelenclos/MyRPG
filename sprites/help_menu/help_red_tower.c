/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** menu background sprite
*/

#include "../../include/rpg.h"

void create_help_red_tower(scene *d, float x, float y)
{
    sfVector2f vector[2] = {{x, y}, {0, 0}};
    sfIntRect rect = create_rect(740, 2508, 740, 294);
    game_obj *hero = create_obj(d, "help", rect, vector);
    hero->grp = HELP_TOWER_S;
    hero->display = 5;
    hero->name = "help_red_tower_s";
    sfSprite_setTextureRect(hero->sprite, hero->rect);
    sfRenderWindow_drawSprite(d->hub->window, hero->sprite, NULL);
    put_in_list(&d->objs, hero);
}
