/*
** EPITECH PROJECT, 2021
** MyRPG - Sprite
** File description:
** player sprite
*/

#include "../../include/rpg.h"

void regeneration_player(game_obj *g, scene *d)
{
    // game_obj *map = get_object(d, "maps");
    // slime *s = (slime *) g->data;
    game_obj *p = get_object(d, "player");
    sfVector2f pos_map = sfSprite_getPosition(map->sprite);
    pos_map.x += g->vector.x * 9.0;
    pos_map.y += g->vector.y * 9.0;
    sfSprite_setPosition(g->sprite, pos_map);
    pos_map.y -= 10;
    pos_map.x += 30;
    float distance = get_distance(g, p);
    s->time = sfClock_getElapsedTime(g->clock);
    float seconds = sfTime_asSeconds(s->time);
    float old_seconds = sfTime_asSeconds(s->old_time_hit);
    if (distance <= 150.0)
        s->state = HIT;
    else
        s->state = IDLE;
    if (g->display)
        print_life_bar(d, s->lb, s->hp * 10, pos_map);
    if (g->display && distance <= 150.0 && seconds - old_seconds >= 0.5) {
        ((player *) p->data)->hp -= 2;
        s->old_time_hit = sfClock_getElapsedTime(g->clock);
        if (((player *) p->data)->hp <= 0) {
            ((player *) p->data)->hp = 100;
            switch_scene(d, START);
        }
    }
    if (s->hp <= 0)
        s->state = DESTROY;
    

    game_obj *map = get_object(d, "maps");
    player *s = (player *) g->data;
    sfVector2f pos_map = sfSprite_getPosition(map->sprite);
    pos_map.x += g->vector.x * 9.0;
    pos_map.y += g->vector.y * 9.0;
}

void print_life_bar_player(scene *d, player *p)
{
    life_percent(p->lb, p->hp);
    sfVector2f v = sfSprite_getPosition(p->inv->sprite);
    v.y -= 50;
    sfSprite_setPosition(p->lb->sprite, v);
    sfRenderWindow_drawSprite(d->hub->window, p->lb->sprite, NULL);
}

void event_player(game_obj *g, scene *d, sfEvent event)
{
    player *p = (player *) g->data;
    sfIntRect rect = sfSprite_getTextureRect(g->sprite);
    if (p->state == HIT)
        return;
    p->state = IDLE;
    if (sfKeyboard_isKeyPressed(71) || sfKeyboard_isKeyPressed(72) ||
        sfKeyboard_isKeyPressed(73) || sfKeyboard_isKeyPressed(74)) {
        p->state = MOVE;
        if (event.key.shift)
            p->animation_speed = 0.1;
        else
            p->animation_speed = 0.15;
    }
    if (event.type == sfEvtMouseButtonPressed) {
        rect.left = 0;
        p->state = HIT;
        float distance = get_distance(g, get_closer_object(d, g, ENEMY));
        if (distance <= 175.0 && distance >= 0.0) {
            game_obj *s = get_object(d, "enemy_slime");
            if (s != NULL)
                ((slime *)s->data)->hp -= 5;
        }
        sfSprite_setTextureRect(g->sprite, rect);
    }
}

void animate_player(scene *d, game_obj *g)
{
    player *data = (player *) g->data;
    print_life_bar_player(d, data);
    switch (data->state) {
    case HIT:
        data->hit(d, g);
        break;
    case DESTROY:
        data->destroy(d, g);
        break;
    case IDLE:
        g->rect.left = 0;
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
    data->hp = 100;
    data->idle = idle_player_animation;
    data->move = move_player_animation;
    data->hit = hit_player_animation;
    data->animation_speed = 0.15;
    data->inv = create_inventory(d);
    data->lb = create_life_bar(300, 20, sfGreen, sfBlack);
    put_in_end(&d->objs, data->inv);
    data->particles = NULL;
    return data;
}

void create_player(scene *d)
{
    sfVector2f vector[2] = {{
            (d->hub->mode.width / 2) - ((48 * 6) / 2),
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
    put_in_list(&((player *)(hero->data))->particles, create_particle(d));
}
