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

#ifndef OBJECT_H_
    #define OBJECT_H_

void create_blue_banner(scene *d);
void create_green_banner(scene *d);
void create_purple_banner(scene *d);
void create_red_banner(scene *d);
void create_white_banner(scene *d);
void create_wreath_banner(scene *d);
void create_arrow_down(scene *d);
void create_arrow_up(scene *d);
void create_arrow_left(scene *d);
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
void create_slime(scene *d, int x, int y, slime_type type);
int create_sprite_lb(scene *d, char *, int, int);
int create_sprite_rb(scene *d, char *, int, int);
int create_sprite_sb(scene *d, char *, int, int);
void create_chest_inventory_sprite(scene *d);
void create_chest_background_sprite(scene *d);

#endif
