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

void discuss_screen(scene *data)
{
    sprites_manager(data);
    move_manager(data);
    time_manager(data);
    text_manager(data);
}

void active_discuss(scene *old, scene *new)
{
    if (old->state != PLAY)
        return;
    game_obj
        *obj = get_closer_object(old, get_object(old, "player"), PNJ_ENTITY);
    game_obj *obj_b = get_object(new, "big_pnj");
    pnj *p = obj->data;
    obj_b->data = obj->data;
    obj_b->animate = obj->animate;
    obj_b->texture = obj->texture;
    save_chest_background(old, new);
    sfSprite_setTexture(obj_b->sprite, obj->texture->texture, sfFalse);
    if (p->step == 2) {
        if (count_max_quest() > (p->dialog + 1)) {
            p->dialog++;
            p->quest = quests[p->dialog];
            p->step = 0;
        }
    } else if (p->step == 1)
        p->step = p->quest(old) ? 2 : 1;
}

void events_discuss(scene *d, sfEvent event)
{
    events_manage(d, event);
    scene *play = get_scene(d, PLAY);
    game_obj *pnj_a = get_closer_object(play, get_object(play, "player"), PNJ_ENTITY);
    pnj *p = pnj_a->data;
    switch (event.type) {
    case sfEvtClosed:
        sfRenderWindow_close(d->hub->window);
        break;
    case sfEvtKeyPressed:
        if (event.key.code == sfKeyEscape) {
            check_quest(d, p);
            switch_scene(d, PLAY);
        }
        break;
    }
}

void create_scene_data_discuss(scene *d)
{
    d->textures = get_scene(d, START)->textures;
    create_chest_background_sprite(d);
    create_big_pnj(d, create_vector2f(0, -100), 40);

    sfSprite_setScale(create_sprite_popup(d,
        create_vector2f(d->hub->mode.width / 2 - (723 / 2) * 2, 800))->sprite,
        create_vector2f(2, 1.5));
    scene *play = get_scene(d, PLAY);
    game_obj *pnj_a = get_closer_object(play, get_object(play, "player"), PNJ_ENTITY);
    display_dialog(d, (pnj *) pnj_a->data);
}

void data_discuss(screen *screen1)
{
    scene *d = create_scene(screen1, DISCUSS);
    d->screen = discuss_screen;
    d->event = events_discuss;
    d->active = active_discuss;
    create_scene_data_discuss(d);
    put_in_list(&screen1->datas, d);
}
