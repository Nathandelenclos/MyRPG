/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** chest_inventory
*/

#include "../../include/rpg.h"

void create_chest_inventory_texture(scene *d)
{
    texture *t = malloc(sizeof(texture));
    t->filename = "./assets/ui/chest_inventory.png";
    t->name = "chest_inventory";
    t->rect = create_rect(914, 862, 0, 0);
    t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    put_in_list(&d->textures, t);
}
