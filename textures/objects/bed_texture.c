/*
** EPITECH PROJECT, 2021
** bed_texture.c
** File description:
** Created by Bastien Mazzolini
*/

#include "../../include/rpg.h"

void create_bed_texture(scene *d)
{
    put_in_list(&d->textures, create_texture("./assets/objects/objects.png",
        "bed", create_rect(16, 30, 176, 32)));
}
