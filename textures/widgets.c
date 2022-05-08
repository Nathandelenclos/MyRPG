/*
** EPITECH PROJECT, 2021
** MyDefender
** File description:
** main menu texture
*/

#include "../include/rpg.h"

void create_widget_texture(scene *d)
{
    texture *t = malloc(sizeof(texture));
    t->filename = "./assets/widget_sprites.png";
    t->name = "widgets";
    t->rect = create_rect(7080, 479, 0, 0);
    t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    put_in_list(&d->textures, t);
}
