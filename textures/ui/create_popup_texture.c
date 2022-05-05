/*
** EPITECH PROJECT, 2021
** MyRpg - textures
** File description:
** Long buttons
*/

#include "../../include/rpg.h"

void create_popup(scene *d)
{
    put_in_list(&d->textures,
    create_texture("./assets/ui/error_popup.png",
    "popup", create_rect(723, 251, 0, 0)));
}
