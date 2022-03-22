/*
** EPITECH PROJECT, 2021
** MyRPG - texture
** File description:
** dwarf texture
*/

#include "../include/list.h"
#include "../include/rpg.h"
#include <stdlib.h>
#include <SFML/Graphics.h>

void create_dwarf_texture(scene *d)
{
    texture *t = malloc(sizeof(texture));
    t->filename = "./assets/dwarf_sheet.png";
    t->name = "dwarf";
    t->rect = create_rect(512, 32, 0, 32);
    t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    put_in_list(&d->textures, t);
}