/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** open_inventory_chest
*/

#include "../include/rpg.h"
#include "../include/my.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

void event_switch_case(scene *d, sfEvent event, game_obj *p, game_obj *c)
{
    inventory *inv = NULL;
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(d->hub->window);
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == d->hub->s->c->menu) {
            switch_scene(d, PLAY);
            action_click_on_case(d, 0, event.mouseButton, NULL);
        }
    }
    if (event.type == sfEvtMouseButtonPressed) {
        for (int i = 0; i < 36; i++) {
            inv = i >= 27 ? ((player *) p->data)->inventory
                            : ((chest *) c->data)->inventory;
            action_click_on_case(d, i, event.mouseButton, inv);
        }
    }
}

void events_chest(scene *d, sfEvent event)
{
    events_manage(d, event);
    scene *play = get_scene(d, PLAY);
    game_obj *p = get_object(play, "player");
    game_obj *c = get_closer_object(play, p, CHESTS_G);
    event_switch_case(d, event, p, c);
}
