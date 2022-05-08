/*
** EPITECH PROJECT, 2021
** event_change_input_setting.c
** File description:
** Created by Bastien Mazzolini
*/

#include "../../include/rpg.h"

void change_interact(button *d, controls *c, sfEvent event, scene *s)
{
    if (event.key.code && my_strcmp(d->t->string, TOUCH[c->interact])) {
        if (input_handling(event.key.code, c, s)) {
            modify_string(s, (char *)TOUCH[c->interact],
            (char *)TOUCH[event.key.code]);
            c->interact = event.key.code;
        }
    }
    if (event.key.code && my_strcmp(d->t->string, TOUCH[c->menu])) {
        if (input_handling(event.key.code, c, s)) {
            modify_string(s, (char *)TOUCH[c->menu],
            (char *)TOUCH[event.key.code]);
            c->menu = event.key.code;
        }
    }
}

void change_ingame_interact(button *d, controls *c, sfEvent event, scene *s)
{
    if (event.key.code && my_strcmp(d->t->string, TOUCH[c->attack])) {
        if (input_handling(event.key.code, c, s)) {
            modify_string(s, (char *)TOUCH[c->attack],
            (char *)TOUCH[event.key.code]);
            c->attack = event.key.code;
        }
    }
    if (event.key.code && my_strcmp(d->t->string, TOUCH[c->drop])) {
        if (input_handling(event.key.code, c, s)) {
            modify_string(s, (char *)TOUCH[c->drop],
            (char *)TOUCH[event.key.code]);
            c->drop = event.key.code;
        }
    }
}

void change_menu_interact(button *d, controls *c, sfEvent event, scene *s)
{
    if (event.key.code && my_strcmp(d->t->string, TOUCH[c->screen])) {
        if (input_handling(event.key.code, c, s)) {
            modify_string(s, (char *)TOUCH[c->screen],
            (char *)TOUCH[event.key.code]);
            c->screen = event.key.code;
        }
    }
    if (event.key.code && my_strcmp(d->t->string, TOUCH[c->info])) {
        if (input_handling(event.key.code, c, s)) {
            modify_string(s, (char *)TOUCH[c->info],
            (char *)TOUCH[event.key.code]);
            c->info = event.key.code;
        }
    }
}

void change_input_interact(button *d, controls *c, sfEvent event, scene *s)
{
    change_interact(d, c, event, s);
    change_ingame_interact(d, c, event, s);
    change_menu_interact(d, c, event, s);
}
