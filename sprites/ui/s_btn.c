/*
** EPITECH PROJECT, 2021
** create long button
** File description:
** Sprite - create long button
*/

#include "../include/rpg.h"

void sb_settings_change(sfEvent event, button *d, game_obj *g, scene *s)
{
    sound *music = (sound *)s->sounds->data;
    if (is_on_btn(s, event.mouseButton, g->id) &&
        my_strcmp(g->name, "white_plus") && s->hub->s->volume < 50
        && s->hub->s->volume > -1) {
        s->hub->s->volume++;
        modify_string(s, d->t->string,
            my_int_to_str(s->hub->s->volume));
    }
    if (is_on_btn(s, event.mouseButton, g->id) &&
        my_strcmp(g->name, "white_minus") && s->hub->s->volume > 0
        && s->hub->s->volume < 51) {
        s->hub->s->volume--;
        modify_string(s, d->t->string,
        my_int_to_str(s->hub->s->volume));
    }
    sfMusic_setVolume(music->music, s->hub->s->volume);
}

void square_button_event(sfEvent event, button *d, game_obj *g, scene *s)
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
    if (event.type == sfEvtMouseButtonReleased) {
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
    switch (event.type) {
    case sfEvtMouseButtonPressed:
        if (is_on_btn(s, event.mouseButton, g->id)) {
            g->rect.left = 17;
        }
        sfSprite_setTextureRect(g->sprite, g->rect);
        break;
    }
}

int create_sprite_sb(scene *d, char *name, sfVector2f s_pos, char *text)
{
    sfVector2f pos[2] = {{s_pos.x, s_pos.y}, {0, 0}};
    game_obj *long_b =
        create_obj(d, name, create_rect(17, 19, 0, 0), pos);
    set_scale(d, long_b->sprite, 4);
    long_b->name = my_strdup(name);
    long_b->type = BUTTON;
    long_b->grp = HOME_BTN;
    long_b->display = 1;
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
