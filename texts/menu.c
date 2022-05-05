/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** display money
*/

#include "../include/rpg.h"

void create_btn_text(scene *d, char *name, text_id *id, sfVector2f pos)
{
    text *t =
        create_text("./assets/fonts/motion-control.bold.otf", name,
            sfBlack, pos);
    t->grp = id->grp;
    t->display = id->zindex;
    sfText_setCharacterSize(t->text, id->size);
    put_in_list(&d->texts, t);
}
