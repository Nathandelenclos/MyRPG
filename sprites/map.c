/*
** EPITECH PROJECT, 2021
** MyRPG - Object
** File description:
** map object
*/

#include "../include/rpg.h"

void evt_key_released(scene *s, game_obj *g, int code)
{
    if (code == s->hub->s->c->up)
        g->vector.y = 0;
    if (code == s->hub->s->c->down)
        g->vector.y = 0;
    if (code == s->hub->s->c->left)
        g->vector.x = 0;
    if (code == s->hub->s->c->right)
        g->vector.x = 0;
}

void event_map(game_obj *g, scene *s, sfEvent event)
{
    maps *data = g->data;
    if (sfKeyboard_isKeyPressed(s->hub->s->c->run))
        data->speed = 4;
    else
        data->speed = 2;
    if (sfKeyboard_isKeyPressed(s->hub->s->c->up))
        g->vector.y = data->speed;
    if (sfKeyboard_isKeyPressed(s->hub->s->c->down))
        g->vector.y = -(data->speed);
    if (sfKeyboard_isKeyPressed(s->hub->s->c->left))
        g->vector.x = data->speed;
    if (sfKeyboard_isKeyPressed(s->hub->s->c->right))
        g->vector.x = -(data->speed);
    switch (event.type) {
    case sfEvtKeyReleased:
        evt_key_released(s, g, event.key.code);
        break;
    }

}

void action_maps(game_obj *g, scene *s)
{
    maps *data = g->data;
    game_obj *p_g = get_object(s, "player");
    player *p = (player *)p_g->data;
    if (p->state != MOVE && p->state != MOVE_MIRROR)
        return;
    collision_map(s, g);
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
    sfVector2f pos[2] = {{-1610, -1550}, {0, 0}};
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
