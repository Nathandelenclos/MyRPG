/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** chest_inventory
*/

#include "../include/rpg.h"

void create_chest_inventory_sprite(scene *d)
{
    sfVector2f vector[2] = {{50, 50}, {0, 0}};
    sfIntRect rect = create_rect(914, 862, 0, 0);
    game_obj *hero = create_obj(d, "chest_inventory", rect, vector);
    hero->name = "chest_inventor";
    hero->grp = UI;
    hero->display = 1;
    sfSprite_setTextureRect(hero->sprite, hero->rect);
    sfRenderWindow_drawSprite(d->hub->window, hero->sprite, NULL);
    put_in_end(&d->objs, hero);
}

void create_chest_background_sprite(scene *d)
{
    sfVector2f vector[2] = {{0, 0}, {0, 0}};
    sfIntRect rect = create_rect(1920, 1080, 0, 0);
    game_obj *hero = create_obj(d, NULL, rect, vector);
    hero->name = "background";
    hero->grp = UI;
    hero->display = 1;
    sfSprite_setTextureRect(hero->sprite, hero->rect);
    sfRenderWindow_drawSprite(d->hub->window, hero->sprite, NULL);
    put_in_end(&d->objs, hero);
}
