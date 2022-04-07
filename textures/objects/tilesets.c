/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** tilesets
*/

#include "../include/rpg.h"

void create_decor8x8_texture(scene *d)
{
    texture *t = malloc(sizeof(texture));
    t->filename = "./assets/tilesets/decor_8x8.png";
    t->name = "decor8x8";
    t->rect = create_rect(32, 32, 0, 0);
    t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    put_in_list(&d->textures, t);
}

void create_decor16x16_texture(scene *d)
{
    texture *t = malloc(sizeof(texture));
    t->filename = "./assets/tilesets/decor_16x16.png";
    t->name = "decor16x16";
    t->rect = create_rect(64, 80, 0, 0);
    t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    put_in_list(&d->textures, t);
}

void create_fences_texture(scene *d)
{
    texture *t = malloc(sizeof(texture));
    t->filename = "./assets/tilesets/fences.png";
    t->name = "fences";
    t->rect = create_rect(64, 64, 0, 0);
    t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    put_in_list(&d->textures, t);
}

void create_plains_texture(scene *d)
{
    texture *t = malloc(sizeof(texture));
    t->filename = "./assets/tilesets/plains.png";
    t->name = "plains";
    t->rect = create_rect(96, 192, 0, 0);
    t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    put_in_list(&d->textures, t);
}

void create_tilesets_texture(scene *d)
{
    create_decor8x8_texture(d);
    create_decor16x16_texture(d);
    create_fences_texture(d);
    create_plains_texture(d);
}
