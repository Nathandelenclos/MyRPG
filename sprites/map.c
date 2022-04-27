/*
** EPITECH PROJECT, 2021
** MyRPG - Object
** File description:
** map object
*/

#include "../include/rpg.h"

void evt_key_released(game_obj *g, int code)
{
    if (code == 73)
        g->vector.y = 0;
    if (code == 74)
        g->vector.y = 0;
    if (code == 71)
        g->vector.x = 0;
    if (code == 72)
        g->vector.x = 0;
}

void event_map(game_obj *g, scene *s, sfEvent event)
{
    switch (event.type) {
    case sfEvtKeyPressed:
        if (event.key.code == 73)
            g->vector.y = 2;
        if (event.key.code == 74)
            g->vector.y = -2;
        if (event.key.code == 71)
            g->vector.x = 2;
        if (event.key.code == 72)
            g->vector.x = -2;
        break;
    case sfEvtKeyReleased:
        evt_key_released(g, event.key.code);
        break;
    }
}

void action_maps(game_obj *g, scene *s)
{
    maps *data = g->data;
    data->time = sfClock_getElapsedTime(g->clock);
    float seconds = sfTime_asSeconds(data->time);
    float old_seconds = sfTime_asSeconds(data->old_time_an);
    if (seconds - old_seconds > data->speed) {
        sfSprite_move(g->sprite, g->vector);
        data->old_time_an = sfClock_getElapsedTime(g->clock);
    }
}

int create_sprite_map(scene *d)
{
    sfVector2f pos[2] = {{0, 0}, {0, 0}};
    game_obj *map =
        create_obj(d, "maps", create_rect(787, 775, 0, 0), pos);
    set_scale(d, map->sprite, 6);
    map->data = malloc(sizeof(maps));
    ((maps *) (map->data))->time = sfTime_Zero;
    ((maps *) (map->data))->old_time_an = sfTime_Zero;
    ((maps *) (map->data))->speed = 0.001;
    map->name = "maps";
    map->action = action_maps;
    map->grp = MAP;
    map->display = 1;
    map->event = event_map;
    sfSprite_setTextureRect(map->sprite, map->rect);
    sfRenderWindow_drawSprite(d->hub->window, map->sprite, NULL);
    put_in_end(&d->objs, map);
    return 0;
}
