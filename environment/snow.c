/*
** EPITECH PROJECT, 2021
** MyRPG - environment
** File description:
** environment rain for scene
*/

#include "../include/rpg.h"

void animate_snow(scene *d, environment *e)
{
    e->time = sfClock_getElapsedTime(e->clock);
    float seconds = sfTime_asSeconds(e->time);
    float old_seconds = sfTime_asSeconds(e->old_time);
    if (seconds - old_seconds >= 10) {
        d->env_type = NONE;
        return;
    }
    for (size_t i = 0; i < sfVertexArray_getVertexCount(e->array); ++i) {
        sfVertex *v = sfVertexArray_getVertex(e->array, i);
        v->position.y += 2;
        if (v->position.y > d->hub->mode.height) {
            v->position.y = 0;
            v = sfVertexArray_getVertex(e->array, i - 1);
            v->position.y = 0;
        }
    }
}

void create_snow_env(scene *d)
{
    environment *env = malloc(sizeof(environment));
    env->type = SNOW;
    env->clock = sfClock_create();
    env->time = sfTime_Zero;
    env->old_time = sfClock_getElapsedTime(env->clock);
    env->array = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(env->array, sfQuads);
    for (int i = 0; i < 100; ++i) {
        sfVertex v;
        v.color = sfWhite;
        v.texCoords = create_vector2f(rand() % 1920, rand() % 1080);
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
    env->animate = animate_snow;
    put_in_list(&d->envs, env);
}
