/*
** EPITECH PROJECT, 2021
** event_change_input_setting.c
** File description:
** Created by Bastien Mazzolini
*/

#include "../../include/rpg.h"

void change_arrow_keys_2(button *d, controls *c, sfEvent event, scene *s)
{
    if (event.key.code && my_strcmp(d->t->string, TOUCH[c->left])) {
        if (input_handling(event.key.code, c)) {
            modify_string(s, (char *)TOUCH[c->left],
             (char *)TOUCH[event.key.code]);
            c->left = event.key.code;
        }
    }
    if (event.key.code && my_strcmp(d->t->string, TOUCH[c->right])) {
        if (input_handling(event.key.code, c)) {
            modify_string(s, (char *)TOUCH[c->right],
             (char *)TOUCH[event.key.code]);
            c->right = event.key.code;
        }
    }
}

void change_arrow_keys(button *d, controls *c, sfEvent event, scene *s)
{
    if (event.key.code && my_strcmp(d->t->string, TOUCH[c->up])) {
        if (input_handling(event.key.code, c)) {
            modify_string(s, (char *)TOUCH[c->up],
             (char *)TOUCH[event.key.code]);
            c->up = event.key.code;
        }
    }
    if (event.key.code && my_strcmp(d->t->string, TOUCH[c->down])) {
        if (input_handling(event.key.code, c)) {
            modify_string(s, (char *)TOUCH[c->down],
             (char *)TOUCH[event.key.code]);
            c->down = event.key.code;
        }
    }
    change_arrow_keys_2(d, c, event, s);
}

void change_input_run(button *d, controls *c, sfEvent event, scene *s)
{
    if (event.key.code && my_strcmp(d->t->string, TOUCH[c->run])) {
        if (input_handling(event.key.code, c)) {
            modify_string(s, (char *)TOUCH[c->run],
             (char *)TOUCH[event.key.code]);
            c->run = event.key.code;
        }
    }
}

void change_input_movement(button *d, controls *c, sfEvent event, scene *s)
{
    change_arrow_keys(d, c, event, s);
    change_input_run(d, c, event, s);
}
