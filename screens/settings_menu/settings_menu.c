/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** Screen
*/

#include "../../include/rpg.h"

void events_settings(scene *d, sfEvent event)
{
    events_manage(d, event);
    switch (event.type) {
    case sfEvtKeyPressed:
        if (event.key.code == sfKeyEscape)
            d->hub->state = START;
    }
}

void settings_screen(scene *data)
{
    sprites_manager(data);
    move_manager(data);
    time_manager(data);
    text_manager(data);
}

void create_sprite_settings(scene *d)
{
    d->textures = get_scene(d, START)->textures;
    d->sounds = get_scene(d, START)->sounds;
    create_sprite_menu(d);
    create_btn_text(d, "   DONE", 95);
    create_sprite_lb(d, "white_lb", create_vector2f(822.5, 970.0), "   DONE");
    create_btn_text(d, my_int_to_str(d->hub->s->volume), 50);
    create_sprite_sb(d, "white_plus", create_vector2f(265, 200),
        my_int_to_str(d->hub->s->volume));
    create_sprite_sb(d, "white_minus", create_vector2f(135, 200),
        my_int_to_str(d->hub->s->volume));
    create_sprite_sb(d, "white_sb", create_vector2f(200, 200),
        my_int_to_str(d->hub->s->volume));
}

void data_settings(screen *screen1)
{
    scene *d = create_scene(screen1, SETTINGS);
    d->screen = settings_screen;
    d->event = events_settings;
    create_sprite_settings(d);
    put_in_list(&screen1->datas, d);
}
