/*
** EPITECH PROJECT, 2021
** create long button
** File description:
** Sprite - create long button
*/

#include "../include/rpg.h"

void long_button_event(sfEvent event, button *d, game_obj *g, scene *s)
{
    if (event.type == sfEvtMouseButtonPressed) {
        if (is_on_btn(s, event.mouseButton, g->id)) {
            g->rect.top = 21;
            g->rect.height = 20;
            d->t->position.y += 3;
            g->position.y += 3;
            sfText_setPosition(d->t->text, d->t->position);
            sfSprite_setPosition(g->sprite, g->position);
        }
        sfSprite_setTextureRect(g->sprite, g->rect);
    }
    if (event.type == sfEvtMouseButtonReleased)
        if (is_on_btn(s, event.mouseButton, g->id) &&
            my_strcmp(d->t->string, "   QUIT"))
            sfRenderWindow_close(s->hub->window);
}

void animate_lb(game_obj *g, scene *s, sfEvent event)
{
    button *d = (button *) g->data;
    g->rect.top = 0;
    g->position = d->pos;
    g->rect.height = 21;
    d->t->position.y = g->position.y - 25;
    if (my_strcmp(" SETTINGS", d->t->string))
        d->t->position.y = g->position.y - 10;
    d->t->position.x = g->position.x;
    sfSprite_setPosition(g->sprite, g->position);
    sfText_setPosition(d->t->text, d->t->position);
    sfSprite_setTextureRect(g->sprite, g->rect);
    long_button_event(event, d, g, s);
}

int create_sprite_lb(scene *d, char *name, sfVector2f s_pos, char *text)
{
    sfVector2f pos[2] = {{s_pos.x, s_pos.y}, {0, 0}};
    game_obj *long_b =
        create_obj(d, name, create_rect(55, 21, 0, 0), pos);
    set_scale(d, long_b->sprite, 5);
    long_b->data = create_button_data(text, d, pos[0]);
    long_b->name = my_strdup(name);
    long_b->type = BUTTON;
    long_b->grp = HOME_BTN;
    long_b->display = 1;
    long_b->event = animate_lb;
    sfSprite_setTextureRect(long_b->sprite, long_b->rect);
    sfRenderWindow_drawSprite(d->hub->window, long_b->sprite, NULL);
    put_in_end(&d->objs, long_b);
    return 0;
}
