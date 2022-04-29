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
    maps *data = g->data;
    switch (event.type) {
    case sfEvtKeyPressed:
        if (event.key.shift)
            data->speed = 4;
        else
            data->speed = 2;
        if (event.key.code == 73)
            g->vector.y = data->speed;
        if (event.key.code == 74)
            g->vector.y = -(data->speed);
        if (event.key.code == 71)
            g->vector.x = data->speed;
        if (event.key.code == 72)
            g->vector.x = -(data->speed);
        break;
    case sfEvtKeyReleased:
        evt_key_released(g, event.key.code);
        break;
    }
}

void action_maps(game_obj *g, scene *s)
{
    collision_map(s, g);
    maps *data = g->data;
    data->time = sfClock_getElapsedTime(g->clock);
    float seconds = sfTime_asSeconds(data->time);
    float old_seconds = sfTime_asSeconds(data->old_time_an);
    if (seconds - old_seconds > 0.001) {
        sfSprite_move(g->sprite, g->vector);
        data->old_time_an = sfClock_getElapsedTime(g->clock);
    }
}

maps *create_maps_data(void)
{
    maps *data = malloc(sizeof(maps));
    data->time = sfTime_Zero;
    data->old_time_an = sfTime_Zero;
    data->speed = 2;
    return data;
}

int create_sprite_map(scene *d)
{
    sfVector2f pos[2] = {{-1000, -1000}, {0, 0}};
    game_obj *map =
        create_obj(d, "maps", create_rect(787, 775, 0, 0), pos);
    set_scale(d, map->sprite, 9);
    map->data = create_maps_data();
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
