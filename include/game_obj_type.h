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

typedef struct {
    void (*idle)(scene *, game_obj *);
    void (*move)(scene *, game_obj *);
    void (*jump)(scene *, game_obj *);
    void (*hit)(scene *, game_obj *);
    void (*destroy)(scene *, game_obj *);
    entity_state state;
    sfTime time;
    sfTime old_time_an;
    int life;
    int speed;
} slime;

typedef struct {
    sfTime time;
    sfTime old_time_an;
    float speed;
} maps;

typedef struct {
    sfTime time;
    sfTime old_time_an;
    entity_state state;
    double animation_speed;
    void (*idle)(scene *, game_obj *);
    void (*move)(scene *, game_obj *);
    void (*jump)(scene *, game_obj *);
    void (*hit)(scene *, game_obj *);
    void (*destroy)(scene *, game_obj *);
} player;


void destroy_animate_slime(scene *d, game_obj *g);
void hit_animate_slime(scene *d, game_obj *g);
void move_animate_slime(scene *d, game_obj *g);
void jump_animate_slime(scene *d, game_obj *g);
void idle_animate_slime(scene *d, game_obj *g);

#endif