/*
** EPITECH PROJECT, 2021
** create long button
** File description:
** Sprite - create long button
*/

#include "../include/rpg.h"

void animate_sb(game_obj *g, scene *s, sfEvent event)
{
    g->rect.left = 0;
    sfSprite_setTextureRect(g->sprite, g->rect);
    switch (event.type) {
    case sfEvtMouseButtonPressed:
        if (is_on_btn(s, event.mouseButton, g->id))
            g->rect.left = 17;
        sfSprite_setTextureRect(g->sprite, g->rect);
        break;
    }
}

int create_sprite_sb(scene *d, char *name, int x, int y)
{
    sfVector2f pos[2] = {{x, y}, {0, 0}};
    game_obj *square_b = 
        create_obj(d, name, create_rect(17, 19, 0, 0), pos);
    set_scale(d, square_b->sprite, 3);
    square_b->name = my_strdup(name);
    square_b->grp = HOME_BTN;
    square_b->display = 1;
    square_b->event = animate_sb;
    sfSprite_setTextureRect(square_b->sprite, square_b->rect);
    sfRenderWindow_drawSprite(d->hub->window, square_b->sprite, NULL);
    put_in_end(&d->objs, square_b);
    return 0;
}
