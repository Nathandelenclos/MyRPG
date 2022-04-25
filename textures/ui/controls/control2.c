/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** controls2
*/

#include "../include/rpg.h"

void create_small_arrow_down_texture(scene *d)
{
    texture *t = malloc(sizeof(texture));
    t->filename = "./assets/ui/controls/small_arrow_down.png";
    t->name = "small_arrow_down";
    t->rect = create_rect(8, 8, 0, 0);
    t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    put_in_list(&d->textures, t);
}

void create_small_arrow_up_texture(scene *d)
{
    texture *t = malloc(sizeof(texture));
    t->filename = "./assets/ui/controls/small_arrow_up.png";
    t->name = "small_arrow_up";
    t->rect = create_rect(8, 8, 0, 0);
    t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    put_in_list(&d->textures, t);
}

void create_small_arrow_left_texture(scene *d)
{
    texture *t = malloc(sizeof(texture));
    t->filename = "./assets/ui/controls/small_arrow_left.png";
    t->name = "small_arrow_left";
    t->rect = create_rect(8, 8, 0, 0);
    t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    put_in_list(&d->textures, t);
}

void create_small_arrow_right_texture(scene *d)
{
    texture *t = malloc(sizeof(texture));
    t->filename = "./assets/ui/controls/small_arrow_right.png";
    t->name = "small_arrow_right";
    t->rect = create_rect(8, 8, 0, 0);
    t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    put_in_list(&d->textures, t);
}

void create_controls_texture(scene *d)
{
    create_arrow_right_texture(d);
    create_arrow_left_texture(d);
    create_arrow_down_texture(d);
    create_arrow_up_texture(d);
    create_small_arrow_right_texture(d);
    create_small_arrow_left_texture(d);
    create_small_arrow_down_texture(d);
    create_small_arrow_up_texture(d);
}
