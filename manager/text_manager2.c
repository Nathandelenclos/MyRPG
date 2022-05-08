/*
** EPITECH PROJECT, 2021
** texxt_manager2.c
** File description:
** Created by Bastien Mazzolini
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
    t->display = sfTrue;
    sfText_setPosition(t->text, t->position);
    t->animate = NULL;
    t->display = 1;
    t->name = my_strdup(string);
    return t;
}
