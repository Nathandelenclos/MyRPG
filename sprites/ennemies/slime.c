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
    sfVector2f pos_map = pos_management_action_slime(g, d, map);
    if (!is_on_window(g, d))
        return;
    float distance = get_distance(g, p);
    s->time = sfClock_getElapsedTime(g->clock);
    float seconds = sfTime_asSeconds(s->time);
    float old_seconds = sfTime_asSeconds(s->old_time_hit);
    float old_seconds_disp = sfTime_asSeconds(s->old_time_disp);
    state_and_lifebar(d, g, pos_map, distance);
    action_living_slime(g, d, distance, create_vector2f(seconds, old_seconds));
    action_dead_slime(g, d, s, create_vector2f(seconds, old_seconds_disp));
}

void create_slime_(scene *d, sfVector2f pos, char *name, sfVector2f hp_hit)
{
    sfVector2f vector[2] = {pos, pos};
    sfIntRect rect = create_rect(32, 32, 0, 0);
    game_obj *hero = create_obj(d, name, rect, vector);
    set_scale(d, hero->sprite, 5);
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
