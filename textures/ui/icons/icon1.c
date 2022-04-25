/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** icon1
*/

#include "../include/rpg.h"

void create_icon_exclamationmark_texture(scene *d)
{
    texture *t = malloc(sizeof(texture));
    t->filename = "./assets/ui/icons/icon_exclamationmark.png";
    t->name = "icon_exclamationmark";
    t->rect = create_rect(3, 9, 0, 0);
    t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    put_in_list(&d->textures, t);
}

void create_icon_facebook_texture(scene *d)
{
    texture *t = malloc(sizeof(texture));
    t->filename = "./assets/ui/icons/icon_facebook.png";
    t->name = "icon_facebook";
    t->rect = create_rect(6, 9, 0, 0);
    t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    put_in_list(&d->textures, t);
}

void create_icon_house_texture(scene *d)
{
    texture *t = malloc(sizeof(texture));
    t->filename = "./assets/ui/icons/icon_house.png";
    t->name = "icon_house";
    t->rect = create_rect(11, 7, 0, 0);
    t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    put_in_list(&d->textures, t);
}

void create_icon_human_texture(scene *d)
{
    texture *t = malloc(sizeof(texture));
    t->filename = "./assets/ui/icons/icon_human.png";
    t->name = "icon_human";
    t->rect = create_rect(7, 10, 0, 0);
    t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    put_in_list(&d->textures, t);
}

void create_icons_texture(scene *d)
{
    create_icon_exclamationmark_texture(d);
    create_icon_facebook_texture(d);
    create_icon_house_texture(d);
    create_icon_human_texture(d);
}
