/*
** EPITECH PROJECT, 2021
** create long button
** File description:
** Sprite - create long button
*/

#include "../include/rpg.h"

int create_sprite_ltile(scene *d, char *name, btn_param *p)
{
    sfVector2f pos[2] = {{p->pos.x, p->pos.y}, {0, 0}};
    game_obj *long_t =
        create_obj(d, name, create_rect(55, 20, 0, 0), pos);
    set_scale(d, long_t->sprite, p->scale);
    long_t->name = my_strdup(name);
    long_t->grp = p->grp;
    long_t->display = p->zindex;
    sfSprite_setTextureRect(long_t->sprite, long_t->rect);
    sfRenderWindow_drawSprite(d->hub->window, long_t->sprite, NULL);
    put_in_end(&d->objs, long_t);
    return 0;
}
