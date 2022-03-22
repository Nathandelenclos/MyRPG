/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** Screen
*/

#include "../../include/rpg.h"

void events_game_over(scene *d, sfEvent event)
{
    switch (event.type) {
    case sfEvtClosed:
        sfRenderWindow_close(d->hub->window);
        break;
    case sfEvtKeyPressed:
        if (event.key.code == sfKeyEscape)
            d->hub->state = START;
    }
}

void game_over_screen(struct data_s *data)
{
    sprites_manager(data);
    time_manager(data);
    text_manager(data);
}

void create_data_game_over(scene *d)
{
    d->textures = get_scene(d, START)->textures;
    create_home_btn(d, 200, 200);
}

void data_game_over(screen *screen1)
{
    scene *d = create_scene(screen1, GAME_OVER);
    d->screen = game_over_screen;
    d->event = events_game_over;
    d->lb = create_life_bar(400, 20, sfGreen, sfBlack);
    create_data_game_over(d);
    put_in_list(&screen1->datas, d);
}
