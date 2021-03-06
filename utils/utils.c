/*
** EPITECH PROJECT, 2021
** MyRPG - utils
** File description:
** utils function
*/

#include "../include/rpg.h"

btn_param *create_btn_param(sfVector2f pos, int zindex, int scale, group grp)
{
    btn_param *p = malloc(sizeof(btn_param));
    p->pos = pos;
    p->zindex = zindex;
    p->scale = scale;
    p->grp = grp;
    return p;
}

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
