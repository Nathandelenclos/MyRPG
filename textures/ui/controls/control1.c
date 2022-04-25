/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** controls1
*/

#include "../include/rpg.h"

void create_arrow_down_texture(scene *d)
{
    texture *t = malloc(sizeof(texture));
    t->filename = "./assets/ui/controls/arrow_down.png";
    t->name = "arrow_down";
    t->rect = create_rect(12, 14, 0, 0);
    t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    put_in_list(&d->textures, t);
}

void create_arrow_up_texture(scene *d)
{
    texture *t = malloc(sizeof(texture));
    t->filename = "./assets/ui/controls/arrow_up.png";
    t->name = "arrow_up";
    t->rect = create_rect(12, 14, 0, 0);
    t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    put_in_list(&d->textures, t);
}

void create_arrow_left_texture(scene *d)
{
    texture *t = malloc(sizeof(texture));
    t->filename = "./assets/ui/controls/arrow_left.png";
    t->name = "arrow_left";
    t->rect = create_rect(13, 13, 0, 0);
    t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    put_in_list(&d->textures, t);
}

void create_arrow_right_texture(scene *d)
{
    texture *t = malloc(sizeof(texture));
    t->filename = "./assets/ui/controls/arrow_right.png";
    t->name = "arrow_right";
    t->rect = create_rect(13, 13, 0, 0);
    t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    put_in_list(&d->textures, t);
}
