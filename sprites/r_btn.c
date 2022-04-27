/*
** EPITECH PROJECT, 2021
** create long button
** File description:
** Sprite - create long button
*/

#include "../include/rpg.h"

void animate_rb(game_obj *g, scene *s, sfEvent event)
{
    g->rect.left = 0;
    sfSprite_setTextureRect(g->sprite, g->rect);
    switch (event.type) {
    case sfEvtMouseButtonPressed:
        if (is_on_btn(s, event.mouseButton, HOME_BTN, g->name))
            g->rect.left = 17;
        sfSprite_setTextureRect(g->sprite, g->rect);
        break;
    }
}

int create_sprite_rb(scene *d, char *name, int x, int y)
{
    sfVector2f pos[2] = {{x, y}, {0, 0}};
    game_obj *round_b = 
        create_obj(d, name, create_rect(17, 17, 0, 0), pos);
    set_scale(d, round_b->sprite, 5);
    round_b->name = my_strdup(name);
    round_b->grp = HOME_BTN;
    round_b->display = 1;
    round_b->event = animate_rb;
    sfSprite_setTextureRect(round_b->sprite, round_b->rect);
    sfRenderWindow_drawSprite(d->hub->window, round_b->sprite, NULL);
    put_in_end(&d->objs, round_b);
    return 0;
}
