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

    if (is_on_btn(s, event.mouseButton, g->id)) {
        sfRenderWindow_waitEvent(s->hub->window, &event);
        if (event.key.code) {
            n = event.key.code;
            modify_string(s, (char *)TOUCH[s->hub->s->c->up], (char *)TOUCH[n]);
//            s->hub->s->c->up = n;
        }
    }
}