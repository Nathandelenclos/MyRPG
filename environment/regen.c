/*
** EPITECH PROJECT, 2021
** MyRPG - environment 
** File description:
** regen environment particle
*/

#include "../include/rpg.h"

void animate_regen(scene *d, environment *e)
{
    for (size_t i = 0; i < sfVertexArray_getVertexCount(e->array); ++i) {
        sfVertex *v = sfVertexArray_getVertex(e->array, i);
        v->position.y -= rand() % (3 - 0 + 1) + 0;
        v->position.x += rand() % (5 - -5 + 1) + -5;
        v->color.a -= 2;
        if (v->color.a <= 5) {
            v->position = create_vector2f(d->hub->mode.width / 2,(d->hub->mode.height / 2) + 130);
            v->color = sfGreen;
        }
    }
}

void create_regen_env(scene *d)
{
    environment *env = malloc(sizeof(environment));
    env->type = REGEN;
    env->active = sfFalse;
    env->array = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(env->array, sfPoints);
    for (int i = 0; i < 500; ++i) {
        sfVertex v;
        v.color = sfGreen;
        v.texCoords = create_vector2f(d->hub->mode.width / 2, (d->hub->mode.height / 2) + 130);
        v.position = v.texCoords;
        sfVertexArray_append(env->array, v);
    }
    env->animate = animate_regen;
    put_in_list(&d->envs, env);
}
