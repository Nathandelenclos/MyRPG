/*
** EPITECH PROJECT, 2021
** MyRPG - text
** File description:
** discuss text
*/

#include "../include/rpg.h"

void animate_dialog(text *t, scene *d)
{
    scene *play = get_scene(d, PLAY);
    game_obj *pnj_a =
        get_closer_object(play, get_object(play, "player"), PNJ_ENTITY);
    pnj *p = pnj_a->data;
    modify_string(d, t->string, (char *)DIALOG[p->dialog][p->step]);
}

void display_dialog(scene *d, pnj *p)
{
    sfVector2f pos = {(d->hub->mode.width / 2 - (723 / 2) * 2) + 40, 830};
    text *t =
        create_text("./assets/fonts/josefin_sans_light.ttf",
        (char *)DIALOG[p->dialog][p->step], sfBlack, pos);
    t->display = sfTrue;
    t->animate = animate_dialog;
    t->name = my_strdup("discuss");
    t->display = 5;
    sfText_setCharacterSize(t->text, 40);
    put_in_list(&d->texts, t);
}
