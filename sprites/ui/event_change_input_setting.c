/*
** EPITECH PROJECT, 2021
** event_change_input_setting.c
** File description:
** Created by Bastien Mazzolini
*/

#include "../../include/rpg.h"

void change_input_movement(button *d, controls *c, sfEvent event, scene *s)
{
    if (event.key.code && my_strcmp(d->t->string, TOUCH[c->up])) {
        modify_string(s, (char *)TOUCH[c->up],
         (char *)TOUCH[event.key.code]);
    }
    if (event.key.code && my_strcmp(d->t->string, TOUCH[c->down])) {
        modify_string(s, (char *)TOUCH[c->down],
         (char *)TOUCH[event.key.code]);
    }
    if (event.key.code && my_strcmp(d->t->string, TOUCH[c->left])) {
        modify_string(s, (char *)TOUCH[c->left],
         (char *)TOUCH[event.key.code]);
    }
    if (event.key.code && my_strcmp(d->t->string, TOUCH[c->right])) {
        modify_string(s, (char *)TOUCH[c->right],
         (char *)TOUCH[event.key.code]);
    }
    if (event.key.code && my_strcmp(d->t->string, TOUCH[c->run])) {
        modify_string(s, (char *)TOUCH[c->run],
         (char *)TOUCH[event.key.code]);
    }
}

void change_input_interact(button *d, controls *c, sfEvent event, scene *s)
{
    if (event.key.code && my_strcmp(d->t->string, TOUCH[c->interact])) {
            modify_string(s, (char *)TOUCH[c->interact],
             (char *)TOUCH[event.key.code]);
    }
    if (event.key.code && my_strcmp(d->t->string, TOUCH[c->attack])) {
        modify_string(s, (char *)TOUCH[c->attack],
         (char *)TOUCH[event.key.code]);
    }
    if (event.key.code && my_strcmp(d->t->string, TOUCH[c->menu])) {
        modify_string(s, (char *)TOUCH[c->menu],
         (char *)TOUCH[event.key.code]);
    }
    if (event.key.code && my_strcmp(d->t->string, TOUCH[c->screen])) {
        modify_string(s, (char *)TOUCH[c->screen],
         (char *)TOUCH[event.key.code]);
    }
}

void change_input_slot_p1(button *d, controls *c, sfEvent event, scene *s)
{
    if (event.key.code && my_strcmp(d->t->string, TOUCH[c->slot1])) {
            modify_string(s, (char *)TOUCH[c->slot1],
             (char *)TOUCH[event.key.code]);
    }
    if (event.key.code && my_strcmp(d->t->string, TOUCH[c->slot2])) {
        modify_string(s, (char *)TOUCH[c->slot2],
         (char *)TOUCH[event.key.code]);
    }
    if (event.key.code && my_strcmp(d->t->string, TOUCH[c->slot3])) {
        modify_string(s, (char *)TOUCH[c->slot3],
         (char *)TOUCH[event.key.code]);
    }
    if (event.key.code && my_strcmp(d->t->string, TOUCH[c->slot4])) {
        modify_string(s, (char *)TOUCH[c->slot4],
         (char *)TOUCH[event.key.code]);
    }
}

void change_input_slot_p2(button *d, controls *c, sfEvent event, scene *s)
{
    if (event.key.code && my_strcmp(d->t->string, TOUCH[c->slot5])) {
            modify_string(s, (char *)TOUCH[c->slot5],
             (char *)TOUCH[event.key.code]);
    }
    if (event.key.code && my_strcmp(d->t->string, TOUCH[c->slot6])) {
        modify_string(s, (char *)TOUCH[c->slot6],
         (char *)TOUCH[event.key.code]);
    }
    if (event.key.code && my_strcmp(d->t->string, TOUCH[c->slot7])) {
        modify_string(s, (char *)TOUCH[c->slot7],
         (char *)TOUCH[event.key.code]);
    }
    if (event.key.code && my_strcmp(d->t->string, TOUCH[c->slot8])) {
        modify_string(s, (char *)TOUCH[c->slot8],
         (char *)TOUCH[event.key.code]);
    }
    if (event.key.code && my_strcmp(d->t->string, TOUCH[c->slot9])) {
        modify_string(s, (char *)TOUCH[c->slot9],
         (char *)TOUCH[event.key.code]);
    }
}

void lb_change_input(sfEvent event, button *d, game_obj *g, scene *s)
{
    int n = 0;
    controls *c = s->hub->s->c;

    if (is_on_btn(s, event.mouseButton, g->id)) {
        sfRenderWindow_waitEvent(s->hub->window, &event);
        change_input_movement(d, c, event, s);
        change_input_interact(d, c, event, s);
        change_input_slot_p1(d, c, event, s);
        change_input_slot_p2(d, c, event, s);
    }
}