/*
** EPITECH PROJECT, 2021
** MyRPG - utils
** File description:
** utils function
*/

#include "../include/rpg.h"

int get_next_index(node *list)
{
    int i = 0;
    node *tmp = list;

    for (; tmp != NULL; ++i)
        tmp = tmp->next;
    return i;
}

sfVector2f create_vector2f(float x, float y)
{
    sfVector2f v = {x, y};
    return v;
}

void switch_scene(scene *d, state s)
{
    scene *new = get_scene(d, s);
    if (new->active != NULL)
        new->active(d, new);
    d->hub->state = s;
}

game_obj *get_object(scene *d, char *name)
{
    game_obj *obj;
    node *tmp = d->objs;
    while (tmp != NULL) {
        obj = (game_obj *) tmp->data;
        if (my_strcmp(name, obj->name))
            return obj;
        tmp = tmp->next;
    }
    return NULL;
}

button *create_button_data(char *text, scene *s, sfVector2f pos)
{
    button *b = malloc(sizeof(button));
    b->t = search_for_text(s, text);
    b->pos = pos;
    return b;
}

text *search_for_text(scene *s, char *name)
{
    text *t;
    node *tmp = s->texts;
    while (tmp != NULL) {
        t = (text *)tmp->data;
        if (t != NULL && my_strcmp(t->string, name))
            return t;
        tmp = tmp->next;
    }
    return NULL;
}

text *search_for_n_text(scene *s, char *name, int n)
{
    text *t;
    node *tmp = s->texts;
    while (tmp != NULL) {
        t = (text *)tmp->data;
        if (t != NULL && my_strncmp(t->string, name, n))
            return t;
        tmp = tmp->next;
    }
    return NULL;
}
