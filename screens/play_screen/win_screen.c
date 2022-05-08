/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** Screen
*/

#include "../../include/rpg.h"

void events_win(scene *d, sfEvent event)
{
    events_manage(d, event);
    switch (event.type) {
    case sfEvtKeyPressed:
        if (event.key.code == sfKeyEscape)
            switch_scene(d, START);
    }
}

void win_screen(scene *data)
{
    sprites_manager(data);
    move_manager(data);
    time_manager(data);
    text_manager(data);
}

void create_data_win(scene *d)
{
    d->textures = get_scene(d, START)->textures;
    create_sprite_bg_game_over(d);
    create_sprite_popup(d, create_vector2f(598.5, 414.5));
    create_btn_text(d, "YOU WON",
    create_text_id_struct(120, UI, 3), create_vector2f(850, 450));
    create_btn_text(d, "CONTINUE",
    create_text_id_struct(65, HOME_BTN, 3), create_vector2f(633.5, 945));
    create_btn_text(d, "MAIN MENU",
    create_text_id_struct(65, HOME_BTN, 3), create_vector2f(1066.5, 945));
    create_sprite_lb(d, "white_lb",
    create_btn_param(create_vector2f(598.5, 945), 2, 5, HOME_BTN), "CONTINUE");
    create_sprite_lb(d, "white_lb",
    create_btn_param(create_vector2f(1046.5, 945), 2, 5, HOME_BTN),
    "MAIN MENU");
}

void save_background_win(scene *old, scene *new)
{
    sfRenderWindow_setMouseCursorVisible(new->hub->window, sfTrue);
    sfTexture *texture =
        sfTexture_create(old->hub->mode.width, old->hub->mode.height);
    sfTexture_updateFromRenderWindow(texture, old->hub->window, 0, 0);
    game_obj *g = get_object(new, "game_over");
    sfColor color = sfSprite_getColor(g->sprite);
    color.a = 200;
    color.r = 50;
    color.b = 50;
    color.g = 255;
    sfSprite_setColor(g->sprite, color);
    sfSprite_setTexture(g->sprite, texture, sfTrue);
    game_obj *pl = get_object(old, "player");
    player *p = pl->data;
    clear_inventory(p->inventory);
    game_obj *maps = get_object(old, "maps");
    sfSprite_setPosition(maps->sprite, maps->position);
}

void data_win(screen *screen1)
{
    scene *d = create_scene(screen1, WIN);
    d->screen = win_screen;
    d->event = events_win;
    d->active = save_background_win;
    create_data_win(d);
    put_in_list(&screen1->datas, d);
}
