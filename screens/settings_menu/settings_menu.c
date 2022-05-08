/*
** EPITECH PROJECT, 2021
** MyRPG
** File descriptiofn:
** Screen
*/

#include "../../include/rpg.h"

void events_settings(scene *d, sfEvent event)
{
    events_manage(d, event);
    switch (event.type) {
    case sfEvtKeyPressed:
        if (event.key.code == sfKeyEscape)
            d->hub->state = START;
        break;
    case sfEvtMouseWheelMoved:
        scroll_object_by_grp(d, 0, event.mouseWheel.delta * 10, SCROLL_BTN);
        scroll_object_by_grp(d, 0, event.mouseWheel.delta * 10, SCROLL_BTN_IN);
        scroll_text_grp(d, 0, event.mouseWheel.delta * 10, SCROLL_BTN_IN);
        break;
    }
}

void settings_screen(scene *data)
{
    sprites_manager(data);
    move_manager(data);
    time_manager(data);
}

void create_sprite_settings(scene *d)
{
    d->textures = get_scene(d, START)->textures;
    d->sounds = get_scene(d, START)->sounds;
    create_settings_menu_sprite(d);
    create_settings_hud_sprite(d);
    create_btn_text(d, "   DONE", create_text_id_struct(95, UI, 4), create_vector2f(822.5, 945));
    create_sprite_lb(d, "white_lb",
    create_btn_param(create_vector2f(822.5, 970), 2, 5, HOME_BTN), "   DONE");
    create_btn_text(d, my_int_to_str(d->hub->s->volume), create_text_id_struct(50, UI, 3),
        create_vector2f(613, 80));
    create_btn_text(d, "VOLUME:", create_text_id_struct(50, UI, 3), create_vector2f(565, 20));
    create_sprite_sb(d, "white_plus",
     create_btn_param(create_vector2f(665, 80), 2, 4, HOME_BTN),
        my_int_to_str(d->hub->s->volume));
    create_sprite_sb(d, "white_minus",
     create_btn_param(create_vector2f(535, 80), 2, 4, HOME_BTN),
        my_int_to_str(d->hub->s->volume));
    create_sprite_sb(d, "white_sb",
     create_btn_param(create_vector2f(600, 80), 2, 4, HOME_BTN),
        my_int_to_str(d->hub->s->volume));
    create_btn_text(d, my_int_to_str(d->hub->s->fps), create_text_id_struct(50, UI, 3),
        create_vector2f(613, 80));
    create_btn_text(d, "FPS:", create_text_id_struct(50, UI, 3), create_vector2f(1265, 20));
    create_sprite_sb(d, "white_plus",
     create_btn_param(create_vector2f(1365, 80), 2, 4, HOME_BTN),
        my_int_to_str(d->hub->s->fps));
    create_sprite_sb(d, "white_minus",
     create_btn_param(create_vector2f(1235, 80), 2, 4, HOME_BTN),
        my_int_to_str(d->hub->s->fps));
    create_sprite_sb(d, "white_sb",
     create_btn_param(create_vector2f(1300, 80), 2, 4, HOME_BTN),
        my_int_to_str(d->hub->s->fps));
    create_button_setting(d);
}

void data_settings(screen *screen1)
{
    scene *d = create_scene(screen1, SETTINGS);
    d->screen = settings_screen;
    d->event = events_settings;
    create_sprite_settings(d);
    put_in_list(&screen1->datas, d);
}
