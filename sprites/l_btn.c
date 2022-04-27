/*
** EPITECH PROJECT, 2021
** create long button
** File description:
** Sprite - create long button
*/

#include "../include/rpg.h"

void animate_lb(game_obj *g, scene *s, sfEvent event)
{
    g->rect.top = 0;
    sfSprite_setTextureRect(g->sprite, g->rect);
    switch (event.type) {
    case sfEvtMouseButtonPressed:
        if (is_on_btn(s, event.mouseButton, g->id))
            g->rect.top = 20;
        sfSprite_setTextureRect(g->sprite, g->rect);
        break;
    }
}

int create_sprite_lb(scene *d, char *name, int x, int y)
{
    sfVector2f pos[2] = {{x, y}, {0, 0}};
    game_obj *long_b = 
        create_obj(d, name, create_rect(55, 20, 0, 0), pos);
    set_scale(d, long_b->sprite, 3);
    long_b->name = my_strdup(name);
    long_b->grp = HOME_BTN;
    long_b->display = 1;
    long_b->event = animate_lb;
    sfSprite_setTextureRect(long_b->sprite, long_b->rect);
    sfRenderWindow_drawSprite(d->hub->window, long_b->sprite, NULL);
    put_in_end(&d->objs, long_b);
    return 0;
}
