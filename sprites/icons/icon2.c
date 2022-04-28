/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** icon2
*/

#include "../../include/rpg.h"

void create_icon_questionmark(scene *d)
{
    sfVector2f vector[2] = {{100, 100}, {0, 0}};
    sfIntRect rect = create_rect(6, 9, 0, 0);
    game_obj *hero = create_obj(d, "icon_questionmark", rect, vector);
    set_scale(d, hero->sprite, 10);
    hero->name = "icon_questionmark";
    hero->grp = UI;
    hero->display = 1;
    sfSprite_setTextureRect(hero->sprite, hero->rect);
    sfRenderWindow_drawSprite(d->hub->window, hero->sprite, NULL);
    put_in_end(&d->objs, hero);
}

void create_icon_ranking(scene *d)
{
    sfVector2f vector[2] = {{100, 100}, {0, 0}};
    sfIntRect rect = create_rect(11, 7, 0, 0);
    game_obj *hero = create_obj(d, "icon_ranking", rect, vector);
    set_scale(d, hero->sprite, 10);
    hero->name = "icon_ranking";
    hero->grp = UI;
    hero->display = 1;
    sfSprite_setTextureRect(hero->sprite, hero->rect);
    sfRenderWindow_drawSprite(d->hub->window, hero->sprite, NULL);
    put_in_end(&d->objs, hero);
}

void create_icon_settings(scene *d)
{
    sfVector2f vector[2] = {{100, 100}, {0, 0}};
    sfIntRect rect = create_rect(10, 10, 0, 0);
    game_obj *hero = create_obj(d, "icon_settings", rect, vector);
    set_scale(d, hero->sprite, 10);
    hero->name = "icon_settings";
    hero->grp = UI;
    hero->display = 1;
    sfSprite_setTextureRect(hero->sprite, hero->rect);
    sfRenderWindow_drawSprite(d->hub->window, hero->sprite, NULL);
    put_in_end(&d->objs, hero);
}

void create_icon_triangle(scene *d)
{
    sfVector2f vector[2] = {{100, 100}, {0, 0}};
    sfIntRect rect = create_rect(4, 7, 0, 0);
    game_obj *hero = create_obj(d, "icon_triangle", rect, vector);
    set_scale(d, hero->sprite, 10);
    hero->name = "icon_triangle";
    hero->grp = UI;
    hero->display = 1;
    sfSprite_setTextureRect(hero->sprite, hero->rect);
    sfRenderWindow_drawSprite(d->hub->window, hero->sprite, NULL);
    put_in_end(&d->objs, hero);
}
