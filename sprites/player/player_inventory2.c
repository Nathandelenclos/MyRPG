/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** player_inventory2
*/

#include "../../include/rpg.h"

void clear_inventory(inventory *inv)
{
    for (int i = 0; i < inv->size; ++i)
        inv->slot[i] = NULL;
}
