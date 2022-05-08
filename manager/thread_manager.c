/*
** EPITECH PROJECT, 2021
** MyRPG - Manager
** File description:
** thread manager
*/

#include "../include/rpg.h"

void launch_in_thread(void (*function)(void *), void *userData)
{
    sfThread *thread = sfThread_create(function, userData);
    sfThread_launch(thread);
    sfThread_wait(thread);
    sfThread_terminate(thread);
}
