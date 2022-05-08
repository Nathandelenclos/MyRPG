/*
** EPITECH PROJECT, 2021
** second_quest.c
** File description:
** Created by Bastien Mazzolini
*/

#include "../include/rpg.h"

void second_quest2(player *p, inventory *inv, int nb_pink_slime)
{
    for (int i = 0; i < p->inventory->size; ++i) {
        if (inv->slot[i] != NULL && my_strcmp(inv->slot[i]->obj->name,
            "pink_slime") && nb_pink_slime < 4) {
            inv->slot[i] = NULL;
        }
    }
}

int seconds_quest(scene *d)
{
    d = get_scene(d, PLAY);
    player *p = get_object(d, "player")->data;
    int nb_pink_slime = 0;
    inventory *inv = p->inventory;
    for (int i = 0; i < p->inventory->size; ++i) {
        if (inv->slot[i] != NULL && my_strcmp(inv->slot[i]->obj->name,
            "pink_slime") && nb_pink_slime < 4) {
            nb_pink_slime++;
        }
    }
    if (nb_pink_slime <= 3) {
        second_quest2(p, inv, nb_pink_slime);
        return 1;
    }
    return 0;
}
