/*
** EPITECH PROJECT, 2021
** MyRPG - chests animation
** File description:
** chest animation
*/
#include "../../include/rpg.h"

sfVector2f *init_inventory_pos_places(void)
{
    sfVector2f *pos = malloc(sizeof(sfVector2f) * 36);
    for (int i = 0; i < 36; i++) {
        if (i >= 0 && i < 9) {
            pos[i].x = 275 + i * 157;
            pos[i].y = 356 - 140;
        }
        if (i >= 9 && i < 18) {
            pos[i].x = 275 + (i - 9) * 157;
            pos[i].y = 356 + 157 - 140;
        }
        if (i >= 18 && i < 27) {
            pos[i].x = 275 + (i - 18) * 157;
            pos[i].y = 356 + 157 * 2 - 140;
        }
        if (i >= 27 && i < 36) {
            pos[i].x = 275 + (i - 27) * 157;
            pos[i].y = 869 - 140;
        }
    }
    return (pos);
}

inventory *create_inventory_data(scene *d, int size)
{
    inventory *data = malloc(sizeof(inventory));
    data->pos = init_inventory_pos_places();
    data->state = FIRST_CLICK;
    data->size = size;
    data->slot = malloc(sizeof(slot_inv *) * ((size) + 1));
    for (int i = 0; i < (size) + 1; ++i)
        data->slot[i] = NULL;
    return data;
}

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

chest *create_chest_data(scene *d)
{
    chest *data = malloc(sizeof(chest));
    data->old_time_an = sfTime_Zero;
    data->time = sfTime_Zero;
    data->open = open_animate_chest;
    data->close = close_animate_chest;
    data->inventory = create_inventory_data(d, 27);
    return data;
}
