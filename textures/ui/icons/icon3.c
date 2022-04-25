/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** icon3
*/

#include "../include/rpg.h"

void create_icon_trophy_texture(scene *d)
{
    texture *t = malloc(sizeof(texture));
    t->filename = "./assets/ui/icons/icon_trophy.png";
    t->name = "icon_trophy";
    t->rect = create_rect(8, 9, 0, 0);
    t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    put_in_list(&d->textures, t);
}

void create_icon_twitter_texture(scene *d)
{
    texture *t = malloc(sizeof(texture));
    t->filename = "./assets/ui/icons/icon_twitter.png";
    t->name = "icon_twitter";
    t->rect = create_rect(10, 8, 0, 0);
    t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    put_in_list(&d->textures, t);
}

void create_icon_watchad_texture(scene *d)
{
    texture *t = malloc(sizeof(texture));
    t->filename = "./assets/ui/icons/icon_watchad.png";
    t->name = "icon_watchad";
    t->rect = create_rect(17, 8, 0, 0);
    t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    put_in_list(&d->textures, t);
}

void create_icon_youtube_texture(scene *d)
{
    texture *t = malloc(sizeof(texture));
    t->filename = "./assets/ui/icons/icon_youtube.png";
    t->name = "icon_youtube";
    t->rect = create_rect(8, 7, 0, 0);
    t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    put_in_list(&d->textures, t);
}
