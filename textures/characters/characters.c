/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** characters
*/

#include "../include/rpg.h"

void create_skeleton_texture(scene *d)
{
    texture *t = malloc(sizeof(texture));
    t->filename = "./assets/characters/skeleton.png";
    t->name = "skeleton";
    t->rect = create_rect(384, 320, 0, 0);
    t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    put_in_list(&d->textures, t);
}

void create_slime_texture(scene *d)
{
    texture *t = malloc(sizeof(texture));
    t->filename = "./assets/characters/slime.png";
    t->name = "slime";
    t->rect = create_rect(224, 160, 0, 0);
    t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    put_in_list(&d->textures, t);
}

void create_player_texture(scene *d)
{
    texture *t = malloc(sizeof(texture));
    t->filename = "./assets/characters/player.png";
    t->name = "player";
    t->rect = create_rect(288, 240, 0, 0);
    t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    put_in_list(&d->textures, t);
}

void create_characters_texture(scene *d)
{
    create_skeleton_texture(d);
    create_slime_texture(d);
    create_player_texture(d);
}
