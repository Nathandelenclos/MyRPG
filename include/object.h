/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** type of game object
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "list.h"
#include "my.h"
#include "enum.h"
#include "struct.h"

#ifndef GAME_OBJ_H
    #define GAME_OBJ_H

//Objects
void create_slime(scene *d, int x, int y, slime_type type);
int create_sprite_lb(scene *d, char *, sfVector2f, char *);
int create_sprite_rb(scene *d, char *, int, int);
int create_sprite_sb(scene *d, char *, int, int);
int create_sprite_menu(scene *d);

//Text
void create_btn_text(scene *d, char *, int);

#endif
