/*
** EPITECH PROJECT, 2021
** MyRPG - utils
** File description:
** quest utils
*/

#include "../include/rpg.h"

void check_quest(scene *s, pnj *p)
{
    if (count_max_quest() <= p->dialog)
        return;
    if (p->step == 2) {
        if (count_max_quest() > (p->dialog + 1)) {
            p->step = 0;
            p->dialog++;
            p->quest = quests[p->dialog];
        }
    } else if (p->step == 0 || p->step == 1)
        p->step = p->quest(s) ? 2 : 1;
}
