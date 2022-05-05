/*
** EPITECH PROJECT, 2021
** MyRPG - environment
** File description:
** environment low life
*/

#include "../include/rpg.h"

void animate_low_life(scene *d, environment *e)
{
    sfVector2f vs[] = {
        create_vector2f(0, 0), create_vector2f(d->hub->mode.width, 0),
        create_vector2f(0, d->hub->mode.height),
        create_vector2f(d->hub->mode.width, d->hub->mode.height),
    };
    for (size_t i = 0; i < sfVertexArray_getVertexCount(e->array); ++i) {
        sfVertex *v = sfVertexArray_getVertex(e->array, i);
        v->position.y -= rand() % (15 - -15 + 1) + -15;
        v->position.x += rand() % (15 - -15 + 1) + -15;
        v->color.a -= 2;
        if (v->color.a <= 5) {
            v->position = vs[rand() % (3 - 0 + 1) + 0];
            v->color = sfRed;
        }
    }
}

void create_low_life_env(scene *d)
{
    environment *env = malloc(sizeof(environment));
    env->type = LOW_LIFE;
    env->array = sfVertexArray_create();
    env->active = sfFalse;
    sfVertexArray_setPrimitiveType(env->array, sfPoints);
    for (int i = 0; i < 30000; ++i) {
        sfVertex v;
        v.color = sfRed;
        v.texCoords = create_vector2f(0, 0);
        v.position = v.texCoords;
        sfVertexArray_append(env->array, v);
        v.position = create_vector2f(d->hub->mode.width, 0);
        sfVertexArray_append(env->array, v);
        v.position = create_vector2f(0, d->hub->mode.height);
        sfVertexArray_append(env->array, v);
        v.position = create_vector2f(d->hub->mode.width, d->hub->mode.height);
        sfVertexArray_append(env->array, v);
    }
    env->animate = animate_low_life;
    put_in_list(&d->envs, env);
}
