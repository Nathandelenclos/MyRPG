/*
** EPITECH PROJECT, 2021
** create long button
** File description:
** Sprite - create long button
*/

#include "../include/rpg.h"

void modify_sound(game_obj *g, scene *s, sfEvent event)
{
    switch (event.type) {
    case sfEvtMouseButtonPressed:
        if (is_on_btn(s, event.mouseButton, g->id)) {
            g->position.x = sfMouse_getPositionRenderWindow(s->hub->window).x
            - (49 * 3);
            sfSprite_setPosition(g->sprite, g->position);
        }
        sfSprite_setTextureRect(g->sprite, g->rect);
        break;
    }
}

int create_sprite_slide_b(scene *d, sfVector2f s_pos)
{
    sfVector2f pos[2] = {{s_pos.x, s_pos.y + 10}, {0, 0}};
    game_obj *slide_b =
        create_obj(d, "slide_bar", create_rect(98, 10, 0, 0), pos);
    set_scale(d, slide_b->sprite, 3);
    create_sprite_rb(d, "white_rb", s_pos.x + 50, s_pos.y);
    slide_b->name = "slide_bar";
    slide_b->type = BUTTON;
    slide_b->grp = HOME_BTN;
    slide_b->display = 1;
    slide_b->event = modify_sound;
    sfSprite_setTextureRect(slide_b->sprite, slide_b->rect);
    sfRenderWindow_drawSprite(d->hub->window, slide_b->sprite, NULL);
    put_in_end(&d->objs, slide_b);
    return 0;
}
