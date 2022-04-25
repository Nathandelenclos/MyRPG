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

#ifndef RPG_ENUM_H
    #define RPG_ENUM_H

typedef enum group_e {
    HOME_BTN,
    ENEMY,
    UI,
} group;

typedef enum type_e {
    BASIC,
} type;

typedef enum state_e {
    START,
    PLAY,
    PAUSE,
} state;

enum sound_grp {
    MUSIC,
    CLICK,
    NEW_GAME
};

#endif
