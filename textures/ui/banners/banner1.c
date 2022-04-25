/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** banner1
*/

#include "../include/rpg.h"

void create_blue_banner_texture(scene *d)
{
    texture *t = malloc(sizeof(texture));
    t->filename = "./assets/ui/Banners/Banner_Blue.png";
    t->name = "blue_banner";
    t->rect = create_rect(13, 17, 0, 0);
    t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    put_in_list(&d->textures, t);
}

void create_green_banner_texture(scene *d)
{
    texture *t = malloc(sizeof(texture));
    t->filename = "./assets/ui/Banners/Banner_Green.png";
    t->name = "green_banner";
    t->rect = create_rect(13, 17, 0, 0);
    t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    put_in_list(&d->textures, t);
}

void create_purple_banner_texture(scene *d)
{
    texture *t = malloc(sizeof(texture));
    t->filename = "./assets/ui/Banners/Banner_Purple.png";
    t->name = "purple_banner";
    t->rect = create_rect(13, 17, 0, 0);
    t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    put_in_list(&d->textures, t);
}

void create_red_banner_texture(scene *d)
{
    texture *t = malloc(sizeof(texture));
    t->filename = "./assets/ui/Banners/Banner_Red.png";
    t->name = "red_banner";
    t->rect = create_rect(13, 17, 0, 0);
    t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    put_in_list(&d->textures, t);
}

void create_banners_texture(scene *d)
{
    create_blue_banner_texture(d);
    create_green_banner_texture(d);
    create_purple_banner_texture(d);
    create_red_banner_texture(d);
    create_white_banner_texture(d);
    create_wreath_banner_texture(d);
}
