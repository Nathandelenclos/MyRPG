/*
** EPITECH PROJECT, 2021
** MyRPG - Manager
** File description:
** Manager
*/

#include "../include/list.h"
#include "../include/rpg.h"
#include "../include/my.h"
#include <stdio.h>
#include <stdlib.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>

text *create_text(char *filename, char *string, sfColor color, sfVector2f v)
{
    text *t = malloc(sizeof(text));
    t->text = sfText_create();
    t->font = sfFont_createFromFile(filename);
    sfText_setFont(t->text, t->font);
    t->string = my_strdup(string);
    sfText_setString(t->text, t->string);
    t->color = color;
    sfText_setColor(t->text, t->color);
    t->position = v;
    sfText_setPosition(t->text, t->position);
    t->animate = NULL;
    t->zindex = 1;
    return t;
}

void modify_string(scene *d, char *before, char *after)
{
    text *t;
    node *tmp = d->texts;
    while (tmp != NULL) {
        t = (text *)tmp->data;
        if (my_strcmp(t->string, before)) {
            free(t->string);
            t->string = my_strdup(after);
            sfText_setString(t->text, t->string);
        }
        tmp = tmp->next;
    }
}

void text_manager(scene *d)
{
    text *t;
    node *tmp = d->texts;
    while (tmp != NULL) {
        t = (text *)tmp->data;
        sfRenderWindow_drawText(d->hub->window, t->text, NULL);
        tmp = tmp->next;
    }
}
