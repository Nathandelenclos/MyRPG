/*
** EPITECH PROJECT, 2021
** slot_button.c
** File description:
** Created by Bastien Mazzolini
*/

#include "../../include/rpg.h"


void create_button_setting_invent(scene *d)
{
    create_sprite_lb(d, "white_lb", create_btn_param(create_vector2f(965, 1355), 1, 3, SCROLL_BTN_IN),
        TOUCH[d->hub->s->c->slot1]);
    create_sprite_lb(d, "white_lb", create_btn_param(create_vector2f(965, 1455), 1, 3, SCROLL_BTN_IN),
        TOUCH[d->hub->s->c->slot2]);
    create_sprite_lb(d, "white_lb", create_btn_param(create_vector2f(965, 1555), 1, 3, SCROLL_BTN_IN),
        TOUCH[d->hub->s->c->slot3]);
    create_sprite_lb(d, "white_lb", create_btn_param(create_vector2f(965, 1655), 1, 3, SCROLL_BTN_IN),
        TOUCH[d->hub->s->c->slot4]);
    create_sprite_lb(d, "white_lb", create_btn_param(create_vector2f(965, 1755), 1, 3, SCROLL_BTN_IN),
        TOUCH[d->hub->s->c->slot5]);
    create_sprite_lb(d, "white_lb", create_btn_param(create_vector2f(965, 1855), 1, 3, SCROLL_BTN_IN),
        TOUCH[d->hub->s->c->slot6]);
    create_sprite_lb(d, "white_lb", create_btn_param(create_vector2f(965, 1955), 1, 3, SCROLL_BTN_IN),
        TOUCH[d->hub->s->c->slot7]);
    create_sprite_lb(d, "white_lb", create_btn_param(create_vector2f(965, 2055), 1, 3, SCROLL_BTN_IN),
        TOUCH[d->hub->s->c->slot8]);
    create_sprite_lb(d, "white_lb", create_btn_param(create_vector2f(965, 2155), 1, 3, SCROLL_BTN_IN),
        TOUCH[d->hub->s->c->slot9]);
}

void create_text_setting_invent_right(scene *d)
{
    create_btn_text(d, TOUCH[d->hub->s->c->slot1], 50,
        create_vector2f(965, 1355));
    create_btn_text(d, TOUCH[d->hub->s->c->slot2], 50,
        create_vector2f(965, 1455));
    create_btn_text(d, TOUCH[d->hub->s->c->slot3], 50,
        create_vector2f(965, 1555));
    create_btn_text(d, TOUCH[d->hub->s->c->slot4], 50,
        create_vector2f(965, 1655));
    create_btn_text(d, TOUCH[d->hub->s->c->slot5], 50,
        create_vector2f(965, 1755));
    create_btn_text(d, TOUCH[d->hub->s->c->slot6],
        50, create_vector2f(965, 1855));
    create_btn_text(d, TOUCH[d->hub->s->c->slot7],
        50, create_vector2f(965, 1955));
    create_btn_text(d, TOUCH[d->hub->s->c->slot8],
        50, create_vector2f(965, 2055));
    create_btn_text(d, TOUCH[d->hub->s->c->slot9],
        50, create_vector2f(965, 2155));
}

void create_text_setting_invent_left(scene *d)
{
    create_btn_text(d, "INVENTORY", 50, create_vector2f(815, 1230));
    create_btn_text(d, "Slot 1:", 50, create_vector2f(565, 1350));
    create_btn_text(d, "Slot 2:", 50, create_vector2f(565, 1450));
    create_btn_text(d, "Slot 3:", 50, create_vector2f(565, 1550));
    create_btn_text(d, "Slot 4:", 50, create_vector2f(565, 1650));
    create_btn_text(d, "Slot 5:", 50, create_vector2f(565, 1750));
    create_btn_text(d, "Slot 6:", 50, create_vector2f(565, 1850));
    create_btn_text(d, "Slot 7:", 50, create_vector2f(565, 1950));
    create_btn_text(d, "Slot 8:", 50, create_vector2f(565, 2050));
    create_btn_text(d, "Slot 9:", 50, create_vector2f(565, 2150));
    create_text_setting_invent_right(d);
    create_button_setting_invent(d);
}

