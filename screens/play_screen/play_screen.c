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
    switch (event.type) {
    case sfEvtClosed:
        sfRenderWindow_close(d->hub->window);
        break;
    case sfEvtKeyPressed:
        if (event.key.code == sfKeyEscape)
            d->hub->state = PAUSE;
    case sfEvtMouseButtonPressed:
        if (is_on_btn(d, event.mouseButton, INVISIBLE_BTN, NULL)) {
            d->hub->state = BUY;
            d->hub->data_switch->place =
                is_on_btn(d, event.mouseButton, INVISIBLE_BTN, NULL)->name;
        }
        if (is_on_btn(d, event.mouseButton, PAUSE_BTN, NULL)) {
            d->hub->state = PAUSE;
        }
        break;
    }
}

void play_screen(scene *data)
{
    sprites_manager(data);
    move_manager(data);
    time_manager(data);
    print_main_life(data);
    money_manager(data);
    text_manager(data);
}

void create_data_play(scene *d)
{
    d->textures = get_scene(d, START)->textures;
    display_score(d);
    display_money(d);
}

void data_play(screen *screen1)
{
    scene *d = create_scene(screen1, PLAY);
    d->screen = play_screen;
    d->event = events_play;
    d->stat = malloc(sizeof(game_stat));
    d->stat->score = 0;
    d->stat->game_life = 100;
    d->stat->money = 450;
    d->lb = create_life_bar(300, 20, sfGreen, sfBlack);
    create_data_play(d);
    put_in_list(&screen1->datas, d);
}
