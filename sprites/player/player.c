/*
** EPITECH PROJECT, 2021
** MyRPG - Sprite
** File description:
** player sprite
*/

#include "../../include/rpg.h"

void regeneration_player(game_obj *g, scene *d)
{
    game_obj *map = get_object(d, "maps");
    player *p = (player *) g->data;
    sfVector2f pos_mapbg = sfSprite_getPosition(map->sprite);
    sfVector2f pos_maphd = pos_mapbg;
    sfVector2f pos_player = sfSprite_getPosition(g->sprite);
    pos_mapbg.x += 276 * 9.0;
    pos_mapbg.y += 303 * 9.0;
    pos_maphd.x += 341 * 9.0;
    pos_maphd.y += 225 * 9.0;
    p->time = sfClock_getElapsedTime(g->clock);
    float seconds = sfTime_asSeconds(p->time);
    float old_seconds = sfTime_asSeconds(p->old_time_hp);
    if (pos_player.x + 144 >= pos_mapbg.x && pos_player.x + 144 <= pos_maphd.x
    && pos_player.y + 144 <= pos_mapbg.y && pos_player.y + 144 >= pos_maphd.y
    && g->display) {
        if (seconds - old_seconds >= 0.2 && p->hp > 0 && p->hp < 100) {
            p->hp += 1;
            p->old_time_hp = sfClock_getElapsedTime(g->clock);
        }
        if (p->hp >= 100)
            get_env(d, REGEN)->active = sfFalse;
        else
            get_env(d, REGEN)->active = sfTrue;
    } else
        get_env(d, REGEN)->active = sfFalse;
    if (p->hp > 0 && p->hp <= 15)
        get_env(d, LOW_LIFE)->active = sfTrue;
    else
        get_env(d, LOW_LIFE)->active = sfFalse;
    p->lb->main_color = sfColor_fromRGB(255 - (255*p->hp/100), (float )(p->hp) * 2.55, 0);
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
    if (sfKeyboard_isKeyPressed(d->hub->s->c->up) ||
    sfKeyboard_isKeyPressed(d->hub->s->c->down) ||
    sfKeyboard_isKeyPressed(d->hub->s->c->left) ||
    sfKeyboard_isKeyPressed(d->hub->s->c->right)) {
        p->state = MOVE;
        if (event.key.shift)
            p->animation_speed = 0.1;
        else
            p->animation_speed = 0.15;
    }
    if (sfKeyboard_isKeyPressed(d->hub->s->c->attack)) {
        rect.left = 0;
        p->state = HIT;
        float distance = get_distance(g, get_closer_object(d, g, ENEMY));
        if (distance <= 175.0 && distance >= 0.0) {
            game_obj *s = get_closer_object(d, g, ENEMY);
            if (s != NULL)
                ((slime *)s->data)->hp -= 3;
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
    data->old_time_hit = sfTime_Zero;
    data->old_time_hp = sfTime_Zero;
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
    hero->action = regeneration_player;
    hero->display = 2;
    sfSprite_setTextureRect(hero->sprite, hero->rect);
    sfRenderWindow_drawSprite(d->hub->window, hero->sprite, NULL);
    put_in_end(&d->objs, hero);
    put_in_list(&((player *)(hero->data))->particles, create_particle(d));
}
