/*
** EPITECH PROJECT, 2021
** four_quest.c
** File description:
** Created by Bastien Mazzolini
*/

#include "../include/rpg.h"

void four_quest2(player *p, inventory *inv, int nb)
{
    for (int i = 0; i < p->inventory->size; ++i) {
        if (inv->slot[i] != NULL && my_strcmp(inv->slot[i]->obj->name,
            "blue_slime") && nb < 5) {
            inv->slot[i] = NULL;
        }
    }
}

int four_quest(scene *d)
{
    d = get_scene(d, PLAY);
    player *p = get_object(d, "player")->data;
    int nb_blue_slime = 0;
    inventory *inv = p->inventory;
    for (int i = 0; i < p->inventory->size; ++i) {
        if (inv->slot[i] != NULL && my_strcmp(inv->slot[i]->obj->name,
            "blue_slime") && nb_blue_slime < 5) {
            nb_blue_slime++;
        }
    }
    if (nb_blue_slime <= 4) {
        four_quest2(p, inv, nb_blue_slime);
        return 1;
    }
    return 0;
}
