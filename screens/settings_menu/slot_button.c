/*
** EPITECH PROJECT, 2021
** slot_button.c
** File description:
** Created by Bastien Mazzolini
*/

#include "../../include/rpg.h"

void create_button_setting_invent2(scene *d)
{
    create_sprite_lb(d, "white_lb",
    create_btn_param(create_vector2f(1065, 1755), 1, 3, SCROLL_BTN_IN),
        (char *) TOUCH[d->hub->s->c->slot5]);
    create_sprite_lb(d, "white_lb",
    create_btn_param(create_vector2f(1065, 1855), 1, 3, SCROLL_BTN_IN),
        (char *) TOUCH[d->hub->s->c->slot6]);
    create_sprite_lb(d, "white_lb",
    create_btn_param(create_vector2f(1065, 1955), 1, 3, SCROLL_BTN_IN),
        (char *) TOUCH[d->hub->s->c->slot7]);
    create_sprite_lb(d, "white_lb",
    create_btn_param(create_vector2f(1065, 2055), 1, 3, SCROLL_BTN_IN),
        (char *) TOUCH[d->hub->s->c->slot8]);
    create_sprite_lb(d, "white_lb",
    create_btn_param(create_vector2f(1065, 2155), 1, 3, SCROLL_BTN_IN),
        (char *) TOUCH[d->hub->s->c->slot9]);
}

void create_button_setting_invent(scene *d)
{
    create_sprite_lb(d, "white_lb",
    create_btn_param(create_vector2f(1065, 1355), 1, 3, SCROLL_BTN_IN),
        (char *) TOUCH[d->hub->s->c->slot1]);
    create_sprite_lb(d, "white_lb",
    create_btn_param(create_vector2f(1065, 1455), 1, 3, SCROLL_BTN_IN),
        (char *) TOUCH[d->hub->s->c->slot2]);
    create_sprite_lb(d, "white_lb",
    create_btn_param(create_vector2f(1065, 1555), 1, 3, SCROLL_BTN_IN),
        (char *) TOUCH[d->hub->s->c->slot3]);
    create_sprite_lb(d, "white_lb",
    create_btn_param(create_vector2f(1065, 1655), 1, 3, SCROLL_BTN_IN),
        (char *) TOUCH[d->hub->s->c->slot4]);
    create_button_setting_invent2(d);
}

void create_text_setting_invent_right(scene *d)
{
    create_btn_text(d, (char *) TOUCH[d->hub->s->c->slot1],
    create_text_id_struct(50, SCROLL_BTN_IN, 1), create_vector2f(1080, 1350));
    create_btn_text(d, (char *) TOUCH[d->hub->s->c->slot2],
    create_text_id_struct(50, SCROLL_BTN_IN, 1), create_vector2f(1080, 1450));
    create_btn_text(d, (char *) TOUCH[d->hub->s->c->slot3],
    create_text_id_struct(50, SCROLL_BTN_IN, 1), create_vector2f(1080, 1550));
    create_btn_text(d, (char *) TOUCH[d->hub->s->c->slot4],
    create_text_id_struct(50, SCROLL_BTN_IN, 1), create_vector2f(1080, 1650));
    create_btn_text(d, (char *) TOUCH[d->hub->s->c->slot5],
    create_text_id_struct(50, SCROLL_BTN_IN, 1), create_vector2f(1080, 1750));
    create_btn_text(d, (char *) TOUCH[d->hub->s->c->slot6],
    create_text_id_struct(50, SCROLL_BTN_IN, 1), create_vector2f(1080, 1850));
    create_btn_text(d, (char *) TOUCH[d->hub->s->c->slot7],
    create_text_id_struct(50, SCROLL_BTN_IN, 1), create_vector2f(1080, 1950));
    create_btn_text(d, (char *) TOUCH[d->hub->s->c->slot8],
    create_text_id_struct(50, SCROLL_BTN_IN, 1), create_vector2f(1080, 2050));
    create_btn_text(d, (char *) TOUCH[d->hub->s->c->slot9],
    create_text_id_struct(50, SCROLL_BTN_IN, 1), create_vector2f(1080, 2150));
}

void create_text_setting_invent_left2(scene *d)
{
    create_btn_text(d, "Slot 5:",
    create_text_id_struct(50, SCROLL_BTN_IN, 1), create_vector2f(700, 1750));
    create_btn_text(d, "Slot 6:",
    create_text_id_struct(50, SCROLL_BTN_IN, 1), create_vector2f(700, 1850));
    create_btn_text(d, "Slot 7:",
    create_text_id_struct(50, SCROLL_BTN_IN, 1), create_vector2f(700, 1950));
    create_btn_text(d, "Slot 8:",
    create_text_id_struct(50, SCROLL_BTN_IN, 1), create_vector2f(700, 2050));
    create_btn_text(d, "Slot 9:",
    create_text_id_struct(50, SCROLL_BTN_IN, 1), create_vector2f(700, 2150));
}

void create_text_setting_invent_left(scene *d)
{
    create_btn_text(d, "INVENTORY",
    create_text_id_struct(50, SCROLL_BTN_IN, 1), create_vector2f(875, 1245));
    create_btn_text(d, "Slot 1:",
    create_text_id_struct(50, SCROLL_BTN_IN, 1), create_vector2f(700, 1350));
    create_btn_text(d, "Slot 2:",
    create_text_id_struct(50, SCROLL_BTN_IN, 1), create_vector2f(700, 1450));
    create_btn_text(d, "Slot 3:",
    create_text_id_struct(50, SCROLL_BTN_IN, 1), create_vector2f(700, 1550));
    create_btn_text(d, "Slot 4:",
    create_text_id_struct(50, SCROLL_BTN_IN, 1), create_vector2f(700, 1650));
    create_text_setting_invent_left2(d);
    create_text_setting_invent_right(d);
    create_button_setting_invent(d);
}
