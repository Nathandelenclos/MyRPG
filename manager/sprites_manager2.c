/*
** EPITECH PROJECT, 2021
** sprites_manager2.c
** File description:
** Created by Bastien Mazzolini
*/

#include "../include/rpg.h"

void scroll_object_by_name(scene *d, float x, float y, char *name)
{
    game_obj *obj = get_object(d, name);
    sfSprite_move(obj->sprite, create_vector2f(x, y));
}
