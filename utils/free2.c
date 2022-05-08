/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** free2
*/

#include "../include/rpg.h"

void free_game(screen *hub)
{
    free_list(hub->datas, (void(*)(void *))free_scene);
    sfClock_destroy(hub->clock);
    free(hub);
}
