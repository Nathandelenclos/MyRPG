/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** particules
*/

#include "../include/rpg.h"

void create_particles_texture(scene *d)
{
    texture *t = malloc(sizeof(texture));
    t->filename = "./assets/particles/move.png";
    t->name = "dust_particles1";
    t->rect = create_rect(48, 12, 0, 0);
    t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    put_in_list(&d->textures, t);
}
