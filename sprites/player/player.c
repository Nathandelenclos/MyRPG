/*
** EPITECH PROJECT, 2021
** MyRPG - Sprite
** File description:
** player sprite
*/

#include "../../include/rpg.h"

void print_life_bar_player(scene *d, player *p)
{
    life_percent(p->lb, p->hp);
    sfVector2f v = sfSprite_getPosition(p->inv->sprite);
    v.y -= 50;
    sfSprite_setPosition(p->lb->sprite, v);
    sfRenderWindow_drawSprite(d->hub->window, p->lb->sprite, NULL);
}

// g->texture = get_texture(d, "player_mirror");
// if (g->texture != NULL) {
//     sfSprite_setTexture(g->sprite, g->texture, sfTrue);
// }

int is_mirror(player *p)
{
    if (p->state == IDLE_MIRROR || p->state == HIT_MIRROR
    || p->state == MOVE_MIRROR) {
        return 1;
    }
    return 0;
}
//sfKeyboard_isKeyPressed(71) || sfKeyboard_isKeyPressed(72) ||
void event_player(game_obj *g, scene *d, sfEvent event)
{
    player *p = (player *) g->data;
    sfIntRect rect = sfSprite_getTextureRect(g->sprite);
    if (p->state == HIT || p->state == HIT_MIRROR)
        return;
    if (p->state == IDLE_MIRROR || p->state == MOVE_MIRROR)
        printf("IDLE_MIRROR\n");
    else
        p->state = IDLE;
    if ((sfKeyboard_isKeyPressed(71)) || (sfKeyboard_isKeyPressed(73) ||
        sfKeyboard_isKeyPressed(74)) && is_mirror(p)) {
        p->state = MOVE_MIRROR;
        if (event.key.shift)
            p->animation_speed = 0.1;
        else
            p->animation_speed = 0.15;
    } else if (sfKeyboard_isKeyPressed(73) ||
        sfKeyboard_isKeyPressed(74) || sfKeyboard_isKeyPressed(72)) {
        p->state = MOVE;
        if (event.key.shift)
            p->animation_speed = 0.1;
        else
            p->animation_speed = 0.15;
    }
    if (event.type == sfEvtMouseButtonPressed && is_mirror(p)) {
        printf("HIT_MIRROR\n");
    } else if (event.type == sfEvtMouseButtonPressed) {
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
