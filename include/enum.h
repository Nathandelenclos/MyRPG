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

static const char *TOUCH[] = {"   A", "   B", "   C", "   D", "   E", "   F",
    "   G", "   H", "   I", "   J", "   K", "   L", "   M", "   N", "   O",
    "   P", "   Q", "   R", "   S", "   T", "   U", "   V", "   W", "   X",
    "   Y", "   Z", "   0", "   1", "   2", "   3", "   4", "   5", "   6",
    "   7", "   8", "   9", "  Esc", " L Ctrl", "L Shift",
    " L Alt", " L Syst", " R Ctrl", "R Shift", " R Alt", " R Syst", "  Menu",
    "   {", "   }", "   ;", "   ,", "   .", "   \"", "   /", "   \\", "   ~",
    "   =", "   -", " Space", " Enter",
    "B Space", "  Tab", "  P Up", " P Down", "  End", "  Home", " Insert",
    "  Del", "   +", "   -", "   *", "    /", "  Left", " Right", "   Up",
    "  Down", "  NP 1", "  NP 2", "  NP 3", "  NP 4", "  NP 5", "  NP 6",
    "  NP 7", "  NP 8", "  NP 9", "  F1", "  F2", "  F3", "   F4", "  F5",
    "  F6", "  F7", "  F8", "  F9", "  F10", "  F11", "  F12", "  F13",
    "  F14", "  F15",
    " Pause", "K Count", "-", "B Space", "\\", ";", " Enter", NULL};


typedef enum group_e {
    HOME_BTN,
    ENEMY,
    UI,
    OBJECT,
} group;

typedef enum type_e {
    BASIC,
    SLIME,
    MENU_BG,
    BUTTON,
    CHEST,
} type;

typedef enum state_e {
    START,
    PLAY,
    PAUSE,
    SETTINGS,
} state;

enum sound_grp {
    MUSIC,
    CLICK,
    NEW_GAME
};

typedef enum {
    BLUE,
    BLACK,
    GREEN,
    PINK,
    YELLOW
} slime_type;

typedef enum {
    IDLE,
    MOVE,
    JUMP,
    HIT,
    DESTROY,
} slime_state;

typedef enum {
    OPEN,
    CLOSE,
    IDLE_C,
} chest_state;

#endif
