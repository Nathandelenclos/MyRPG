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
#include "object.h"

#ifndef GAME_OBJ_TYPE_H
    #define GAME_OBJ_TYPE_H

// SLIME

typedef struct {
    void (*idle)(scene *, game_obj *);
    void (*move)(scene *, game_obj *);
    void (*jump)(scene *, game_obj *);
    void (*hit)(scene *, game_obj *);
    void (*destroy)(scene *, game_obj *);
    slime_state state;
    sfTime time;
    sfTime old_time_an;
    int life;
    int speed;
} slime;

void destroy_animate_slime(scene *d, game_obj *g);
void hit_animate_slime(scene *d, game_obj *g);
void move_animate_slime(scene *d, game_obj *g);
void jump_animate_slime(scene *d, game_obj *g);
void idle_animate_slime(scene *d, game_obj *g);

#endif