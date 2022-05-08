/*
** EPITECH PROJECT, 2021
** MyRPG - screen
** File description:
** Pause menu
*/

#include "../../include/rpg.h"

void events_pause(scene *d, sfEvent event)
{
    events_manage(d, event);
    switch (event.type) {
    case sfEvtKeyPressed:
        if (event.key.code == d->hub->s->c->menu)
            switch_scene(d, PLAY);
    }
}

void pause_screen(scene *data)
{
    sprites_manager(data);
    move_manager(data);
    time_manager(data);
    text_manager(data);
}

void create_data_pause(scene *d)
{
    d->textures = get_scene(d, START)->textures;
    create_chest_background_sprite(d);
    create_btn_text(d, "   PLAY",
    create_text_id_struct(95, HOME_BTN, 2), create_vector2f(822.5, 480));
    create_btn_text(d, " SETTINGS",
    create_text_id_struct(80, HOME_BTN, 2), create_vector2f(822.5, 610));
    create_btn_text(d, "MAIN MENU",
    create_text_id_struct(65, HOME_BTN, 2), create_vector2f(840, 743));
    create_sprite_lb(d, "white_lb",
    create_btn_param(create_vector2f(822.5, 500), 1, 5, HOME_BTN), "   PLAY");
    create_sprite_lb(d, "white_lb",
    create_btn_param(create_vector2f(822.5, 620), 1, 5, HOME_BTN),
    " SETTINGS");
    create_sprite_lb(d, "white_lb",
    create_btn_param(create_vector2f(822.5, 740), 1, 5, HOME_BTN),
    "MAIN MENU");
}

void active_pause(scene *old, scene *new)
{
    sfRenderWindow_setMouseCursorVisible(new->hub->window, sfTrue);
    save_chest_background(old, new);
}

void data_pause(screen *screen1)
{
    scene *d = create_scene(screen1, PAUSE);
    d->screen = pause_screen;
    d->event = events_pause;
    d->active = active_pause;
    create_data_pause(d);
    put_in_list(&screen1->datas, d);
}
