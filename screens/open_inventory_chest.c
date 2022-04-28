/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** open_inventory_chest
*/

#include "../include/rpg.h"
#include "../include/my.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

void events_chest(scene *d, sfEvent event)
{
    events_manage(d, event);
    switch (event.type) {
    case sfEvtClosed:
        sfRenderWindow_close(d->hub->window);
        break;
    case sfEvtKeyPressed:
        if (event.key.code == sfKeyEscape)
            switch_scene(d, PLAY);
    }
}

void chest_screen(scene *data)
{
    sprites_manager(data);
    move_manager(data);
    time_manager(data);
    text_manager(data);
}

void create_chest_scene_data(scene *d)
{
    d->textures = get_scene(d, START)->textures;
    create_chest_background_sprite(d);
    create_chest_inventory_sprite(d);
}

void save_background(scene *old, scene *new)
{
    sfTexture *texture =
    sfTexture_create(old->hub->mode.width, old->hub->mode.height);
    sfTexture_updateFromRenderWindow(texture, old->hub->window, 0, 0);
    game_obj *g = get_object(new, "background");
    sfSprite_setTexture(g->sprite, texture, sfTrue);
}

void data_chest(screen *screen1)
{
    scene *d = create_scene(screen1, CHEST);
    d->screen = chest_screen;
    d->event = events_chest;
    d->active = save_background;
    create_chest_scene_data(d);
    put_in_list(&screen1->datas, d);
}
