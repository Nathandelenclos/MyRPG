/*
** EPITECH PROJECT, 2021
** MyRPG - environment
** File description:
** environment rain for scene
*/

#include "../include/rpg.h"

void animate_snow(scene *d, environment *e)
{
    for (size_t i = 0; i < sfVertexArray_getVertexCount(e->array); ++i) {
        sfVertex *v = sfVertexArray_getVertex(e->array, i);
        v->position.y += 2;
        if (v->position.y > d->hub->mode.height) {
            v->position.y = 0;
        }
    }
}


void create_snow_env(scene *d)
{
    environment *env = malloc(sizeof(environment));
    env->type = SNOW;
    env->active = sfFalse;
    env->array = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(env->array, sfPoints);
    for (int i = 0; i < 500; ++i) {
        sfVertex v;
        v.color = sfWhite;
        v.texCoords = create_vector2f(rand() % 1920, rand() % 1080);
        v.position = v.texCoords;
        sfVertexArray_append(env->array, v);
    }
    env->animate = animate_snow;
    put_in_list(&d->envs, env);
}
