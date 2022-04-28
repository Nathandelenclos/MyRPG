/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** chests
*/

#include "../include/rpg.h"

void close_animate_chest(scene *d, game_obj *g)
{
    chest *data = (chest *)g->data;
    if (data->state != CLOSE)
        return;
    data->time = sfClock_getElapsedTime(g->clock);
    float seconds = sfTime_asSeconds(data->time);
    float old_seconds = sfTime_asSeconds(data->old_time_an);
    if (seconds - old_seconds >= 0.23) {
        sfIntRect rect = sfSprite_getTextureRect(g->sprite);
        rect.left -= 16;
        rect.top = 0;
        if (rect.left < 16) {
            data->state = IDLE_C;
        }
        sfSprite_setTextureRect(g->sprite, rect);
        data->old_time_an = sfClock_getElapsedTime(g->clock);
    }
}

void open_animate_chest(scene *d, game_obj *g)
{
    chest *data = (chest *)g->data;
    if (data->state != OPEN)
        return;
    data->time = sfClock_getElapsedTime(g->clock);
    float seconds = sfTime_asSeconds(data->time);
    float old_seconds = sfTime_asSeconds(data->old_time_an);
    if (seconds - old_seconds >= 0.23) {
        sfIntRect rect = sfSprite_getTextureRect(g->sprite);
        rect.left += 16;
        rect.top = 0;
        if (rect.left > 2 * 16) {
            data->state = IDLE_C;
        }
        sfSprite_setTextureRect(g->sprite, rect);
        data->old_time_an = sfClock_getElapsedTime(g->clock);
    }
}

chest *create_chest_data(void)
{
    chest *data = malloc(sizeof(chest));
    data->old_time_an = sfTime_Zero;
    data->time = sfTime_Zero;
    data->open = open_animate_chest;
    data->close = close_animate_chest;
    return data;
}

void create_basic_chest(scene *d)
{
    sfVector2f vector[2] = {{100, 100}, {0, 0}};
    sfIntRect rect = create_rect(16, 16, 0, 0);
    game_obj *hero = create_obj(d, "basic_chest", rect, vector);
    set_scale(d, hero->sprite, 3);
    hero->data = create_chest_data();
    hero->type = CHEST;
    hero->name = "basic_chest";
    hero->grp = OBJECT;
    hero->display = 1;
    sfSprite_setTextureRect(hero->sprite, hero->rect);
    sfRenderWindow_drawSprite(d->hub->window, hero->sprite, NULL);
    put_in_end(&d->objs, hero);
}

void create_golden_chest(scene *d)
{
    sfVector2f vector[2] = {{100, 100}, {0, 0}};
    sfIntRect rect = create_rect(16, 16, 0, 0);
    game_obj *hero = create_obj(d, "golden_chest", rect, vector);
    set_scale(d, hero->sprite, 3);
    hero->data = create_chest_data();
    hero->type = CHEST;
    hero->name = "golden_chest";
    hero->grp = OBJECT;
    hero->display = 1;
    sfSprite_setTextureRect(hero->sprite, hero->rect);
    sfRenderWindow_drawSprite(d->hub->window, hero->sprite, NULL);
    put_in_end(&d->objs, hero);
}
