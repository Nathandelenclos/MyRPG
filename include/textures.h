/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** textures
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

#ifndef TEXTURES_H_
    #define TEXTURES_H_

int create_menu_texture(scene *d);
int create_buttons_texture(scene *d);
void create_characters_texture(scene *d);
void create_chest_and_obj_texture(scene *d);
void create_particles_texture(scene *d);
void create_walls_texture(scene *d);
void create_tilesets_texture(scene *d);
void create_white_banner_texture(scene *d);
void create_wreath_banner_texture(scene *d);
void create_banners_texture(scene *d);
void create_arrow_down_texture(scene *d);
void create_arrow_up_texture(scene *d);
void create_arrow_left_texture(scene *d);
void create_arrow_right_texture(scene *d);
void create_controls_texture(scene *d);
void create_icons_texture(scene *d);
void create_icon_questionmark_texture(scene *d);
void create_icon_ranking_texture(scene *d);
void create_icon_settings_texture(scene *d);
void create_icon_triangle_texture(scene *d);
void create_icon_trophy_texture(scene *d);
void create_icon_twitter_texture(scene *d);
void create_icon_watchad_texture(scene *d);
void create_icon_youtube_texture(scene *d);
void create_others_texture(scene *d);

#endif
