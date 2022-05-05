/*
** EPITECH PROJECT, 2021
** event_change_input_setting.c
** File description:
** Created by Bastien Mazzolini
*/

#include "../../include/rpg.h"

int input_handling(sfKeyCode code, controls *c, scene *s)
{
    if (TOUCH[code] == NULL) {
        switch_scene(s, SETTINGS_ERROR);
        return 0;
    }
    if (c->up == code || c->right == code || c->down == code ||
    c->left == code || c->attack == code || c->interact == code ||
    c->menu == code || c->run == code || c->screen == code || c->slot1 == code
    || c->slot2 == code || c->slot3 == code || c->slot4 == code ||
    c->slot5 == code || c->slot6 == code || c->slot7 == code ||
    c->slot8 == code || c->slot9 == code) {
        switch_scene(s, SETTINGS_ERROR);
        return 0;
    }
    switch_scene(s, SETTINGS);
    return 1;
}
