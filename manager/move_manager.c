/*
** EPITECH PROJECT, 2021
** MyRunner
** File description:
** move manager
*/

#include "../include/list.h"
#include "../include/rpg.h"
#include "../include/my.h"
#include <stdio.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

int is_integer(float f)
{
    if (f == (int) f)
        return 0;
    return 1;
}

int vector_is_around(sfVector2f v, sfVector2f obj, int margin)
{
    if (v.y + margin >= obj.y && v.y - margin <= obj.y &&
        v.x + margin >= obj.x && v.x - margin <= obj.x)
        return 1;
    return 0;
}

void move_manager(scene *d)
{
    game_obj *obj;
    text *t;
    node *tmp = d->objs;

    while (tmp != NULL) {
        obj = (game_obj *) tmp->data;
        if (obj->action != NULL)
            obj->action(obj, d);
        tmp = tmp->next;
    }
    tmp = d->texts;
    while (tmp != NULL) {
        t = (text *) tmp->data;
        if (t->animate != NULL)
            t->animate(t, d);
        tmp = tmp->next;
    }
}
