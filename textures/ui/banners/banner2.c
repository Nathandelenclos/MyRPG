/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** banner2
*/

#include "../include/rpg.h"

void create_white_banner_texture(scene *d)
{
    texture *t = malloc(sizeof(texture));
    t->filename = "./assets/ui/Banners/Banner_White.png";
    t->name = "white_banner";
    t->rect = create_rect(13, 17, 0, 0);
    t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    put_in_list(&d->textures, t);
}

void create_wreath_banner_texture(scene *d)
{
    texture *t = malloc(sizeof(texture));
    t->filename = "./assets/ui/Banners/Banner_Wreath.png";
    t->name = "wreath_banner";
    t->rect = create_rect(17, 17, 0, 0);
    t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    put_in_list(&d->textures, t);
}
