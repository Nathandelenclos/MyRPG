/*
** EPITECH PROJECT, 2021
** MyRPG - Game Object Animation
** File description:
** animation of player
*/

#include "../../include/rpg.h"

void idle_player_animation(scene *d, game_obj *g)
{
    player *data = (player *)g->data;
    if (data->state != IDLE)
        return;
    data->time = sfClock_getElapsedTime(g->clock);
    float seconds = sfTime_asSeconds(data->time);
    float old_seconds = sfTime_asSeconds(data->old_time_an);
    if (seconds - old_seconds >= 0.23) {
        sfIntRect rect = sfSprite_getTextureRect(g->sprite);
        rect.left += 48;
        rect.top = 0;
        if (rect.left > g->texture->rect.width - 48)
            rect = g->rect;
        sfSprite_setTextureRect(g->sprite, rect);
        data->old_time_an = sfClock_getElapsedTime(g->clock);
    }
}

void move_player_animation(scene *d, game_obj *g)
{
    player *data = (player *)g->data;
    if (data->state != MOVE)
        return;
    data->time = sfClock_getElapsedTime(g->clock);
    float seconds = sfTime_asSeconds(data->time);
    float old_seconds = sfTime_asSeconds(data->old_time_an);
    if (seconds - old_seconds >= data->animation_speed) {
        sfIntRect rect = sfSprite_getTextureRect(g->sprite);
        rect.left += 48;
        rect.top = 48;
        if (rect.left > g->texture->rect.width - 48)
            rect = g->rect;
        sfSprite_setTextureRect(g->sprite, rect);
        data->old_time_an = sfClock_getElapsedTime(g->clock);
    }
}

void hit_player_animation(scene *d, game_obj *g)
{
    player *data = (player *)g->data;
    if (data->state != HIT)
        return;
    data->time = sfClock_getElapsedTime(g->clock);
    float seconds = sfTime_asSeconds(data->time);
    float old_seconds = sfTime_asSeconds(data->old_time_an);
    if (seconds - old_seconds >= 0.23) {
        sfIntRect rect = sfSprite_getTextureRect(g->sprite);
        rect.left += 48;
        rect.top = 96;
        if (rect.left > g->texture->rect.width - (3 * 48))
            rect = g->rect;
        sfSprite_setTextureRect(g->sprite, rect);
        data->old_time_an = sfClock_getElapsedTime(g->clock);
    }
}
