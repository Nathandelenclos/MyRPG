/*
** EPITECH PROJECT, 2021
** moving_button.c
** File description:
** Created by Bastien Mazzolini
*/

#include "../../include/rpg.h"

void create_buttons_move(scene *d)
{
    create_sprite_lb(d, "white_lb",
    create_btn_param(create_vector2f(1065, 355), 1, 3, SCROLL_BTN_IN),
        (char *)TOUCH[d->hub->s->c->up]);
    create_sprite_lb(d, "white_lb",
    create_btn_param(create_vector2f(1065, 455), 1, 3, SCROLL_BTN_IN),
        (char *)TOUCH[d->hub->s->c->down]);
    create_sprite_lb(d, "white_lb",
    create_btn_param(create_vector2f(1065, 555), 1, 3, SCROLL_BTN_IN),
        (char *)TOUCH[d->hub->s->c->left]);
    create_sprite_lb(d, "white_lb",
    create_btn_param(create_vector2f(1065, 655), 1, 3, SCROLL_BTN_IN),
        (char *)TOUCH[d->hub->s->c->right]);
    create_sprite_lb(d, "white_lb",
    create_btn_param(create_vector2f(1065, 755), 1, 3, SCROLL_BTN_IN),
        (char *)TOUCH[d->hub->s->c->run]);
}

void create_buttons_interact(scene *d)
{
    create_sprite_lb(d, "white_lb",
    create_btn_param(create_vector2f(1065, 855), 1, 3, SCROLL_BTN_IN),
        (char *)TOUCH[d->hub->s->c->interact]);
    create_sprite_lb(d, "white_lb",
    create_btn_param(create_vector2f(1065, 955), 1, 3, SCROLL_BTN_IN),
        (char *)TOUCH[d->hub->s->c->attack]);
}

void create_button_setting_basic(scene *d)
{
    create_buttons_move(d);
    create_buttons_interact(d);
    create_sprite_lb(d, "white_lb",
    create_btn_param(create_vector2f(1065, 1055), 1, 3, SCROLL_BTN_IN),
        (char *)TOUCH[d->hub->s->c->menu]);
    create_sprite_lb(d, "white_lb",
    create_btn_param(create_vector2f(1065, 1155), 1, 3, SCROLL_BTN_IN),
        (char *)TOUCH[d->hub->s->c->drop]);
    create_sprite_lb(d, "white_lb",
    create_btn_param(create_vector2f(1065, 2355), 1, 3, SCROLL_BTN_IN),
        (char *)TOUCH[d->hub->s->c->screen]);
    create_sprite_lb(d, "white_lb",
    create_btn_param(create_vector2f(1065, 2455), 1, 3, SCROLL_BTN_IN),
        (char *)TOUCH[d->hub->s->c->info]);
}
