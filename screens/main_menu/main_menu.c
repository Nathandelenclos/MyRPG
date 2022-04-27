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
    display_fps(d);
    create_sprite_lb(d, "purple_lb", 450, 250);
    create_sprite_lb(d, "purple_lb", 450, 320);
    create_sprite_lb(d, "purple_lb", 450, 390);
    create_sprite_lb(d, "purple_lb", 450, 460);
    create_sprite_rb(d, "purple_rb", 0, 0);
    create_sprite_rb(d, "purple_rb", 1000, 0);
    create_sprite_sb(d, "purple_sb", 1000, 320);
    sound_manager(d);
    create_slime(d, 100, 100, GREEN);
    create_slime(d, 200, 200, YELLOW);
}

void data_start(screen *screen1)
{
    scene *d = create_scene(screen1, START);
    d->screen = start_screen;
    d->event = events;
    create_data(d);
    put_in_list(&screen1->datas, d);
}
