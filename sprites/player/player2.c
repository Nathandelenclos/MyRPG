/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** player2
*/

#include "../../include/rpg.h"

int is_mirror(player *p)
{
    if (p->state == IDLE_MIRROR || p->state == HIT_MIRROR
    || p->state == MOVE_MIRROR) {
        return 1;
    }
    return 0;
}

void direction_event(player *p, sfEvent event, int state)
{
    p->state = state;
    if (event.key.shift)
        p->animation_speed = 0.1;
    else
        p->animation_speed = 0.15;
}

void attack_event(scene *d, game_obj *g, sfIntRect rect, int state)
{
    player *p = (player *) g->data;
    rect.left = 0;
    p->state = state;
    float distance = get_distance(g, get_closer_object(d, g, ENEMY));
    if (distance <= 175.0 && distance >= 0.0) {
        game_obj *s = get_closer_object(d, g, ENEMY);
        if (s != NULL)
            ((slime *)s->data)->hp -= 3;
    }
    sfSprite_setTextureRect(g->sprite, rect);
}

void choose_state(player *p)
{
    if (is_mirror(p))
        p->state = IDLE_MIRROR;
    else if (!is_mirror(p))
        p->state = IDLE;
}

void event_player(game_obj *g, scene *d, sfEvent event)
{
    player *p = (player *) g->data;
    sfIntRect rect = sfSprite_getTextureRect(g->sprite);
    if (p->state == HIT || p->state == HIT_MIRROR)
        return;
    choose_state(p);
    if ((sfKeyboard_isKeyPressed(d->hub->s->c->left))
    || ((sfKeyboard_isKeyPressed(d->hub->s->c->up)
    || sfKeyboard_isKeyPressed(d->hub->s->c->down)) && is_mirror(p)))
        direction_event(p, event, MOVE_MIRROR);
    else if ((sfKeyboard_isKeyPressed(d->hub->s->c->right))
    || ((sfKeyboard_isKeyPressed(d->hub->s->c->up)
    || sfKeyboard_isKeyPressed(d->hub->s->c->down)) && !is_mirror(p)))
        direction_event(p, event, MOVE);
    if (sfKeyboard_isKeyPressed(d->hub->s->c->attack) && is_mirror(p))
        attack_event(d, g, rect, HIT_MIRROR);
    else if (sfKeyboard_isKeyPressed(d->hub->s->c->attack) && !is_mirror(p))
        attack_event(d, g, rect, HIT);
    if (event.key.code == d->hub->s->c->interact &&
    get_distance(g, get_closer_object(d, g, PNJ_ENTITY)) <= 200)
        switch_scene(d, DISCUSS);
}
