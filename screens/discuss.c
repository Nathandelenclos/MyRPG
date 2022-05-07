/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** discuss
*/

#include "../include/my.h"
#include "../include/rpg.h"
#include <SFML/Window.h>
#include <SFML/Graphics.h>

void active_discuss(scene *old, scene *new)
{
    // node *tmp = new->objs;
    // game_obj *obj = NULL;
    // sfColor color;

    // sfRenderWindow_setMouseCursorVisible(new->hub->window, sfFalse);
    // if (old->state != START)
    //     return;
    // for (int t = 0; t <= 255; ++t) {
    //     sfRenderWindow_clear(new->hub->window, sfBlack);
    //     while (tmp != NULL) {
    //         obj = (game_obj *) tmp->data;
    //         color = sfSprite_getColor(obj->sprite);
    //         color.a = t;
    //         sfSprite_setColor(obj->sprite, color);
    //         sfRenderWindow_drawSprite(new->hub->window, obj->sprite, NULL);
    //         tmp = tmp->next;
    //     }
    //     tmp = new->objs;
    //     sfRenderWindow_display(new->hub->window);
    // }

    save_chest_background(old, new);
}

void events_discuss(scene *d, sfEvent event)
{
    events_manage(d, event);
    switch (event.type) {
    case sfEvtClosed:
        sfRenderWindow_close(d->hub->window);
        break;
    case sfEvtKeyPressed:
        if (event.key.code == sfKeyEscape)
            switch_scene(d, PLAY);
        break;
    }
}

void create_scene_data_discuss(scene *d)
{
    d->textures = get_scene(d, START)->textures;
    create_chest_background_sprite(d);
}

void data_discuss(screen *screen1)
{
    scene *d = create_scene(screen1, DISCUSS);
    d->screen = play_screen;
    d->event = events_discuss;
    d->active = active_discuss;
    create_scene_data_discuss(d);
    put_in_list(&screen1->datas, d);
}
