/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** walls
*/

#include "../include/rpg.h"

void create_wall_texture(scene *d)
{
    texture *t = malloc(sizeof(texture));
    t->filename = "./assets/tilesets/walls/walls.png";
    t->name = "walls";
    t->rect = create_rect(128, 128, 0, 0);
    t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    put_in_list(&d->textures, t);
}

void create_wooden_door_texture(scene *d)
{
    texture *t = malloc(sizeof(texture));
    t->filename = "./assets/tilesets/walls/wooden_door.png";
    t->name = "wooden_door";
    t->rect = create_rect(32, 16, 0, 0);
    t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    put_in_list(&d->textures, t);
}

void create_wooden_door_b_texture(scene *d)
{
    texture *t = malloc(sizeof(texture));
    t->filename = "./assets/tilesets/walls/wooden_door_b.png";
    t->name = "wooden_door_b";
    t->rect = create_rect(32, 16, 0, 0);
    t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    put_in_list(&d->textures, t);
}

void create_walls_texture(scene *d)
{
    create_wall_texture(d);
    create_wooden_door_texture(d);
    create_wooden_door_b_texture(d);
}
