/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** icon2
*/

#include "../include/rpg.h"

void create_icon_questionmark_texture(scene *d)
{
    texture *t = malloc(sizeof(texture));
    t->filename = "./assets/ui/icons/icon_questionmark.png";
    t->name = "icon_questionmark";
    t->rect = create_rect(6, 9, 0, 0);
    t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    put_in_list(&d->textures, t);
}

void create_icon_ranking_texture(scene *d)
{
    texture *t = malloc(sizeof(texture));
    t->filename = "./assets/ui/icons/icon_ranking.png";
    t->name = "icon_ranking";
    t->rect = create_rect(11, 7, 0, 0);
    t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    put_in_list(&d->textures, t);
}

void create_icon_settings_texture(scene *d)
{
    texture *t = malloc(sizeof(texture));
    t->filename = "./assets/ui/icons/icon_settings.png";
    t->name = "icon_settings";
    t->rect = create_rect(10, 10, 0, 0);
    t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    put_in_list(&d->textures, t);
}

void create_icon_triangle_texture(scene *d)
{
    texture *t = malloc(sizeof(texture));
    t->filename = "./assets/ui/icons/icon_triangle.png";
    t->name = "icon_triangle";
    t->rect = create_rect(4, 7, 0, 0);
    t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    put_in_list(&d->textures, t);
}
