/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** Screen
*/

#include "../include/rpg.h"

void events(scene *d, sfEvent event)
{
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
