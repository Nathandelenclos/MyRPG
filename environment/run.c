/*
** EPITECH PROJECT, 2021
** MyRPG - environment
** File description:
** run particle
*/

#include "../include/rpg.h"

void animate_run(scene *d, environment *e)
{
    game_obj *g = get_object(d, "maps");
    maps *map = (maps *)g->data;
    int midx = d->hub->mode.width / 2;
    int midy = (d->hub->mode.height / 2) + 130;
    for (size_t i = 0; i < sfVertexArray_getVertexCount(e->array); ++i) {
        sfVertex *v = sfVertexArray_getVertex(e->array, i);
        v->position.x -= map->speed;
        if (v->color.a < 15)
            v->color.a = 0;
        else
            v->color.a -= (rand() % (5 - -0 + 1) + -0);
        if (v->position.x < 0) {
            v->color = sfBlue;
            v->position = create_vector2f(midx, rand() % ((midy + 5) - (midy - 5) + 1) + (midy - 5));
        }
    }
}

void create_run_env(scene *d)
{
    environment *env = malloc(sizeof(environment));
    env->type = RUN;
    env->active = sfFalse;
    env->array = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(env->array, sfQuads);
    for (int i = 0; i < 100; ++i) {
        sfVertex v;
        v.color = sfBlue;
        int midx = d->hub->mode.width / 2;
        int midy = (d->hub->mode.height / 2) + 130;
        v.texCoords = create_vector2f(midx, rand() % ((midy + 5) - (midy - 5) + 1) + (midy - 5));
        v.position = v.texCoords;
        sfVertexArray_append(env->array, v);
    }
    env->animate = animate_run;
    put_in_list(&d->envs, env);
}
