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

void create_characters_texture(scene *d);

void create_chest_and_obj_texture(scene *d);

void create_particles_texture(scene *d);

void create_walls_texture(scene *d);

void create_tilesets_texture(scene *d);

void create_others_texture(scene *d);

#endif
