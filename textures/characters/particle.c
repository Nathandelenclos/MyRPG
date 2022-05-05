/*
** EPITECH PROJECT, 2021
** MyRPG - texture
** File description:
** create partlicle texture
*/

#include "../../include/rpg.h"

void create_particle_texture(scene *d)
{
    texture *t = malloc(sizeof(texture));
    t->filename = "./assets/particles/move.png";
    t->name = "particle";
    t->rect = create_simple_rect(48, 12);
    t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    put_in_list(&d->textures, t);
}
