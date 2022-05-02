/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** Screen
*/

#include "../../include/rpg.h"

void events(scene *d, sfEvent event)
{
    events_manage(d, event);
    switch (event.type) {
    case sfEvtClosed:
        sfRenderWindow_close(d->hub->window);
        break;
    case sfEvtKeyPressed:
        if (event.key.code == sfKeyEscape)
            sfRenderWindow_close(d->hub->window);
    }
}

void start_screen(scene *data)
{
    sprites_manager(data);
    move_manager(data);
    time_manager(data);
    text_manager(data);
}

void create_data(scene *d)
{
    create_textures(d);
    create_sprite_menu(d);
    create_btn_text(d, "   PLAY", 95, create_vector2f(0, 0));
    create_btn_text(d, " SETTINGS", 80, create_vector2f(0, 0));
    create_btn_text(d, "   QUIT", 100, create_vector2f(0, 0));
    create_sprite_lb(d, "white_lb", create_btn_param(822.5, 500, 1, 5),
        "   PLAY");
    create_sprite_lb(d, "white_lb", create_btn_param(822.5, 620, 1, 5),
        " SETTINGS");
    create_sprite_lb(d, "white_lb", create_btn_param(822.5, 740, 1, 5),
        "   QUIT");
    sound_manager(d);
}

void data_start(screen *screen1)
{
    scene *d = create_scene(screen1, START);
    d->screen = start_screen;
    d->event = events;
    create_data(d);
    put_in_list(&screen1->datas, d);
}
