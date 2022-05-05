/*
** EPITECH PROJECT, 2021
** MyRPG - Header
** File description:
** header file
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "list.h"
#include "my.h"
#include "enum.h"

#ifndef RPG_STRUCT_H
    #define RPG_STRUCT_H

typedef struct game_obj_s game_obj;
typedef struct scene_s scene;

typedef struct {
    int up;
    int down;
    int left;
    int right;
    int run;
    int interact;
    int attack;
    int menu;
    int screen;
    int slot1;
    int slot2;
    int slot3;
    int slot4;
    int slot5;
    int slot6;
    int slot7;
    int slot8;
    int slot9;
} controls;

typedef struct {
    int volume;
    int fps;
    controls *c;
} settings;

typedef struct screen_s {
    sfVideoMode mode;
    state state;
    node *datas;
    sfRenderWindow *window;
    int fps;
    sfClock *clock;
    settings *s;
} screen;

typedef struct life_bar_s {
    sfImage *image;
    sfIntRect rect;
    sfTexture *texture;
    sfColor main_color;
    sfColor back_color;
    sfSprite *sprite;
    game_obj *obj;
    int percent;
} life_bar;

typedef struct scene_s {
    node *objs;
    node *texts;
    node *sounds;
    node *textures;
    state state;
    screen *hub;
    void (*screen)(scene *data);
    void (*active)(scene *old, scene *new);
    void (*event)(scene *data, sfEvent event);
} scene;

typedef struct texture_s {
    sfTexture *texture;
    sfIntRect rect;
    char *filename;
    void (*animate)(game_obj *);
    char *name;
} texture;

struct game_obj_s {
    int id;
    type type;
    void *data;
    group grp;
    sfSprite *sprite;
    texture *texture;
    sfIntRect rect;
    sfVector2f position;
    int display;
    char *name;
    void (*action)(game_obj *, scene *);
    void (*event)(game_obj *, scene *, sfEvent);
    void (*animate)(scene *, game_obj *);
    sfClock *clock;
    sfVector2f vector;
};

typedef struct sound_d {
    sfMusic *music;
    enum sound_grp grp;
} sound;

typedef struct text_s {
    sfBool display;
    sfFont *font;
    char *string;
    sfText *text;
    sfVector2f position;
    sfColor color;
    void (*animate)(struct text_s *, scene *d);
    int display;
    char *name;
    group grp;
} text;

#endif
