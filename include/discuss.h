/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** type of game object
*/

#include <stdlib.h>

#ifndef DISCUSS_H
    #define DISCUSS_H

static const char *DIALOG[][4] = {{
    "Hey, you. You\'re finally awake.\n"
    "You've been sleeping for almost 1 full day so its normal\n"
    "if you feel kind of dizzy right now....\n"
    "Go get me the item that's in the chest on your right so\n"
    "you can stretch your legs a bit after that long nap.",
    "Maybe your legs are a bit numb, or you are too dumb... Whatever.\n"
    "Can you please go get that item in the chest for me please?",
    "Ok, looks like you can still use your legs.\n",
    NULL},{
    "Try running around a bit.\n"
    "However, be careful about the mobs you could get hurt.",
    "...",
    "I didn’t realize how strong you were when I saw you!\n"
    "Do you think you can kill some stronger slimes for me?\n"
    "I’lltell you my plan later.\n"
    "I don’t think you are ready to hear it.",
    NULL
}};

#endif
