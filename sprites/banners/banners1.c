/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** banners
*/

#include "../../include/rpg.h"

void create_blue_banner(scene *d)
{
    sfVector2f vector[2] = {{100, 100}, {0, 0}};
    sfIntRect rect = create_rect(13, 17, 0, 0);
    game_obj *hero = create_obj(d, "blue_banner", rect, vector);
    set_scale(d, hero->sprite, 10);
    hero->name = "blue_banner";
    hero->grp = UI;
    hero->display = 1;
    sfSprite_setTextureRect(hero->sprite, hero->rect);
    sfRenderWindow_drawSprite(d->hub->window, hero->sprite, NULL);
    put_in_end(&d->objs, hero);
}

void create_green_banner(scene *d)
{
    sfVector2f vector[2] = {{100, 100}, {0, 0}};
    sfIntRect rect = create_rect(13, 17, 0, 0);
    game_obj *hero = create_obj(d, "green_banner", rect, vector);
    set_scale(d, hero->sprite, 10);
    hero->name = "green_banner";
    hero->grp = UI;
    hero->display = 1;
    sfSprite_setTextureRect(hero->sprite, hero->rect);
    sfRenderWindow_drawSprite(d->hub->window, hero->sprite, NULL);
    put_in_end(&d->objs, hero);
}

void create_purple_banner(scene *d)
{
    sfVector2f vector[2] = {{100, 100}, {0, 0}};
    sfIntRect rect = create_rect(13, 17, 0, 0);
    game_obj *hero = create_obj(d, "purple_banner", rect, vector);
    set_scale(d, hero->sprite, 10);
    hero->name = "purple_banner";
    hero->grp = UI;
    hero->display = 1;
    sfSprite_setTextureRect(hero->sprite, hero->rect);
    sfRenderWindow_drawSprite(d->hub->window, hero->sprite, NULL);
    put_in_end(&d->objs, hero);
}

void create_red_banner(scene *d)
{
    sfVector2f vector[2] = {{100, 100}, {0, 0}};
    sfIntRect rect = create_rect(13, 17, 0, 0);
    game_obj *hero = create_obj(d, "red_banner", rect, vector);
    set_scale(d, hero->sprite, 10);
    hero->name = "red_banner";
    hero->grp = UI;
    hero->display = 1;
    sfSprite_setTextureRect(hero->sprite, hero->rect);
    sfRenderWindow_drawSprite(d->hub->window, hero->sprite, NULL);
    put_in_end(&d->objs, hero);
}
