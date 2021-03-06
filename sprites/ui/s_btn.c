/*
** EPITECH PROJECT, 2021
** create long button
** File description:
** Sprite - create long button
*/

#include "../../include/rpg.h"

void square_button_pressed(sfEvent event, button *d, game_obj *g, scene *s)
{
    if (event.type == sfEvtMouseButtonPressed) {
        if (is_on_btn(s, event.mouseButton, g->id)) {
            g->rect.left = 17;
            d->t->position.y += 8;
            g->position.y += 3;
            sfText_setPosition(d->t->text, d->t->position);
            sfSprite_setPosition(g->sprite, g->position);
        }
        sfSprite_setTextureRect(g->sprite, g->rect);
    }
}

void square_button_event(sfEvent event, button *d, game_obj *g, scene *s)
{
    if (hover_on_btn(s, g->id)) {
        sfColor color = sfSprite_getColor(g->sprite);
        color.a = 135;
        sfSprite_setColor(g->sprite, color);
    } else {
        sfColor color = sfSprite_getColor(g->sprite);
        color.a = 255;
        sfSprite_setColor(g->sprite, color);
    }
    square_button_pressed(event, d, g, s);
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        sb_settings_change(event, d, g, s);
    }
}

void animate_sb(game_obj *g, scene *s, sfEvent event)
{
    button *d = (button *) g->data;
    g->rect.left = 0;
    g->position = d->pos;
    d->t->position.y = g->position.y;
    d->t->position.x = g->position.x + 13;
    sfSprite_setPosition(g->sprite, g->position);
    sfText_setPosition(d->t->text, d->t->position);
    sfSprite_setTextureRect(g->sprite, g->rect);
    square_button_event(event, d, g, s);
}

void animate_sb_no_text(game_obj *g, scene *s, sfEvent event)
{
    g->rect.left = 0;
    int a = 0;
    sfSprite_setTextureRect(g->sprite, g->rect);
    if (hover_on_btn(s, g->id)) {
        sfColor color = sfSprite_getColor(g->sprite);
        color.a = 135;
        sfSprite_setColor(g->sprite, color);
    } else {
        sfColor color = sfSprite_getColor(g->sprite);
        color.a = 255;
        sfSprite_setColor(g->sprite, color);
    }
    switch (event.type) {
    case sfEvtMouseButtonPressed:
        if (is_on_btn(s, event.mouseButton, g->id)) {
            g->rect.left = 17;
        }
        sfSprite_setTextureRect(g->sprite, g->rect);
        break;
    }
}

int create_sprite_sb(scene *d, char *name, btn_param *p, char *text)
{
    sfVector2f pos[2] = {{p->pos.x, p->pos.y}, {0, 0}};
    game_obj *long_b =
        create_obj(d, name, create_rect(17, 19, 0, 0), pos);
    set_scale(d, long_b->sprite, p->scale);
    long_b->name = my_strdup(name);
    long_b->type = BUTTON;
    long_b->grp = p->grp;
    long_b->display = p->zindex;
    if (text != NULL) {
        long_b->data = create_button_data(text, d, pos[0]);
        long_b->event = animate_sb;
    } else
        long_b->event = animate_sb_no_text;
    sfSprite_setTextureRect(long_b->sprite, long_b->rect);
    sfRenderWindow_drawSprite(d->hub->window, long_b->sprite, NULL);
    put_in_end(&d->objs, long_b);
    return 0;
}
