/*
** EPITECH PROJECT, 2021
** MyRPG - Game Obejct
** File description:
** animation for all slime
*/
#include "../../include/rpg.h"

void idle_animate_slime(scene *d, game_obj *g)
{
    slime *data = (slime *)g->data;
    if (data->state != IDLE)
        return;
    data->time = sfClock_getElapsedTime(g->clock);
    float seconds = sfTime_asSeconds(data->time);
    float old_seconds = sfTime_asSeconds(data->old_time_an);
    if (seconds - old_seconds >= 0.23) {
        sfIntRect rect = sfSprite_getTextureRect(g->sprite);
        rect.left += 32;
        rect.top = 0;
        if (rect.left > (g->texture->rect.width - (4 * 32)))
            rect = g->rect;
        sfSprite_setTextureRect(g->sprite, rect);
        data->old_time_an = sfClock_getElapsedTime(g->clock);
    }
}

void move_animate_slime(scene *d, game_obj *g)
{
    slime *data = (slime *)g->data;
    if (data->state != MOVE)
        return;
    data->time = sfClock_getElapsedTime(g->clock);
    float seconds = sfTime_asSeconds(data->time);
    float old_seconds = sfTime_asSeconds(data->old_time_an);
    if (seconds - old_seconds >= 0.23) {
        sfIntRect rect = sfSprite_getTextureRect(g->sprite);
        rect.left += 32;
        rect.top = 32;
        if (rect.left > (g->texture->rect.width - (2 * 32)))
            rect = g->rect;
        sfSprite_setTextureRect(g->sprite, rect);
        data->old_time_an = sfClock_getElapsedTime(g->clock);
    }
}

void jump_animate_slime(scene *d, game_obj *g)
{
    slime *data = (slime *)g->data;
    if (data->state != JUMP)
        return;
    data->time = sfClock_getElapsedTime(g->clock);
    float seconds = sfTime_asSeconds(data->time);
    float old_seconds = sfTime_asSeconds(data->old_time_an);
    if (seconds - old_seconds >= 0.23) {
        sfIntRect rect = sfSprite_getTextureRect(g->sprite);
        rect.left += 32;
        rect.top = 64;
        if (rect.left > g->texture->rect.width - 32)
            rect = g->rect;
        sfSprite_setTextureRect(g->sprite, rect);
        data->old_time_an = sfClock_getElapsedTime(g->clock);
    }
}

void hit_animate_slime(scene *d, game_obj *g)
{
    slime *data = (slime *)g->data;
    if (data->state != HIT)
        return;
    data->time = sfClock_getElapsedTime(g->clock);
    float seconds = sfTime_asSeconds(data->time);
    float old_seconds = sfTime_asSeconds(data->old_time_an);
    if (seconds - old_seconds >= 0.23) {
        sfIntRect rect = sfSprite_getTextureRect(g->sprite);
        rect.left += 32;
        rect.top = 96;
        if (rect.left > (g->texture->rect.width - (5 * 32)))
            rect = g->rect;
        sfSprite_setTextureRect(g->sprite, rect);
        data->old_time_an = sfClock_getElapsedTime(g->clock);
    }
}

void destroy_animate_slime(scene *d, game_obj *g)
{
    slime *data = (slime *)g->data;
    game_obj *p = get_object(d, "player");
    player *p_data = p->data;
    if (data->state != DESTROY && g->display == 0)
        return;
    data->time = sfClock_getElapsedTime(g->clock);
    float seconds = sfTime_asSeconds(data->time);
    float old_seconds = sfTime_asSeconds(data->old_time_an);
    if (seconds - old_seconds >= 0.23) {
        sfIntRect rect = sfSprite_getTextureRect(g->sprite);
        rect.left += 32;
        rect.top = 128;
        if (rect.left > (g->texture->rect.width - (3 * 32))) {
            if (g->display != 0) {
                push_items(p_data->inventory,
                    get_free_space_inv(p_data->inventory),
                    obj_dup(d, g));
                p_data->xp += 10;
            }
            g->display = 0;
        }
        sfSprite_setTextureRect(g->sprite, rect);
        data->old_time_an = sfClock_getElapsedTime(g->clock);
    }
}
