/*
** EPITECH PROJECT, 2021
** MyRPG - Manager
** File description:
** Manager
*/

#include "../include/rpg.h"
#include "../include/my.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

void scroll(scene *d, float x, float y, group grp)
{
    node *tmp = d->objs;
    while (tmp != NULL) {
        game_obj *obj = (game_obj *) tmp->data;
        if (obj->grp == grp) {
            sfVector2f v = {x, y};
            sfSprite_move(obj->sprite, v);
        }
        tmp = tmp->next;
    }
}

game_obj *is_on_btn(
    scene *d, sfMouseButtonEvent event, group grp, char *name
)
{
    game_obj *obj;
    node *tmp = d->objs;
    sfVector2f position;
    while (tmp != NULL) {
        obj = (game_obj *) tmp->data;
        position = sfSprite_getPosition(obj->sprite);
        if (obj->grp == grp &&
            (name == NULL || (obj->name && my_strcmp(obj->name, name))) &&
            (float) event.y < (position.y + (float) obj->rect.height) &&
            (float) event.y > position.y &&
            (float) event.x < (position.x + (float) obj->rect.width) &&
            (float) event.x > position.x) {
            return obj;
        }
        tmp = tmp->next;
    }
    return NULL;
}

scene *get_scene(scene *d, state state)
{
    screen *hub = d->hub;
    node *tmp = hub->datas;
    while (tmp != NULL) {
        if (((scene *)tmp->data)->state == state)
            return (scene *)tmp->data;
        tmp = tmp->next;
    }
    return NULL;
}

scene *create_scene(screen *s, state state)
{
    scene *d = malloc(sizeof(scene));
    d->objs = NULL;
    d->texts = NULL;
    d->sounds = NULL;
    d->textures = NULL;
    d->hub = s;
    d->state = state;
    d->screen = NULL;
    d->event = NULL;
    return d;
}

void screen_manager(screen *s)
{
    data_start(s);
}
