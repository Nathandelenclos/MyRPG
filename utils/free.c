/*
** EPITECH PROJECT, 2021
** MyRPG - FREE
** File description:
** free
*/

#include "../include/rpg.h"

void free_text(text *t)
{
    sfText_destroy(t->text);
    free(t->string);
    sfFont_destroy(t->font);
    free(t);
}

void free_texture(texture *t)
{
    sfTexture_destroy(t->texture);
    free(t->filename);
    free(t->name);
    free(t);
}

void free_sound(sound *t)
{
    sfMusic_stop(t->music);
    sfMusic_destroy(t->music);
    free(t);
}

void free_obj(game_obj *obj)
{
    sfSprite_destroy(obj->sprite);
    free_texture(obj->texture);
    free(obj->name);
    sfClock_destroy(obj->clock);
    free(obj);
}

void free_scene(scene *s)
{
    free_list(s->objs, (void(*)(void *))free_obj);
    free_list(s->sounds, (void(*)(void *))free_sound);
    free_list(s->texts, (void(*)(void *))free_text);
    free_list(s->textures, (void(*)(void *))free_texture);
    free(s);
}
