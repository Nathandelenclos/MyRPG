/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** Screen
*/

#include "../../include/my.h"
#include "../../include/rpg.h"
#include <SFML/Window.h>
#include <SFML/Graphics.h>

void events_play(scene *d, sfEvent event)
{
    events_manage(d, event);
    switch (event.type) {
    case sfEvtClosed:
        sfRenderWindow_close(d->hub->window);
        break;
    case sfEvtKeyPressed:
        if (event.key.code == sfKeyEscape)
            switch_scene(d, START);
        if (event.key.code == sfKeySpace)
            switch_scene(d, CHEST);
        break;
    }
}

void play_screen(scene *data)
{
    sprites_manager(data);
    move_manager(data);
    time_manager(data);
    text_manager(data);
    env_manager(data);
}

void create_data_play(scene *d)
{
    d->textures = get_scene(d, START)->textures;
    create_sprite_map(d);
    create_player(d);
    display_fps(d);
    create_rain_env(d);
    create_snow_env(d);
    create_slime(d, 100,100, BLUE);
    create_slime(d, 100,200, BLACK);
    create_slime(d, 100,300, YELLOW);
    create_slime(d, 200,100, GREEN);
    create_slime(d, 300,100, PINK);
    d->env_type = RAIN;
}

void active_play(scene *old, scene *new)
{

    node *tmp = new->objs;
    game_obj *obj = NULL;
    sfColor color;

    sfRenderWindow_setMouseCursorVisible(new->hub->window, sfFalse);
    if (old->state != START)
        return;
    for (int t = 0; t <= 255; ++t) {
        sfRenderWindow_clear(new->hub->window, sfBlack);
        while (tmp != NULL) {
            obj = (game_obj *)tmp->data;
            color = sfSprite_getColor(obj->sprite);
            color.a = t;
            sfSprite_setColor(obj->sprite, color);
            sfRenderWindow_drawSprite(new->hub->window, obj->sprite, NULL);
            tmp = tmp->next;
        }
        tmp = new->objs;
        sfRenderWindow_display(new->hub->window);
    }
}

void data_play(screen *screen1)
{
    scene *d = create_scene(screen1, PLAY);
    d->screen = play_screen;
    d->event = events_play;
    d->active = active_play;
    create_data_play(d);
    put_in_list(&screen1->datas, d);
}
