/*
** EPITECH PROJECT, 2021
** MyRPG - environment
** File description:
** spawn particle
*/

#include "../include/rpg.h"

void animate_spawn(scene *d, environment *e)
{
    for (size_t i = 0; i < sfVertexArray_getVertexCount(e->array); ++i) {
        sfVertex *v = sfVertexArray_getVertex(e->array, i);
        if (v->color.a < 15)
            v->color.a = 0;
        else
            v->color.a -= (rand() % (5 - -0 + 1) + -0);
    }
}

void create_spawn_env(scene *d)
{
    environment *env = malloc(sizeof(environment));
    env->type = SPAWN;
    env->active = sfFalse;
    env->array = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(env->array, sfPoints);
    for (int i = 0; i < 15000; ++i) {
        sfVertex v;
        v.color = sfWhite;
        int midx = d->hub->mode.width / 2;
        int midy = (d->hub->mode.height / 2);
        v.texCoords = create_vector2f(midx + (rand() % (75 - -75 + 1) + -75), midy + (rand() % (75 - -75 + 1) + -75));
        v.position = v.texCoords;
        sfVertexArray_append(env->array, v);
    }
    env->animate = animate_spawn;
    put_in_list(&d->envs, env);
}
