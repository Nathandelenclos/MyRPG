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
        env = (environment *) tmp->data;
        if (env->type == type)
            return env;
        tmp = tmp->next;
    }
    return NULL;
}

void env_manager(scene *d)
{
    node *tmp = d->envs;
    environment *env = NULL;
    while (tmp != NULL) {
        env = (environment *) tmp->data;
        if (env->active == sfTrue) {
            env->animate(d, env);
            sfRenderWindow_drawVertexArray(d->hub->window, env->array, NULL);
        }
        tmp = tmp->next;
    }
}

void create_env(scene *d)
{
    create_rain_env(d);
    create_regen_env(d);
    create_low_life_env(d);
}
