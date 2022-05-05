/*
** EPITECH PROJECT, 2021
** MyRPG - environment
** File description:
** environment rain for scene
*/

#include "../include/rpg.h"

void animate_rain(scene *d, environment *e)
{
    for (size_t i = 0; i < sfVertexArray_getVertexCount(e->array); ++i) {
        sfVertex *v = sfVertexArray_getVertex(e->array, i);
        v->position.y += 10;
        if (v->position.y > d->hub->mode.height) {
            v->position.y = 0;
        }
    }
}

void create_rain_env(scene *d)
{
    environment *env = malloc(sizeof(environment));
    env->type = RAIN;
    env->active = sfFalse;
    env->array = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(env->array, sfQuads);
    for (int i = 0; i < 100; ++i) {
        sfVertex v;
        v.color = sfBlue;
        v.texCoords = create_vector2f(rand() % d->hub->mode.width, rand() % d->hub->mode.height);
        v.position = v.texCoords;
        sfVertexArray_append(env->array, v);
        v.position.y += 5;
        sfVertexArray_append(env->array, v);
        v.position.y -= 5;
        v.position.x += 5;
        sfVertexArray_append(env->array, v);
        v.position.y += 5;
        sfVertexArray_append(env->array, v);
    }
    env->animate = animate_rain;
    put_in_list(&d->envs, env);
}
