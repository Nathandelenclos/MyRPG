/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** banners2
*/

#include "../../include/rpg.h"

void create_white_banner(scene *d)
{
    sfVector2f vector[2] = {{100, 100}, {0, 0}};
    sfIntRect rect = create_rect(13, 17, 0, 0);
    game_obj *hero = create_obj(d, "white_banner", rect, vector);
    set_scale(d, hero->sprite, 10);
    hero->name = "white_banner";
    hero->grp = UI;
    hero->display = 1;
    sfSprite_setTextureRect(hero->sprite, hero->rect);
    sfRenderWindow_drawSprite(d->hub->window, hero->sprite, NULL);
    put_in_end(&d->objs, hero);
}

void create_wreath_banner(scene *d)
{
    sfVector2f vector[2] = {{100, 100}, {0, 0}};
    sfIntRect rect = create_rect(17, 17, 0, 0);
    game_obj *hero = create_obj(d, "wreath_banner", rect, vector);
    set_scale(d, hero->sprite, 10);
    hero->name = "wreath_banner";
    hero->grp = UI;
    hero->display = 1;
    sfSprite_setTextureRect(hero->sprite, hero->rect);
    sfRenderWindow_drawSprite(d->hub->window, hero->sprite, NULL);
    put_in_end(&d->objs, hero);
}
