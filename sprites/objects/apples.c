/*
** EPITECH PROJECT, 2021
** MYRPG - game object
** File description:
** apples game object
*/

#include "../../include/rpg.h"

game_obj *create_golden_apple(scene *d)
{
    sfVector2f vector[2] = {{0, 0}, {0, 0}};
    sfIntRect rect = create_rect(27.5, 30, 27.5, 6);
    game_obj *hero = create_obj(d, "apple", rect, vector);
    set_scale(d, hero->sprite, 2);
    hero->type = APPLE;
    hero->name = "golden_apple";
    hero->grp = OBJECT;
    hero->display = 0;
    sfSprite_setTextureRect(hero->sprite, hero->rect);
    sfRenderWindow_drawSprite(d->hub->window, hero->sprite, NULL);
    put_in_end(&d->objs, hero);
    return hero;
}

game_obj *create_apple(scene *d)
{
    sfVector2f vector[2] = {{0, 0}, {0, 0}};
    sfIntRect rect = create_rect(23, 30, 4, 6);
    game_obj *hero = create_obj(d, "apple", rect, vector);
    set_scale(d, hero->sprite, 2);
    hero->type = APPLE;
    hero->name = "apple";
    hero->grp = OBJECT;
    hero->display = 0;
    sfSprite_setTextureRect(hero->sprite, hero->rect);
    sfRenderWindow_drawSprite(d->hub->window, hero->sprite, NULL);
    put_in_end(&d->objs, hero);
    return hero;
}

