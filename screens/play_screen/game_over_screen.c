/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** Screen
*/

#include "../../include/rpg.h"

void events_game_over(scene *d, sfEvent event)
{
    events_manage(d, event);
    switch (event.type) {
    case sfEvtKeyPressed:
        if (event.key.code == sfKeyEscape)
            switch_scene(d, START);
    }
}

void game_over_screen(scene *data)
{
    sprites_manager(data);
    move_manager(data);
    time_manager(data);
    text_manager(data);
}

void create_data_game_over(scene *d)
{
    d->textures = get_scene(d, START)->textures;
    create_sprite_bg_game_over(d);
    create_sprite_popup(d, create_vector2f(598.5, 414.5));
    create_btn_text(d, "GAME OVER", create_text_id_struct(120, UI, 3), create_vector2f(740, 450));
    create_btn_text(d, "RESPAWN", create_text_id_struct(65, HOME_BTN, 3), create_vector2f(633.5, 945));
    create_btn_text(d, "MAIN MENU", create_text_id_struct(65, HOME_BTN, 3), create_vector2f(1066.5, 945));
    create_sprite_lb(d, "white_lb", create_btn_param(create_vector2f(598.5, 945), 2, 5, HOME_BTN), "RESPAWN");
    create_sprite_lb(d, "white_lb", create_btn_param(create_vector2f(1046.5, 945), 2, 5, HOME_BTN), "MAIN MENU");
}

void save_background_game_over(scene *old, scene *new)
{
    sfRenderWindow_setMouseCursorVisible(new->hub->window, sfTrue);
    sfTexture *texture =
        sfTexture_create(old->hub->mode.width, old->hub->mode.height);
    sfTexture_updateFromRenderWindow(texture, old->hub->window, 0, 0);
    game_obj *g = get_object(new, "game_over");
    sfColor color = sfSprite_getColor(g->sprite);
    color.a = 200;
    color.r = 255;
    color.b = 50;
    color.g = 50;
    sfSprite_setColor(g->sprite, color);
    sfSprite_setTexture(g->sprite, texture, sfTrue);
}

void data_game_over(screen *screen1)
{
    scene *d = create_scene(screen1, GAME_OVER);
    d->screen = game_over_screen;
    d->event = events_game_over;
    d->active = save_background_game_over;
    create_data_game_over(d);
    put_in_list(&screen1->datas, d);
}
