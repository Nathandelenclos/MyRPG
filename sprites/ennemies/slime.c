/*
** EPITECH PROJECT, 2021
** MyRPG - Game Object
** File description:
** Game object slime
*/

#include "../../include/rpg.h"

void animate_slime(scene *d, game_obj *g)
{
    slime *data = (slime *) g->data;
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

slime *create_slime_data(sfVector2f hp_hit)
{
    slime *data = malloc(sizeof(slime));
    data->old_time_an = sfTime_Zero;
    data->old_time_hit = sfTime_Zero;
    data->old_time_disp = sfTime_Zero;
    data->hp = hp_hit.x;
    data->hp_max = hp_hit.x;
    data->attack = hp_hit.y;
    data->lb = create_life_bar(100, 5, sfGreen, sfBlack);
    data->state = IDLE;
    data->time = sfTime_Zero;
    data->destroy = destroy_animate_slime;
    data->hit = hit_animate_slime;
    data->jump = jump_animate_slime;
    data->idle = idle_animate_slime;
    data->move = move_animate_slime;
    return data;
}

void action_slime(game_obj *g, scene *d)
{
    game_obj *map = get_object(d, "maps");
    slime *s = (slime *) g->data;
    game_obj *p = get_object(d, "player");
    sfVector2f pos_map = sfSprite_getPosition(map->sprite);
    pos_map.x += g->vector.x * 9.0;
    pos_map.y += g->vector.y * 9.0;
    sfSprite_setPosition(g->sprite, pos_map);
    pos_map.y += 20;
    pos_map.x += 35;
    float distance = get_distance(g, p);
    s->time = sfClock_getElapsedTime(g->clock);
    float seconds = sfTime_asSeconds(s->time);
    float old_seconds = sfTime_asSeconds(s->old_time_hit);
    float old_seconds_disp = sfTime_asSeconds(s->old_time_disp);
    if (distance <= 150.0)
        s->state = HIT;
    else
        s->state = IDLE;
    if (g->display)
        print_life_bar(d, s->lb, s->hp * 100 / s->hp_max, pos_map);
    if (g->display && distance <= 150.0 && seconds - old_seconds >= 0.7) {
        ((player *) p->data)->hp -= s->attack;
        s->old_time_hit = sfClock_getElapsedTime(g->clock);
        if (((player *) p->data)->hp <= 0) {
            ((player *) p->data)->hp = 100;
            switch_scene(d, GAME_OVER);
        }
    }
    if (s->hp <= 0) {
        s->state = DESTROY;
        if (seconds - old_seconds_disp >= 120) {
            s->old_time_disp = sfClock_getElapsedTime(g->clock);
            s->hp = s->hp_max;
            s->state = IDLE;
            g->display = 1;
        }
    } else
        s->old_time_disp = sfClock_getElapsedTime(g->clock);
}

void create_slime_(scene *d, sfVector2f pos, char *name, sfVector2f hp_hit)
{
    sfVector2f vector[2] = {pos, pos};
    sfIntRect rect = create_rect(32, 32, 0, 0);
    game_obj *hero = create_obj(d, name, rect, vector);
    set_scale(d, hero->sprite, 5);;
    hero->data = create_slime_data(hp_hit);
    hero->type = SLIME;
    hero->name = my_strdup(name);
    hero->animate = animate_slime;
    hero->grp = ENEMY;
    hero->action = action_slime;
    hero->display = 1;
    game_obj *map = get_object(d, "maps");
    sfVector2f pos_map = sfSprite_getPosition(map->sprite);
    pos_map.x += pos.x * 9;
    pos_map.y += pos.y * 9;
    sfSprite_setPosition(hero->sprite, pos_map);
    sfSprite_setTextureRect(hero->sprite, hero->rect);
    sfRenderWindow_drawSprite(d->hub->window, hero->sprite, NULL);
    put_in_end(&d->objs, hero);
}

void create_slime(scene *d, sfVector2f pos, slime_type type, sfVector2f hp_hit)
{
    switch (type) {
    case BLACK:
        create_slime_(d, pos, "enemy_slime", hp_hit);
        break;
    case BLUE:
        create_slime_(d, pos, "slime", hp_hit);
        break;
    case GREEN:
        create_slime_(d, pos, "green_slime", hp_hit);
        break;
    case PINK:
        create_slime_(d, pos, "pink_slime", hp_hit);
        break;
    case YELLOW:
        create_slime_(d, pos, "yellow_slime", hp_hit);
        break;
    }
}
