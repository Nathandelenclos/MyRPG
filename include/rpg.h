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
#include <math.h>
#include <stdio.h>
#include "list.h"
#include "my.h"
#include "struct.h"
#include "enum.h"
#include "textures.h"
#include "object.h"
#include "game_obj_type.h"

#ifndef RPG_H
    #define RPG_H

text_id *create_text_id_struct(int size, group grp, int);
void switch_scene(scene *d, state s);
void wrong_input(screen *screen1);
btn_param *create_btn_param(sfVector2f pos, int zindex, int scale, group grp);
settings *init_settings_struct(void);
void create_tree(scene *d, sfVector2f pos);
void data_settings(screen *screen1);
void create_button_setting(scene *d);
void create_text_setting_invent_left(scene *d);
void lb_change_input(sfEvent event, button *d, game_obj *g, scene *s);
button *create_button_data(char *text, scene *s, sfVector2f pos);
text *search_for_text(scene *s, char *name);
sfVector2f create_vector2f(float x, float y);
text *search_for_n_text(scene *s, char *name, int n);
sfVector2f get_w_scale(scene *d, game_obj *);
void event_manager(scene *d, sfEvent event);
scene *get_scene(scene *d, state state);
void sprites_manager(scene *d);
int get_next_index(node *list);
void scroll_text_grp(scene *d, float x, float y, group);
text *get_text(scene *d, char *name);
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
void scroll_object_by_grp(scene *d, float x, float y, group grp);
void scroll_object_by_name(scene *d, float x, float y, char *name);
sound *create_sound(char *filename, enum sound_grp grp, float volume);
void screen_manager(screen *s);
void launch_in_thread(void (*function)(void *), void *userData);
void copy_objs(scene *copy, scene *paste, group grp);
game_obj *is_on_btn(scene *d, sfMouseButtonEvent event, int id);
void data_start(screen *screen1);
void print_color(scene *data, int x, int y);
life_bar *create_life_bar(
    int width, int height, sfColor main_color, sfColor back_color
);
void life_percent(life_bar *lb, float percent);
void print_life_bar(scene *d, life_bar *lb, float percent, sfVector2f pos);
void print_main_life(scene *d);
scene *create_scene(screen *s, state state);
texture *create_texture(char *filename, char *name, sfIntRect rect);
void display_score(scene *d);
void display_money(scene *d);
void display_fps(scene *d);
void collision_map(scene *s, game_obj *g);
int vector_is_around(sfVector2f v, sfVector2f obj, int margin);
void play_sound(scene *d, enum sound_grp grp);
void free_game(screen *hub);
void events_manage(scene *d, sfEvent);
void draw_text_with_index(scene *d, int index);
void data_play(screen *screen1);
sfVector2f create_vector2f(float x, float y);
void data_chest(screen *screen1);
game_obj *get_object(scene *d, char *name);
void switch_scene(scene *d, state s);
float get_distance(game_obj *first, game_obj *seconds);
game_obj *get_closer_object(scene *d, game_obj *obj, group grp);
void animate_all_particles(scene *s, player *p);
environment *get_env(scene *d, env_type type);
void env_manager(scene *d);
void create_env(scene *d);
void create_bed(scene *d, sfVector2f pos);

#endif
