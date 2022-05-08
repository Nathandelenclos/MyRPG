/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** case_animation
*/

#include "../../include/rpg.h"

void animate_player_mirrored2(scene *d, game_obj *g, player *data)
{
    switch (data->state) {
    case JUMP_MIRROR:
        data->jump(d, g);
        break;
    case MOVE_MIRROR:
        data->move = move_player_animation_mirror;
        data->move(d, g);
        break;
    }
}

void animate_player_mirrored(scene *d, game_obj *g, player *data)
{
    switch (data->state) {
    case HIT_MIRROR:
        data->hit = hit_player_animation_mirror;
        data->hit(d, g);
        break;
    case DESTROY_MIRROR:
        data->destroy(d, g);
        break;
    case IDLE_MIRROR:
        data->idle = idle_player_animation_mirror;
        g->rect.left = 0;
        data->idle(d, g);
        break;
    default:
        animate_player_mirrored2(d, g, data);
    }
}

void animate_player_unmirrored2(scene *d, game_obj *g, player *data)
{
    switch (data->state) {
    case JUMP:
        data->jump(d, g);
        break;
    case MOVE:
        data->move = move_player_animation;
        data->move(d, g);
        break;
    default:
        animate_player_mirrored(d, g, data);
    }
}

void animate_player_unmirrored(scene *d, game_obj *g, player *data)
{
    switch (data->state) {
    case HIT:
        data->hit = hit_player_animation;
        data->hit(d, g);
        break;
    case DESTROY:
        data->destroy(d, g);
        break;
    case IDLE:
        data->idle = idle_player_animation;
        g->rect.left = 0;
        data->idle(d, g);
        break;
    default:
        animate_player_unmirrored2(d, g, data);
    }
}

void animate_player(scene *d, game_obj *g)
{
    player *data = (player *) g->data;
    print_life_bar_player(d, data);
    animate_player_unmirrored(d, g, data);
}
