/*
** EPITECH PROJECT, 2021
** MyRPG - Sprite
** File description:
** player sprite
*/

#include "../../include/rpg.h"

void event_player(game_obj *g, scene *d, sfEvent event)
{
    player *p = (player *) g->data;
    p->state = IDLE;
    if (event.type == sfEvtKeyPressed &&
        (event.key.code <= 74 && event.key.code >= 71)) {
        p->state = MOVE;
        if (event.key.shift)
            p->animation_speed = 0.1;
        else
            p->animation_speed = 0.15;
    }
    if (event.type == sfEvtMouseButtonPressed)
        p->state = HIT;
}

void animate_player(scene *d, game_obj *g)
{
    player *data = (player *) g->data;
    switch (data->state) {
    case HIT:
        data->hit(d, g);
        break;
    case DESTROY:
        data->destroy(d, g);
        break;
    case IDLE:
        data->idle(d, g);
        break;
    case JUMP:
        data->jump(d, g);
        break;
    case MOVE:
        data->move(d, g);
        break;
    default:
        data->idle(d, g);
    }
}

player *create_player_data(scene *d)
{
    player *data = malloc(sizeof(player));
    data->old_time_an = sfTime_Zero;
    data->time = sfTime_Zero;
    data->state = IDLE;
    data->idle = idle_player_animation;
    data->move = move_player_animation;
    data->hit = hit_player_animation;
    data->animation_speed = 0.15;
    data->inv = create_inventory(d);
    put_in_end(&d->objs, data->inv);
    return data;
}

void create_player(scene *d)
{
    sfVector2f vector[2] = {
        {(d->hub->mode.width / 2) - ((48 * 6) / 2),
            (d->hub->mode.height / 2) - ((48 * 6) / 2)
        }, {0, 0}};
    sfIntRect rect = create_rect(48, 48, 0, 0);
    game_obj *hero = create_obj(d, "player", rect, vector);
    set_scale(d, hero->sprite, 6);
    hero->data = create_player_data(d);
    hero->type = PLAYER;
    hero->name = "player";
    hero->animate = animate_player;
    hero->event = event_player;
    hero->grp = ENTITY;
    hero->display = 2;
    sfSprite_setTextureRect(hero->sprite, hero->rect);
    sfRenderWindow_drawSprite(d->hub->window, hero->sprite, NULL);
    put_in_end(&d->objs, hero);
}
