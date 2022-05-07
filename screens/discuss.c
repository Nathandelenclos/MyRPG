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
    game_obj *obj = get_closer_object(old, get_object(old, "player"), PNJ_ENTITY);
    game_obj *obj_b = get_object(new, "big_pnj");
    obj_b->data = obj->data;
    obj_b->animate = obj->animate;
    obj_b->texture = obj->texture;
    save_chest_background(old, new);
    sfSprite_setTexture(obj_b->sprite, obj->texture->texture, sfFalse);
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
    create_big_pnj(d, create_vector2f(0, -100), 40);
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
