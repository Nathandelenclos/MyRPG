/*
** EPITECH PROJECT, 2021
** MyRunner
** File description:
** header file
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <math.h>
#include "list.h"
#include "my.h"
#include "struct.h"
#include "enum.h"

#ifndef RPG_H
    #define RPG_H

void event_manager(scene *d, sfEvent event);
scene *get_scene(scene *d, state state);
void sprites_manager(scene *d);
game_obj *create_obj(
    scene *d, char *texture_name, sfIntRect rect, sfVector2f *vector
);
void set_scale(scene *d, sfSprite *sprite, float multiplier);
void time_manager(scene *d);
sfIntRect create_simple_rect(int width, int height);
sfIntRect create_rect(int width, int height, int left, int top);
void move_manager(scene *d);
text *create_text(char *s, char *string, sfColor color, sfVector2f v);
void modify_string(scene *d, char *before, char *after);
void text_manager(scene *d);
texture *get_texture(scene *d, char *name);
void create_textures(scene *d);
void sound_manager(scene *d);
void destroy_music(screen *hub);
void scroll(scene *d, float x, float y, group grp);
sound *create_sound(char *filename, enum sound_grp grp, float volume);
void screen_manager(screen *s);
void launch_in_thread(void (*function)(void *), void *userData);
void copy_objs(scene *copy, scene *paste, group grp);
game_obj *is_on_btn(
    scene *d, sfMouseButtonEvent event, group grp, char *name
);
void data_start(screen *screen1);
life_bar *create_life_bar(
    int width, int height, sfColor main_color, sfColor back_color
);
void life_percent(life_bar *lb, float percent);
void print_life_bar(scene *d, life_bar *lb, int percent);
void print_main_life(scene *d);
scene *create_scene(screen *s, state state);
texture *create_texture(char *filename, char *name, sfIntRect rect);
void display_score(scene *d);
void display_money(scene *d);
void display_fps(scene *d);
int vector_is_around(sfVector2f v, sfVector2f obj, int margin);
void play_sound(scene *d, enum sound_grp grp);
void free_game(screen *hub);

#endif
