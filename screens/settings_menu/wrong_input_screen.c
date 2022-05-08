/*
** EPITECH PROJECT, 2021
** MyRPG
** File descriptiofn:
** Screen
*/

#include "../../include/rpg.h"

void events_wrong_input(scene *d, sfEvent event)
{
    events_manage(d, event);
    switch (event.type) {
    case sfEvtKeyPressed:
        d->hub->state = SETTINGS;
    }
}

void wrong_input_screen(scene *data)
{
    sprites_manager(data);
    move_manager(data);
    time_manager(data);
    text_manager(data);
}

void create_sprite_settings_error(scene *d)
{
    d->textures = get_scene(d, SETTINGS)->textures;
    d->sounds = get_scene(d, SETTINGS)->sounds;
    create_sprite_bg_settings(d);
    create_sprite_popup(d, create_vector2f(598.5, 414.5));
    create_btn_text(d, "INPUT IS NOT VALID!", create_text_id_struct(60, HOME_BTN, 3), create_vector2f(760, 500));
    create_btn_text(d, "(press any key to disable this error message)", create_text_id_struct(20, HOME_BTN, 3), create_vector2f(785, 620));
}

void save_background(scene *old, scene *new)
{
    sfTexture *texture =
        sfTexture_create(old->hub->mode.width, old->hub->mode.height);
    sfTexture_updateFromRenderWindow(texture, old->hub->window, 0, 0);
    game_obj *g = get_object(new, "settings_bg");
    sfColor color = sfSprite_getColor(g->sprite);
    color.a = 135;
    sfSprite_setColor(g->sprite, color);
    sfSprite_setTexture(g->sprite, texture, sfTrue);
}

void wrong_input(screen *screen1)
{
    scene *d = create_scene(screen1, SETTINGS_ERROR);
    d->screen = wrong_input_screen;
    d->event = events_wrong_input;
    d->active = save_background;
    create_sprite_settings_error(d);
    put_in_list(&screen1->datas, d);
}
