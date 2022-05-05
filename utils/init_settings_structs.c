/*
** EPITECH PROJECT, 2021
** MyRPG - FREE
** File description:
** free
*/

#include "../include/rpg.h"

void init_slot(controls *c)
{
    c->slot1 = sfKeyNum1;
    c->slot2 = sfKeyNum2;
    c->slot3 = sfKeyNum3;
    c->slot4 = sfKeyNum4;
    c->slot5 = sfKeyNum5;
    c->slot6 = sfKeyNum6;
    c->slot7 = sfKeyNum7;
    c->slot8 = sfKeyNum8;
    c->slot9 = sfKeyNum9;
}

controls *init_controls(void)
{
    controls *c = malloc(sizeof(controls));

    c->up = sfKeyUp;
    c->down = sfKeyDown;
    c->left = sfKeyLeft;
    c->right = sfKeyRight;
    c->run = sfKeyLShift;
    c->interact = sfKeyE;
    c->attack = sfKeyA;
    c->menu = sfKeyEscape;
    c->screen = sfKeyF4;
    init_slot(c);
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
