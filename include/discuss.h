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
    NULL
}, {
    "Try running around a bit.\n"
    "However, be careful about the mobs you could get hurt.\n"
    "Kill some pink slimes on the way !\n",
    "x3 Pink slime\n",
    "I didn't realize how strong you were when I saw you!\n",
    NULL
}, {
    "Damn, I'm so hungry ! Can you pick up some apple on the trees around ?\n"
    "Be careful, there are lot of slime !\n",
    "x5 Apple\n",
    "How could i live without you !\n",
    NULL
}, {
    "A client want some blue slimes.\n"
    "I know you are busy but can you go to the north of the island\n",
    "and kill 4 Blue slimes for me ?\n"
    "x4 Blue slime\n",
    "How could i live without you !\n",
    NULL
}
};

#endif