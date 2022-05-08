/*
** EPITECH PROJECT, 2021
** event_change_input_setting.c
** File description:
** Created by Bastien Mazzolini
*/

#include "../../include/rpg.h"

void change_input_slot_p5(button *d, controls *c, sfEvent event, scene *s)
{
    if (event.key.code && my_strcmp(d->t->string, TOUCH[c->slot9])) {
        if (input_handling(event.key.code, c, s)) {
            modify_string(s, (char *)TOUCH[c->slot9],
            (char *)TOUCH[event.key.code]);
            c->slot9 = event.key.code;
        }
    }
}

void change_input_slot_p4(button *d, controls *c, sfEvent event, scene *s)
{
    if (event.key.code && my_strcmp(d->t->string, TOUCH[c->slot7])) {
        if (input_handling(event.key.code, c, s)) {
            modify_string(s, (char *)TOUCH[c->slot7],
            (char *)TOUCH[event.key.code]);
            c->slot7 = event.key.code;
        }
    }
    if (event.key.code && my_strcmp(d->t->string, TOUCH[c->slot8])) {
        if (input_handling(event.key.code, c, s)) {
            modify_string(s, (char *)TOUCH[c->slot8],
            (char *)TOUCH[event.key.code]);
            c->slot8 = event.key.code;
        }
    }
    change_input_slot_p5(d, c, event, s);
}

void change_input_slot_p3(button *d, controls *c, sfEvent event, scene *s)
{
    if (event.key.code && my_strcmp(d->t->string, TOUCH[c->slot5])) {
        if (input_handling(event.key.code, c, s)) {
            modify_string(s, (char *)TOUCH[c->slot5],
            (char *)TOUCH[event.key.code]);
            c->slot5 = event.key.code;
        }
    }
    if (event.key.code && my_strcmp(d->t->string, TOUCH[c->slot6])) {
        if (input_handling(event.key.code, c, s)) {
            modify_string(s, (char *)TOUCH[c->slot6],
            (char *)TOUCH[event.key.code]);
            c->slot6 = event.key.code;
        }
    }
    change_input_slot_p4(d, c, event, s);
}

void change_input_slot_p2(button *d, controls *c, sfEvent event, scene *s)
{
    if (event.key.code && my_strcmp(d->t->string, TOUCH[c->slot3])) {
        if (input_handling(event.key.code, c, s)) {
            modify_string(s, (char *)TOUCH[c->slot3],
            (char *)TOUCH[event.key.code]);
            c->slot3 = event.key.code;
        }
    }
    if (event.key.code && my_strcmp(d->t->string, TOUCH[c->slot4])) {
        if (input_handling(event.key.code, c, s)) {
            modify_string(s, (char *)TOUCH[c->slot4],
            (char *)TOUCH[event.key.code]);
            c->slot4 = event.key.code;
        }
    }
    change_input_slot_p3(d, c, event, s);
}

void change_input_slot_p1(button *d, controls *c, sfEvent event, scene *s)
{
    if (event.key.code && my_strcmp(d->t->string, TOUCH[c->slot1])) {
        if (input_handling(event.key.code, c, s)) {
            modify_string(s, (char *)TOUCH[c->slot1],
            (char *)TOUCH[event.key.code]);
            c->slot1 = event.key.code;
        }
    }
    if (event.key.code && my_strcmp(d->t->string, TOUCH[c->slot2])) {
        if (input_handling(event.key.code, c, s)) {
            modify_string(s, (char *)TOUCH[c->slot2],
            (char *)TOUCH[event.key.code]);
            c->slot2 = event.key.code;
        }
    }
    change_input_slot_p2(d, c, event, s);
}
