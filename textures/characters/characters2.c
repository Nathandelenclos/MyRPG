/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** characters2
*/

#include "../include/rpg.h"

void create_player_mirror_texture(scene *d)
{
    texture *t = malloc(sizeof(texture));
    t->filename = "./assets/characters/player_mirror.png";
    t->name = "player_mirror";
    t->rect = create_rect(288, 240, 0, 0);
    t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    put_in_list(&d->textures, t);
}
