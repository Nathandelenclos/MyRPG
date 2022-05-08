/*
** EPITECH PROJECT, 2021
** third_quest.c
** File description:
** Created by Bastien Mazzolini
*/

#include "../include/rpg.h"

void third_quest2(player *p, inventory *inv, int nb)
{
    for (int i = 0; i < p->inventory->size; ++i) {
        if (inv->slot[i] != NULL && my_strcmp(inv->slot[i]->obj->name,
            "apple") && nb < 6) {
            inv->slot[i] = NULL;
        }
    }
}

int third_quest(scene *d)
{
    d = get_scene(d, PLAY);
    player *p = get_object(d, "player")->data;
    int nb_apple = 0;
    inventory *inv = p->inventory;
    for (int i = 0; i < p->inventory->size; ++i) {
        if (inv->slot[i] != NULL && my_strcmp(inv->slot[i]->obj->name,
            "apple") && nb_apple < 6) {
            nb_apple++;
        }
    }
    if (nb_apple <= 5) {
        third_quest2(p, inv, nb_apple);
        return 1;
    }
    return 0;
}
