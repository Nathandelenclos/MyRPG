/*
** EPITECH PROJECT, 2021
** MyRPG - sprite
** File description:
** dwarf sprite
*/

#include "../../include/rpg.h"

void animated_dwarf(scene *d, game_obj *obj)
{
    obj->time = sfClock_getElapsedTime(obj->clock);
    float seconds = sfTime_asSeconds(obj->time);
    float seconds_old = sfTime_asSeconds(obj->old_time_an);
    if (seconds - seconds_old >= 0.12) {
        sfIntRect rect = sfSprite_getTextureRect(obj->sprite);
        rect.left += 64;
        if (rect.left >= obj->texture->rect.width)
            rect = obj->rect;
        sfSprite_setTextureRect(obj->sprite, rect);
        obj->old_time_an = sfClock_getElapsedTime(obj->clock);
    }
}

void action_dwarf(game_obj *obj, scene *d)
{
    dwarf *dw = (dwarf *)obj->data;
    dw->time
    obj->time = sfClock_getElapsedTime(obj->clock);
    obj->seconds = sfTime_asSeconds(obj->time);
    float seconds = sfTime_asSeconds(obj->old_time_ac);
    if (obj->seconds - seconds >= obj->speed) {
        sfSprite_move(obj->sprite, obj->vector);
        obj->old_time_ac = sfClock_getElapsedTime(obj->clock);
    }
}

void create_dwarf(scene *d, float speed, int life)
{
    sfVector2f vector[2] = {{-40, 5}, {2, 1.2}};
    sfIntRect rect = create_rect(40, 30, 20, 7);
    game_obj *hero = create_obj(d, "dwarf", rect, vector);
    set_scale(d, hero->sprite, 3);
    dwarf *dw = mall;
    hero->data = dw;
    hero->type = dwarf;
    hero->name = "dwarf";
    hero->grp = ENTITY;
    hero->display = 3;
    hero->animate = animated_dwarf;
    hero->action = action_dwarf;
    sfSprite_setTextureRect(hero->sprite, hero->rect);
    sfRenderWindow_drawSprite(d->hub->window, hero->sprite, NULL);
    put_in_end(&d->objs, hero);
}
