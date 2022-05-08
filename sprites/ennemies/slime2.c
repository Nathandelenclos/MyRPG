/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** slime2
*/

#include "../../include/rpg.h"

sfVector2f pos_management_action_slime(game_obj *g, scene *d, game_obj *map)
{
    sfVector2f pos_map = sfSprite_getPosition(map->sprite);
    sfTime move = sfClock_getElapsedTime(g->clock);
    int sec = sfTime_asMilliseconds(move) / 1000;
    sec %= 2;
    if (is_on_window(g, d)) {
        if (sec == 1) {
            g->vector.x += (g->position.x * (float) d->hub->delta_time) / 8;
            g->vector.y += (g->position.y * (float) d->hub->delta_time) / 8;
        } else if (sec == 0) {
            g->vector.x -= (g->position.x * (float) d->hub->delta_time) / 8;
            g->vector.y -= (g->position.y * (float) d->hub->delta_time) / 8;
        }
    }
    pos_map.x += g->vector.x * 9.0;
    pos_map.y += g->vector.y * 9.0;
    sfSprite_setPosition(g->sprite, pos_map);
    pos_map.y += 20;
    pos_map.x += 35;
    return (pos_map);
}

void state_and_lifebar(scene *d, game_obj *g, sfVector2f pos_map,
float distance)
{
    slime *s = (slime *) g->data;
    if (distance <= 150.0)
        s->state = HIT;
    else
        s->state = IDLE;
    if (g->display)
        print_life_bar(d, s->lb, s->hp * 100 / s->hp_max, pos_map);
}

void action_living_slime(game_obj *g, scene *d, float distance, sfVector2f sec)
{
    slime *s = (slime *) g->data;
    game_obj *p = get_object(d, "player");

    if (g->display && distance <= 150.0 && sec.x - sec.y >= 0.7) {
        ((player *) p->data)->hp -= s->attack;
        s->old_time_hit = sfClock_getElapsedTime(g->clock);
        if (((player *) p->data)->hp <= 0) {
            ((player *) p->data)->hp = 100;
            ((player *) p->data)->damage = 3;
            ((player *) p->data)->total_hp = 100;
            ((player *) p->data)->xp = 0;
            switch_scene(d, GAME_OVER);
        }
    }
}

void action_dead_slime(game_obj *g, scene *d, slime *s, sfVector2f sec)
{
    if (s->hp <= 0) {
        s->state = DESTROY;
        if (sec.x - sec.y >= 15) {
            s->old_time_disp = sfClock_getElapsedTime(g->clock);
            s->hp = s->hp_max;
            s->state = IDLE;
            g->display = 1;
        }
    } else
        s->old_time_disp = sfClock_getElapsedTime(g->clock);
}
