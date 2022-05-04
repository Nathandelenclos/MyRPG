/*
** EPITECH PROJECT, 2021
** MyRPG - manager
** File description:
** manager 
*/

#include "../include/rpg.h"

environment *get_env(scene *d, env_type type)
{
    node *tmp = d->envs;
    environment *env = NULL;
    while (tmp != NULL) {
        env = (environment *)tmp->data;
        if (env->type == type)
            return env;
        tmp = tmp->next;
    }
    return NULL;
}

void env_manager(scene *d)
{
    environment *env = get_env(d, d->env_type);
    if (env != NULL) {
        env->animate(d, env);
        sfRenderWindow_drawVertexArray(d->hub->window, env->array, NULL);
    }
}
