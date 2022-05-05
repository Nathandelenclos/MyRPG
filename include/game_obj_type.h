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

typedef struct particle_s{
    sfSprite *sprite;
    sfTexture *texture;
    void (*animate)(scene  *, struct particle_s *p);
    int state;
} particle;

typedef struct {
    sfTime time;
    sfTime old_time_an;
    entity_state state;
    double animation_speed;
    game_obj *inv;
    node *particles;
    void (*idle)(scene *, game_obj *);
    void (*move)(scene *, game_obj *);
    void (*jump)(scene *, game_obj *);
    void (*hit)(scene *, game_obj *);
    void (*destroy)(scene *, game_obj *);
} player;

typedef struct {
    int count;
    int index;
} slot;

typedef struct {
    text *t;
    sfVector2f pos;
} button;

typedef struct {
    sfTime old_time_an;
    sfTime time;
} menu_bg;

typedef struct {
    chest_state state;
    sfTime time;
    sfTime old_time_an;
    void (*open)(scene *, game_obj *);
    void (*close)(scene *, game_obj *);
} chest;

typedef struct {
    sfVector2f pos;
    int zindex;
    int scale;
    group grp;
} btn_param;

typedef struct {
    int size;
    group grp;
    int zindex;
} text_id;

typedef struct {
    inventory_chest_state state;
    sfVector2f *pos;
    sfSprite *slot_s[36];
    sfTexture *slot_t[36];
    sfSprite *stamp_s;
    sfTexture *stamp_t;
} chest_inventory;

void destroy_animate_slime(scene *d, game_obj *g);
void hit_animate_slime(scene *d, game_obj *g);
void move_animate_slime(scene *d, game_obj *g);
void jump_animate_slime(scene *d, game_obj *g);
void idle_animate_slime(scene *d, game_obj *g);
particle *create_particle(scene *d);

#endif