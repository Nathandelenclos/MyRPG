/*
** EPITECH PROJECT, 2021
** MyRPG - utils
** File description:
** fade translate scene
*/

#include "../include/rpg.h"

void fade_sprite(scene *new, node *tmp, int a)
{
    game_obj *obj = NULL;
    sfColor color;

    while (tmp != NULL) {
        obj = (game_obj *) tmp->data;
        color = sfSprite_getColor(obj->sprite);
        color.a = a;
        sfSprite_setColor(obj->sprite, color);
        sfRenderWindow_drawSprite(new->hub->window, obj->sprite, NULL);
        tmp = tmp->next;
    }
}

void fade_txt(scene *new, node *tmp, int a)
{
    text *txt = NULL;
    sfColor color;

    while (tmp != NULL) {
        txt = (text *) tmp->data;
        sfRenderWindow_drawText(new->hub->window, txt->text, NULL);
        tmp = tmp->next;
    }
}

void fade_scene(scene *old)
{
    node *tmp = old->objs;
    node *tmp_txt = old->texts;

    if (old->state != START)
        return;
    for (int t = 255; t >= 0; --t) {
        sfRenderWindow_clear(old->hub->window, sfBlack);
        fade_sprite(old, tmp, t);
        fade_txt(old, tmp_txt, t);
        tmp = old->objs;
        tmp_txt = old->texts;
        sfRenderWindow_display(old->hub->window);
    }
    fade_sprite(old, tmp, 255);
    fade_txt(old, tmp_txt, 255);
    sfRenderWindow_clear(old->hub->window, sfBlack);
}