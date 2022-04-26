/*
** EPITECH PROJECT, 2021
** MyRPG - utils
** File description:
** game obj
*/

#include "../include/rpg.h"

void create_obj_part_2(game_obj *obj)
{
    obj->display = 1;
    obj->clock = sfClock_create();
    obj->action = NULL;
    obj->event = NULL;
    obj->animate = NULL;
    obj->name = NULL;
}

game_obj *create_obj(
    scene *d, char *texture_name, sfIntRect rect, sfVector2f *vector
)
{
    game_obj *obj = malloc(sizeof(game_obj));
    obj->texture = get_texture(d, texture_name);
    obj->sprite = sfSprite_create();
    obj->rect = rect;
    obj->position = vector[0];
    obj->vector = vector[1];    
    create_obj_part_2(obj);
    sfSprite_setPosition(obj->sprite, vector[0]);
    if (obj->texture != NULL)
        sfSprite_setTexture(obj->sprite, obj->texture->texture, sfTrue);
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    return obj;
}

void set_scale(scene *d, sfSprite *sprite, float multiplier)
{
    sfVector2f resize = {multiplier, multiplier};
    sfSprite_setScale(sprite, resize);
}

void copy_objs(scene *copy, scene *paste, group grp)
{
    node *tmp = copy->objs;
    game_obj *data;
    while (tmp != NULL) {
        data = (game_obj *) tmp->data;
        if (data->grp == grp)
            put_in_list(&paste->objs, data);
        tmp = tmp->next;
    }
}
