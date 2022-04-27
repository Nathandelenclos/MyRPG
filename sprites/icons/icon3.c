/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** icon3
*/

#include "../../include/rpg.h"

void create_icon_trophy(scene *d)
{
    sfVector2f vector[2] = {{100, 100}, {0, 0}};
    sfIntRect rect = create_rect(8, 9, 0, 0);
    game_obj *hero = create_obj(d, "icon_trophy", rect, vector);
    set_scale(d, hero->sprite, 10);
    hero->name = "icon_trophy";
    hero->grp = UI;
    hero->display = 1;
    sfSprite_setTextureRect(hero->sprite, hero->rect);
    sfRenderWindow_drawSprite(d->hub->window, hero->sprite, NULL);
    put_in_end(&d->objs, hero);
}

void create_icon_twitter(scene *d)
{
    sfVector2f vector[2] = {{100, 100}, {0, 0}};
    sfIntRect rect = create_rect(10, 8, 0, 0);
    game_obj *hero = create_obj(d, "icon_twitter", rect, vector);
    set_scale(d, hero->sprite, 10);
    hero->name = "icon_twitter";
    hero->grp = UI;
    hero->display = 1;
    sfSprite_setTextureRect(hero->sprite, hero->rect);
    sfRenderWindow_drawSprite(d->hub->window, hero->sprite, NULL);
    put_in_end(&d->objs, hero);
}

void create_icon_watchad(scene *d)
{
    sfVector2f vector[2] = {{100, 100}, {0, 0}};
    sfIntRect rect = create_rect(14, 8, 0, 0);
    game_obj *hero = create_obj(d, "icon_watchad", rect, vector);
    set_scale(d, hero->sprite, 10);
    hero->name = "icon_watchad";
    hero->grp = UI;
    hero->display = 1;
    sfSprite_setTextureRect(hero->sprite, hero->rect);
    sfRenderWindow_drawSprite(d->hub->window, hero->sprite, NULL);
    put_in_end(&d->objs, hero);
}

void create_icon_youtube(scene *d)
{
    sfVector2f vector[2] = {{100, 100}, {0, 0}};
    sfIntRect rect = create_rect(8, 7, 0, 0);
    game_obj *hero = create_obj(d, "icon_youtube", rect, vector);
    set_scale(d, hero->sprite, 10);
    hero->name = "icon_youtube";
    hero->grp = UI;
    hero->display = 1;
    sfSprite_setTextureRect(hero->sprite, hero->rect);
    sfRenderWindow_drawSprite(d->hub->window, hero->sprite, NULL);
    put_in_end(&d->objs, hero);
}
