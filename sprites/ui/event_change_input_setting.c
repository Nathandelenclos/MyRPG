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

    if (is_on_btn(s, event.mouseButton, g->id) && g->grp == SCROLL_BTN_IN) {
        sfRenderWindow_waitEvent(s->hub->window, &event);
        if (event.key.code) {
            change_input_movement(d, c, event, s);
            change_input_interact(d, c, event, s);
            change_input_slot_p1(d, c, event, s);
        }
    }
}
