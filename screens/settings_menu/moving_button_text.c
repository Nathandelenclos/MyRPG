/*
** EPITECH PROJECT, 2021
** moving_button.c
** File description:
** Created by Bastien Mazzolini
*/

#include "../../include/rpg.h"

void create_move_text(scene *d)
{
    create_btn_text(d, (char *)TOUCH[d->hub->s->c->up],
    create_text_id_struct(50, SCROLL_BTN_IN, 1), create_vector2f(1080, 348));
    create_btn_text(d, (char *)TOUCH[d->hub->s->c->down],
    create_text_id_struct(50, SCROLL_BTN_IN, 1), create_vector2f(1080, 448));
    create_btn_text(d, (char *)TOUCH[d->hub->s->c->left],
    create_text_id_struct(50, SCROLL_BTN_IN, 1), create_vector2f(1080, 548));
    create_btn_text(d, (char *)TOUCH[d->hub->s->c->right],
    create_text_id_struct(50, SCROLL_BTN_IN, 1), create_vector2f(1080, 648));
}

void create_text_setting_basic_right(scene *d)
{
    create_move_text(d);
    create_btn_text(d, (char *)TOUCH[d->hub->s->c->run],
    create_text_id_struct(50, SCROLL_BTN_IN, 1), create_vector2f(1080, 748));
    create_btn_text(d, (char *)TOUCH[d->hub->s->c->interact],
    create_text_id_struct(50, SCROLL_BTN_IN, 1), create_vector2f(1080, 848));
    create_btn_text(d, (char *)TOUCH[d->hub->s->c->attack],
    create_text_id_struct(50, SCROLL_BTN_IN, 1), create_vector2f(1080, 948));
    create_btn_text(d, (char *)TOUCH[d->hub->s->c->menu],
    create_text_id_struct(50, SCROLL_BTN_IN, 1), create_vector2f(1080, 1048));
    create_btn_text(d, (char *)TOUCH[d->hub->s->c->drop],
    create_text_id_struct(50, SCROLL_BTN_IN, 1), create_vector2f(1080, 1148));
    create_btn_text(d, (char *)TOUCH[d->hub->s->c->screen],
    create_text_id_struct(50, SCROLL_BTN_IN, 1), create_vector2f(1080, 2348));
    create_btn_text(d, (char *)TOUCH[d->hub->s->c->info],
    create_text_id_struct(50, SCROLL_BTN_IN, 1), create_vector2f(1080, 2448));
}

void create_text_interact(scene *d)
{
    create_btn_text(d, "Interact:",
    create_text_id_struct(50, SCROLL_BTN_IN, 1), create_vector2f(700, 850));
    create_btn_text(d, "Attack:",
    create_text_id_struct(50, SCROLL_BTN_IN, 1), create_vector2f(700, 950));
    create_btn_text(d, "Menu:",
    create_text_id_struct(50, SCROLL_BTN_IN, 1), create_vector2f(700, 1050));
    create_btn_text(d, "Drop Item:",
    create_text_id_struct(50, SCROLL_BTN_IN, 1), create_vector2f(700, 1150));
}

void create_text_setting_basic_left(scene *d)
{
    create_btn_text(d, "CONTROLS",
    create_text_id_struct(80, SCROLL_BTN_IN, 1), create_vector2f(805, 230));
    create_btn_text(d, "Up:",
    create_text_id_struct(50, SCROLL_BTN_IN, 1), create_vector2f(700, 350));
    create_btn_text(d, "Down:",
    create_text_id_struct(50, SCROLL_BTN_IN, 1), create_vector2f(700, 450));
    create_btn_text(d, "Left:",
    create_text_id_struct(50, SCROLL_BTN_IN, 1), create_vector2f(700, 550));
    create_btn_text(d, "Right:",
    create_text_id_struct(50, SCROLL_BTN_IN, 1), create_vector2f(700, 650));
    create_btn_text(d, "Run:",
    create_text_id_struct(50, SCROLL_BTN_IN, 1), create_vector2f(700, 750));
    create_text_interact(d);
    create_btn_text(d, "MISCELLANEOUS",
    create_text_id_struct(50, SCROLL_BTN_IN, 1), create_vector2f(850, 2250));
    create_btn_text(d, "Screenshot:",
    create_text_id_struct(50, SCROLL_BTN_IN, 1), create_vector2f(700, 2350));
    create_btn_text(d, "Info:",
    create_text_id_struct(50, SCROLL_BTN_IN, 1), create_vector2f(700, 2450));
}

void create_button_setting(scene *d)
{
    create_text_setting_basic_left(d);
    create_text_setting_basic_right(d);
    create_button_setting_basic(d);
    create_text_setting_invent_left(d);
}
