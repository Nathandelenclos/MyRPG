/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** utils2
*/

#include "../include/rpg.h"

void switch_scene(scene *d, state s)
{
    scene *new = get_scene(d, s);
    if (new->active != NULL)
        new->active(d, new);
    d->hub->state = s;
}

float get_distance(game_obj *first, game_obj *seconds)
{
    if (first == NULL || seconds == NULL)
        return -1;
    sfVector2f pos1 = sfSprite_getPosition(first->sprite);
    sfVector2f pos2 = sfSprite_getPosition(seconds->sprite);
    double rx =
        (pos1.x +
            ((first->rect.width / 2.0) * sfSprite_getScale(first->sprite).x))
            -
            (pos2.x + ((seconds->rect.width / 2.0) *
                sfSprite_getScale(seconds->sprite).x));
    double ry =
        (pos1.y +
            ((first->rect.height / 2.0) * sfSprite_getScale(first->sprite).y))
            -
            (pos2.y + ((seconds->rect.height / 2.0) *
                sfSprite_getScale(seconds->sprite).y));
    float range = (float) sqrt(rx * rx + ry * ry);
    return (range);
}

text *search_for_n_text(scene *s, char *name, int n)
{
    text *t;
    node *tmp = s->texts;
    while (tmp != NULL) {
        t = (text *) tmp->data;
        if (t != NULL && my_strncmp(t->string, name, n))
            return t;
        tmp = tmp->next;
    }
    return NULL;
}

text *get_text(scene *d, char *name)
{
    node *tmp = d->texts;
    text *data = NULL;
    while (tmp != NULL) {
        data = (text *) tmp->data;
        if (my_strcmp(data->name, name))
            return data;
        tmp = tmp->next;
    }
    return NULL;
}
