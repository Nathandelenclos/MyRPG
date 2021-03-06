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
        if (event.key.code == sfKeyEnter)
            switch_scene(d, PLAY);
    }
}

void start_screen(scene *data)
{
    sprites_manager(data);
    move_manager(data);
    time_manager(data);
    text_manager(data);
}

void active_start(scene *old, scene *new)
{
    sfRenderWindow_setMouseCursorVisible(new->hub->window, sfTrue);
}

void create_data(scene *d)
{
    create_textures(d);
    create_sprite_menu(d);
    create_btn_text(d, "   PLAY",
    create_text_id_struct(95, HOME_BTN, 2), create_vector2f(822.5, 480));
    create_btn_text(d, " SETTINGS",
    create_text_id_struct(80, HOME_BTN, 2), create_vector2f(822.5, 610));
    create_btn_text(d, "   QUIT",
    create_text_id_struct(100, HOME_BTN, 2), create_vector2f(822.5, 715));
    create_sprite_lb(d, "white_lb",
    create_btn_param(create_vector2f(822.5, 500), 1, 5, HOME_BTN), "   PLAY");
    create_sprite_lb(d, "white_lb",
    create_btn_param(create_vector2f(822.5, 620), 1, 5, HOME_BTN),
    " SETTINGS");
    create_sprite_lb(d, "white_lb",
    create_btn_param(create_vector2f(822.5, 740), 1, 5, HOME_BTN), "   QUIT");
    sound_manager(d);
}

void data_start(screen *screen1)
{
    scene *d = create_scene(screen1, START);
    d->screen = start_screen;
    d->event = events;
    d->active = active_start;
    create_data(d);
    put_in_list(&screen1->datas, d);
}
