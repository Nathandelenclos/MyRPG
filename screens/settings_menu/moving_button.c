/*
** EPITECH PROJECT, 2021
** moving_button.c
** File description:
** Created by Bastien Mazzolini
*/

#include "../../include/rpg.h"

void create_text_setting_basic_right(scene *d)
{
    create_btn_text(d, (char *)TOUCH[d->hub->s->c->up], 50,
        create_vector2f(980, 348));
    create_btn_text(d, (char *)TOUCH[d->hub->s->c->down], 50,
        create_vector2f(980, 448));
    create_btn_text(d, (char *)TOUCH[d->hub->s->c->left], 50,
        create_vector2f(980, 548));
    create_btn_text(d, (char *)TOUCH[d->hub->s->c->right], 50,
        create_vector2f(980, 648));
    create_btn_text(d, (char *)TOUCH[d->hub->s->c->run], 50,
        create_vector2f(980, 748));
    create_btn_text(d, (char *)TOUCH[d->hub->s->c->interact],
        50, create_vector2f(980, 848));
    create_btn_text(d, (char *)TOUCH[d->hub->s->c->attack],
        50, create_vector2f(980, 948));
    create_btn_text(d, (char *)TOUCH[d->hub->s->c->menu],
        50, create_vector2f(980, 1048));
    create_btn_text(d, (char *)TOUCH[d->hub->s->c->screen],
        50, create_vector2f(980, 1148));
}

void create_button_setting_basic(scene *d)
{
    create_sprite_lb(d, "white_lb", create_btn_param(create_vector2f(965, 355), 1, 3, SCROLL_BTN_IN),
        (char *)TOUCH[d->hub->s->c->up]);
    create_sprite_lb(d, "white_lb", create_btn_param(create_vector2f(965, 455), 1, 3, SCROLL_BTN_IN),
        (char *)TOUCH[d->hub->s->c->down]);
    create_sprite_lb(d, "white_lb", create_btn_param(create_vector2f(965, 555), 1, 3, SCROLL_BTN_IN),
        (char *)TOUCH[d->hub->s->c->left]);
    create_sprite_lb(d, "white_lb", create_btn_param(create_vector2f(965, 655), 1, 3, SCROLL_BTN_IN),
        (char *)TOUCH[d->hub->s->c->right]);
    create_sprite_lb(d, "white_lb", create_btn_param(create_vector2f(965, 755), 1, 3, SCROLL_BTN_IN),
        (char *)TOUCH[d->hub->s->c->run]);
    create_sprite_lb(d, "white_lb", create_btn_param(create_vector2f(965, 855), 1, 3, SCROLL_BTN_IN),
        (char *)TOUCH[d->hub->s->c->interact]);
    create_sprite_lb(d, "white_lb", create_btn_param(create_vector2f(965, 955), 1, 3, SCROLL_BTN_IN),
        (char *)TOUCH[d->hub->s->c->attack]);
    create_sprite_lb(d, "white_lb", create_btn_param(create_vector2f(965, 1055), 1, 3, SCROLL_BTN_IN),
        (char *)TOUCH[d->hub->s->c->menu]);
    create_sprite_lb(d, "white_lb", create_btn_param(create_vector2f(965, 1155), 1, 3, SCROLL_BTN_IN),
        (char *)TOUCH[d->hub->s->c->screen]);
}

void create_text_setting_basic_left(scene *d)
{
    create_btn_text(d, "CONTROLS", 80, create_vector2f(815, 230));
    create_btn_text(d, "Up:", 50, create_vector2f(565, 350));
    create_btn_text(d, "Down:", 50, create_vector2f(565, 450));
    create_btn_text(d, "Left:", 50, create_vector2f(565, 550));
    create_btn_text(d, "Right:", 50, create_vector2f(565, 650));
    create_btn_text(d, "Run:", 50, create_vector2f(565, 750));
    create_btn_text(d, "Interact:", 50, create_vector2f(565, 850));
    create_btn_text(d, "Attack:", 50, create_vector2f(565, 950));
    create_btn_text(d, "Menu:", 50, create_vector2f(565, 1050));
    create_btn_text(d, "Screenshot:", 50, create_vector2f(565, 1150));
}

void create_button_setting(scene *d)
{
    create_text_setting_basic_left(d);
    create_text_setting_basic_right(d);
    create_button_setting_basic(d);
    create_text_setting_invent_left(d);
}
