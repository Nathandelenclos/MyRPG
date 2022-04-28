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

sfVector2f create_vector2f(int x, int y)
{
    sfVector2f vec = {x, y};
    return vec;
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
}
