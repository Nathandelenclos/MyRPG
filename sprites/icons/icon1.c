/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** icon1
*/

#include "../../include/rpg.h"

void create_icon_exclamationmark(scene *d)
{
    sfVector2f vector[2] = {{100, 100}, {0, 0}};
    sfIntRect rect = create_rect(3, 9, 0, 0);
    game_obj *hero = create_obj(d, "icon_exclamationmark", rect, vector);
    set_scale(d, hero->sprite, 10);
    hero->name = "icon_exclamationmark";
    hero->grp = UI;
    hero->display = 1;
    sfSprite_setTextureRect(hero->sprite, hero->rect);
    sfRenderWindow_drawSprite(d->hub->window, hero->sprite, NULL);
    put_in_end(&d->objs, hero);
}

void create_icon_facebook(scene *d)
{
    sfVector2f vector[2] = {{100, 100}, {0, 0}};
    sfIntRect rect = create_rect(6, 9, 0, 0);
    game_obj *hero = create_obj(d, "icon_facebook", rect, vector);
    set_scale(d, hero->sprite, 10);
    hero->name = "icon_facebook";
    hero->grp = UI;
    hero->display = 1;
    sfSprite_setTextureRect(hero->sprite, hero->rect);
    sfRenderWindow_drawSprite(d->hub->window, hero->sprite, NULL);
    put_in_end(&d->objs, hero);
}

void create_icon_house(scene *d)
{
    sfVector2f vector[2] = {{100, 100}, {0, 0}};
    sfIntRect rect = create_rect(11, 7, 0, 0);
    game_obj *hero = create_obj(d, "icon_house", rect, vector);
    set_scale(d, hero->sprite, 10);
    hero->name = "icon_house";
    hero->grp = UI;
    hero->display = 1;
    sfSprite_setTextureRect(hero->sprite, hero->rect);
    sfRenderWindow_drawSprite(d->hub->window, hero->sprite, NULL);
    put_in_end(&d->objs, hero);
}

void create_icon_human(scene *d)
{
    sfVector2f vector[2] = {{100, 100}, {0, 0}};
    sfIntRect rect = create_rect(7, 10, 0, 0);
    game_obj *hero = create_obj(d, "icon_human", rect, vector);
    set_scale(d, hero->sprite, 10);
    hero->name = "icon_human";
    hero->grp = UI;
    hero->display = 1;
    sfSprite_setTextureRect(hero->sprite, hero->rect);
    sfRenderWindow_drawSprite(d->hub->window, hero->sprite, NULL);
    put_in_end(&d->objs, hero);
}
