/*
** EPITECH PROJECT, 2021
** MyRpg - textures
** File description:
** Long buttons
*/

#include "../../include/rpg.h"

void create_menu(scene *d)
{
    put_in_list(&d->textures,
    create_texture("./assets/ui/menu_sprites.png",
    "menu", create_rect(8400, 450, 0, 0)));
}

int create_menu_texture(scene *d)
{
    create_menu(d);
    return 0;
}
