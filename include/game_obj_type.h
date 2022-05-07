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
    sfTime old_time_hit;
    sfTime old_time_disp;
    int hp;
    int hp_max;
    int attack;
    int speed;
    life_bar *lb;
} slime;

typedef struct {
    void (*fruit)(scene *, game_obj *);
    tree_state state;
    sfTime time;
    sfTime old_time_fruit;
} tree;


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
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    game_obj *obj;
} slot_inv;

typedef struct {
    sfVector2f *pos;
    slot_inv **slot;
    slot_inv *stamp;
    int size;
} inventory;

typedef struct {
    sfTime time;
    sfTime old_time_an;
    sfTime old_time_hit;
    sfTime old_time_hp;
    entity_state state;
    double animation_speed;
    game_obj *inv;
    inventory *inventory;
    int hp;
    life_bar *lb;
    int slot_select;
    void (*idle)(scene *, game_obj *);
    void (*move)(scene *, game_obj *);
    void (*jump)(scene *, game_obj *);
    void (*hit)(scene *, game_obj *);
    void (*destroy)(scene *, game_obj *);
} player;

typedef struct {
    sfTime time;
    sfTime old_time_an;
    int dialog;
    int quest;
} pnj;

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
    inventory *inventory;
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
    slot_inv **slots;
    int selected;
} player_inv;

void destroy_animate_slime(scene *d, game_obj *g);
void hit_animate_slime(scene *d, game_obj *g);
void move_animate_slime(scene *d, game_obj *g);
void jump_animate_slime(scene *d, game_obj *g);
void idle_animate_slime(scene *d, game_obj *g);
particle *create_particle(scene *d);
chest *create_chest_data(scene *d);
inventory *create_inventory_data(scene *d, int size, sfVector2f *pos);
void push_items(inventory *ci, int i, game_obj *obj);
sfVector2f *init_inventory_pos_places_p(void);
sfVector2f *init_inventory_pos_places_c(void);

#endif