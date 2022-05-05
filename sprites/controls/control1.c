/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** control1
*/

#include "../../include/rpg.h"

void create_arrow_down(scene *d)
{
    sfVector2f vector[2] = {{100, 100}, {0, 0}};
    sfIntRect rect = create_rect(12, 14, 0, 0);
    game_obj *hero = create_obj(d, "arrow_down", rect, vector);
    set_scale(d, hero->sprite, 10);
    hero->name = "arrow_down";
    hero->grp = UI;
    hero->display = 1;
    sfSprite_setTextureRect(hero->sprite, hero->rect);
    sfRenderWindow_drawSprite(d->hub->window, hero->sprite, NULL);
    put_in_end(&d->objs, hero);
}

void create_arrow_up(scene *d)
{
    sfVector2f vector[2] = {{100, 100}, {0, 0}};
    sfIntRect rect = create_rect(12, 14, 0, 0);
    game_obj *hero = create_obj(d, "arrow_up", rect, vector);
    set_scale(d, hero->sprite, 10);
    hero->name = "arrow_up";
    hero->grp = UI;
    hero->display = 1;
    sfSprite_setTextureRect(hero->sprite, hero->rect);
    sfRenderWindow_drawSprite(d->hub->window, hero->sprite, NULL);
    put_in_end(&d->objs, hero);
}

void create_arrow_left(scene *d, sfVector2f pos)
{
    sfVector2f vector[2] = {{pos.x, pos.y}, {0, 0}};
    sfIntRect rect = create_rect(13, 13, 0, 0);
    game_obj *hero = create_obj(d, "arrow_left", rect, vector);
    set_scale(d, hero->sprite, 10);
    hero->name = "arrow_left";
    hero->grp = UI;
    hero->display = 1;
    sfSprite_setTextureRect(hero->sprite, hero->rect);
    sfRenderWindow_drawSprite(d->hub->window, hero->sprite, NULL);
    put_in_end(&d->objs, hero);
}

void create_arrow_right(scene *d)
{
    sfVector2f vector[2] = {{100, 100}, {0, 0}};
    sfIntRect rect = create_rect(13, 13, 0, 0);
    game_obj *hero = create_obj(d, "arrow_right", rect, vector);
    set_scale(d, hero->sprite, 10);
    hero->name = "arrow_right";
    hero->grp = UI;
    hero->display = 1;
    sfSprite_setTextureRect(hero->sprite, hero->rect);
    sfRenderWindow_drawSprite(d->hub->window, hero->sprite, NULL);
    put_in_end(&d->objs, hero);
}
