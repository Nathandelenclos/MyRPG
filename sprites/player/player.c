/*
** EPITECH PROJECT, 2021
** MyRPG - Sprite
** File description:
** player sprite
*/

#include "../../include/rpg.h"

float range_player(game_obj *g, scene *d)
{
    game_obj *map = get_object(d, "maps");
    player *p = (player *)g->data;
    sfVector2f pos_map = sfSprite_getPosition(map->sprite);
    game_obj *s = get_object(d, "enemy_slime");
    pos_map.x += s->vector.x * 9.0;
    pos_map.y += s->vector.y * 9.0;
    if (s == NULL)
        return (-1);
    float rx = (sfSprite_getPosition(g->sprite).x + ((g->rect.width / 2) *
        sfSprite_getScale(g->sprite).x)) - (pos_map.x + ((s->rect.width / 2) *
        sfSprite_getScale(s->sprite).x));
    float ry = (sfSprite_getPosition(g->sprite).y + ((g->rect.height / 2) *
        sfSprite_getScale(g->sprite).y)) - (pos_map.y + ((s->rect.height / 2) *
        sfSprite_getScale(s->sprite).y));
    float range = (float)sqrt(rx * rx + ry * ry);
    return (range);
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
        printf("%f\n", range_player(g, d));
        if (range_player(g, d) <= 175.0 && range_player(g, d) >= 0.0) {
            game_obj *s = get_object(d, "enemy_slime");
            if (s != NULL) {
                ((slime *)s->data)->hp -= 5;
                printf("%i\n", ((slime *)s->data)->hp);
            }
        }
        sfSprite_setTextureRect(g->sprite, rect);
    }
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
    put_in_end(&d->objs, data->inv);
    return data;
}

void create_player(scene *d)
{
    sfVector2f vector[2] = {
        {
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
}
