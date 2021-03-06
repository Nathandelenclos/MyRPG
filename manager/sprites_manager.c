/*
** EPITECH PROJECT, 2021
** MyRPG - Manager
** File description:
** main manager sprites
*/

#include "../include/rpg.h"

game_obj *get_closer_object(scene *d, game_obj *obj, group grp)
{
    node *tmp = d->objs;
    game_obj *obj_tmp = NULL;
    game_obj *result = NULL;
    float distance = -1;

    while (tmp != NULL) {
        obj_tmp = (game_obj *) tmp->data;
        if (obj_tmp->grp != grp) {
            tmp = tmp->next;
            continue;
        }
        if (distance < 0 || get_distance(obj, obj_tmp) < distance) {
            distance = get_distance(obj, obj_tmp);
            result = obj_tmp;
        }
        tmp = tmp->next;
    }
    return result;
}

game_obj *get_object(scene *d, char *name)
{
    node *tmp = d->objs;
    while (tmp != NULL) {
        game_obj *obj = (game_obj *) tmp->data;
        if (my_strcmp(obj->name, name))
            return obj;
        tmp = tmp->next;
    }
    return NULL;
}

void scroll_object_by_name(scene *d, float x, float y, char *name)
{
    game_obj *obj = get_object(d, name);
    sfSprite_move(obj->sprite, create_vector2f(x, y));
}

void scroll_object_by_grp(scene *d, float x, float y, group grp)
{
    node *tmp = d->objs;
    while (tmp != NULL) {
        game_obj *obj = (game_obj *) tmp->data;
        if (obj->grp == grp) {
            sfVector2f v = {x, y};
            sfSprite_move(obj->sprite, v);
        }
        tmp = tmp->next;
    }
}

void sprites_manager(scene *d)
{
    game_obj *obj = NULL;
    node *tmp = d->objs;
    int z_index = 1;
    d->hub->entity_load = 0;

    while (tmp != NULL) {
        obj = (game_obj *) tmp->data;
        if (obj->display == z_index && is_on_window(obj, d)) {
            sfRenderWindow_drawSprite(d->hub->window, obj->sprite, NULL);
            d->hub->entity_load++;
        }
        draw_text_with_index(d, z_index);
        if (tmp->next == NULL && z_index <= 5) {
            z_index++;
            tmp = d->objs;
        }
        tmp = tmp->next;
    }
}
