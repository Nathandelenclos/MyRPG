/*
** EPITECH PROJECT, 2021
** MyRPG - utils
** File description:
** create position
*/

#include "../include/rpg.h"

sfVector2f *init_inventory_pos_places_p(void)
{
    sfVector2f *pos = malloc(sizeof(sfVector2f) * 9);
    for (int i = 0; i < 9; i++) {
        pos[i].x = 685 + i * 60.5;
        pos[i].y = 1015;
    }
    return (pos);
}

sfVector2f *init_inventory_pos_places_c(void)
{
    sfVector2f *pos = malloc(sizeof(sfVector2f) * 36);
    for (int i = 0; i < 36; i++) {
        if (i >= 0 && i < 9) {
            pos[i].x = 275 + i * 157;
            pos[i].y = 356 - 140;
        }
        if (i >= 9 && i < 18) {
            pos[i].x = 275 + (i - 9) * 157;
            pos[i].y = 356 + 157 - 140;
        }
        if (i >= 18 && i < 27) {
            pos[i].x = 275 + (i - 18) * 157;
            pos[i].y = 356 + 157 * 2 - 140;
        }
        if (i >= 27 && i < 36) {
            pos[i].x = 275 + (i - 27) * 157;
            pos[i].y = 869 - 140;
        }
    }
    return (pos);
}

int get_free_space_inv(inventory *inv)
{
    int i = 0;
    for (; inv->slot[i] != NULL; ++i);
    return i;
}
