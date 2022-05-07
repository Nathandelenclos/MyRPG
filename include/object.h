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
#include "textures.h"
#include "game_obj_type.h"

#ifndef OBJECT_H_
    #define OBJECT_H_

//Objects
int create_sprite_popup(scene *d);
int create_sprite_bg_settings(scene *d);
int input_handling(sfKeyCode code, controls *c, scene *s);
void change_input_slot_p1(button *d, controls *c, sfEvent event, scene *s);
void change_input_interact(button *d, controls *c, sfEvent event, scene *s);
void change_input_movement(button *d, controls *c, sfEvent event, scene *s);
int create_settings_hud_sprite(scene *d);
int create_settings_menu_sprite(scene *d);
void create_blue_banner(scene *d);
void create_green_banner(scene *d);
void create_purple_banner(scene *d);
void create_red_banner(scene *d);
void create_white_banner(scene *d);
void create_wreath_banner(scene *d);
void create_arrow_down(scene *d);
void create_arrow_up(scene *d);
void create_arrow_left(scene *d, sfVector2f);
void create_arrow_right(scene *d);
void create_small_arrow_down(scene *d);
void create_small_arrow_up(scene *d);
void create_small_arrow_left(scene *d);
void create_small_arrow_right(scene *d);
void create_icon_exclamationmark(scene *d);
void create_icon_facebook(scene *d);
void create_icon_house(scene *d);
void create_icon_human(scene *d);
void create_icon_questionmark(scene *d);
void create_icon_ranking(scene *d);
void create_icon_settings(scene *d);
void create_icon_triangle(scene *d);
void create_icon_trophy(scene *d);
void create_icon_twitter(scene *d);
void create_icon_watchad(scene *d);
void create_icon_youtube(scene *d);
void create_slime(scene *d, sfVector2f pos, slime_type type, sfVector2f hp_hit);
int create_sprite_map(scene *d);
int create_sprite_lb(scene *d, char *name, btn_param *p, char *text);
int create_sprite_rb(scene *d, char *, int, int);
int create_sprite_sb(scene *d, char *name, btn_param *p, char *text);
void create_player(scene *d);
void idle_player_animation(scene *d, game_obj *g);
void move_player_animation(scene *d, game_obj *g);
void hit_player_animation(scene *d, game_obj *g);
game_obj *create_inventory(scene *d);
void create_chest_inventory_sprite(scene *d);
void create_chest_background_sprite(scene *d);
int create_sprite_menu(scene *d);
int create_sprite_slide_b(scene *d, sfVector2f s_pos);
int create_sprite_ltile(scene *, char *, btn_param *);

//Text
void create_btn_text(scene *d, char *, text_id *, sfVector2f);
void create_basic_chest(scene *d, float x, float y);
void create_golden_chest(scene *d);

//Environment
void create_rain_env(scene *d);
void create_snow_env(scene *d);
void create_regen_env(scene *d);
void create_spawn_env(scene *d);
void create_low_life_env(scene *d);
void create_run_env(scene *d);

#endif
