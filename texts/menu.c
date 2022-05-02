/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** display money
*/

#include "../include/rpg.h"

void create_btn_text(scene *d, char *name, int size, sfVector2f pos)
{
    text *t =
        create_text("./assets/fonts/motion-control.bold.otf", name,
            sfBlack, pos);
    sfText_setCharacterSize(t->text, size);
    put_in_list(&d->texts, t);
}
