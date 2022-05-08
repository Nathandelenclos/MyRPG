/*
** EPITECH PROJECT, 2021
** MyRPG - quest
** File description:
** create quest of simon
*/

#include "../include/rpg.h"

int count_max_quest(void)
{
    int i = 0;
    for (; quests[i] != 0; ++i);
    return i;
}

int first_quest(scene *d)
{
    d = get_scene(d, PLAY);
    player *p = get_object(d, "player")->data;
    inventory *inv = p->inventory;
    for (int i = 0; i < p->inventory->size; ++i)
        if (inv->slot[i] != NULL && my_strcmp(inv->slot[i]->obj->name, "apple")) {
            inv->slot[i] = NULL;
            return 1;
        }
    return 0;
}

int seconds_quest(scene *d)
{
    d = get_scene(d, PLAY);
    player *p = get_object(d, "player")->data;
    inventory *inv = p->inventory;
    for (int i = 0; i < p->inventory->size; ++i)
        if (inv->slot[i] != NULL && inv->slot[i]->obj->grp == ENEMY) {
            inv->slot[i] = NULL;
            return 1;
        }
    return 0;
}