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

void create_slime(scene *d, int x, int y, slime_type type);
int create_sprite_map(scene *d);
int create_sprite_lb(scene *d, char *, int, int);
int create_sprite_rb(scene *d, char *, int, int);
int create_sprite_sb(scene *d, char *, int, int);
void create_player(scene *d);
void idle_player_animation(scene *d, game_obj *g);
void move_player_animation(scene *d, game_obj *g);
void hit_player_animation(scene *d, game_obj *g);

#endif
