/*
** EPITECH PROJECT, 2021
** MyRPG - FREE
** File description:
** free
*/

#include "../include/rpg.h"

controls *init_controls(void)
{
    controls *c = malloc(sizeof(controls));
    c->up = sfKeyUp;
    c->down = sfKeyDown;
    c->left = sfKeyLeft;
    c->right = sfKeyRight;
    c->interact = sfKeyE;
    c->slots = sfKeyNum1, sfKeyNum2, sfKeyNum3, sfKeyNum4, sfKeyNum5,
        sfKeyNum6, sfKeyNum7, sfKeyNum8, sfKeyNum9;
    return c;
}

settings *init_settings_struct(void)
{
    settings *s = malloc(sizeof(settings));
    s->volume = 25;
    s->fps = 120;
    s->c = init_controls();
    return s;
}
