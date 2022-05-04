/*
** EPITECH PROJECT, 2021
** event_change_input_setting.c
** File description:
** Created by Bastien Mazzolini
*/

#include "../../include/rpg.h"

void lb_change_input(sfEvent event, button *d, game_obj *g, scene *s)
{
    int n = 0;
    controls *c = s->hub->s->c;

    if (is_on_btn(s, event.mouseButton, g->id)) {
        sfRenderWindow_waitEvent(s->hub->window, &event);
        if (event.key.code && my_strcmp(d->t->string, TOUCH[c->up])) {
            modify_string(s, (char *)TOUCH[c->up],
             (char *)TOUCH[event.key.code]);
        }
        if (event.key.code && my_strcmp(d->t->string, TOUCH[c->down])) {
            modify_string(s, (char *)TOUCH[c->down],
             (char *)TOUCH[event.key.code]);
        }
    }
}