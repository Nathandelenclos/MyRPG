/*
** EPITECH PROJECT, 2021
** MyRPG - Texture
** File description:
** texture of map
*/

#include "../include/rpg.h"

void create_maps_textures(scene *d)
{
    put_in_list(&d->textures, create_texture("./assets/unknown.png", "maps",
        create_rect(787, 775, 0, 0)));
}
