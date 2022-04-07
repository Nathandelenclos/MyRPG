/*
** EPITECH PROJECT, 2021
** MyRPG - Manager
** File description:
** time manager
*/

#include "../include/my.h"
#include "../include/list.h"
#include "../include/rpg.h"
#include <stdio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

void time_manager(scene *d)
{
    game_obj *obj;
    node *tmp = d->objs;
    while (tmp != NULL) {
        obj = (game_obj *) tmp->data;
        if (obj->animate != NULL) {
            obj->animate(d, obj);
        }
        tmp = tmp->next;
    }
}
