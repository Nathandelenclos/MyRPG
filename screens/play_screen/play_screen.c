/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** Screen
*/

#include "../../include/my.h"
#include "../../include/rpg.h"
#include <SFML/Window.h>
#include <stdio.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>

void events_play(scene *d, sfEvent event)
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

void play_screen(scene *data)
{
    sprites_manager(data);
    move_manager(data);
    time_manager(data);
    text_manager(data);
}

void create_data_play(scene *d)
{
    d->textures = get_scene(d, START)->textures;
    create_sprite_map(d);
    create_player(d);
    display_fps(d);
    create_slime(d, 100, 100, GREEN);
    create_slime(d, 100, 200, YELLOW);
    create_slime(d, 200, 100, BLUE);
    create_slime(d, 200, 200, BLACK);
}

void data_play(screen *screen1)
{
    scene *d = create_scene(screen1, PLAY);
    d->screen = play_screen;
    d->event = events_play;
    create_data_play(d);
    put_in_list(&screen1->datas, d);
}
