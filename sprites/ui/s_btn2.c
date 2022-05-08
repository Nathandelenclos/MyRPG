/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** s_btn2
*/

#include "../../include/rpg.h"

void sb_settings_change2(sfEvent event, button *d, game_obj *g, scene *s)
{
    sound *music = (sound *)s->sounds->data;
    if (my_strcmp(d->t->name, my_int_to_str(s->hub->s->fps)) &&
    s->hub->s->fps < 300 && s->hub->s->fps > 14) {
        s->hub->s->fps++;
        modify_string(s, d->t->string,
        my_int_to_str(s->hub->s->fps));
        d->t->name = my_int_to_str(s->hub->s->fps);
        sfRenderWindow_setFramerateLimit(s->hub->window, s->hub->s->fps);
    }
    if (my_strcmp(d->t->name, my_int_to_str(s->hub->s->volume)) &&
    s->hub->s->volume < 100 && s->hub->s->volume > -1) {
        s->hub->s->volume++;
        modify_string(s, d->t->string,
        my_int_to_str(s->hub->s->volume));
        d->t->name = my_int_to_str(s->hub->s->volume);
        sfMusic_setVolume(music->music, s->hub->s->volume);
    }
}

void sb_settings_change3(sfEvent event, button *d, game_obj *g, scene *s)
{
    sound *music = (sound *)s->sounds->data;
    if (my_strcmp(d->t->name, my_int_to_str(s->hub->s->fps)) &&
    s->hub->s->fps > 15 && s->hub->s->fps < 300) {
        s->hub->s->fps--;
        modify_string(s, d->t->string,
        my_int_to_str(s->hub->s->fps));
        d->t->name = my_int_to_str(s->hub->s->fps);
        sfRenderWindow_setFramerateLimit(s->hub->window, s->hub->s->fps);
    }
    if (my_strcmp(d->t->name, my_int_to_str(s->hub->s->volume)) &&
    s->hub->s->volume > 0 && s->hub->s->volume < 101) {
        s->hub->s->volume--;
        modify_string(s, d->t->string,
        my_int_to_str(s->hub->s->volume));
        d->t->name = my_int_to_str(s->hub->s->volume);
        sfMusic_setVolume(music->music, s->hub->s->volume);
    }
}

void sb_settings_change(sfEvent event, button *d, game_obj *g, scene *s)
{
    if (is_on_btn(s, event.mouseButton, g->id)
    && my_strcmp(g->name, "white_plus"))
        sb_settings_change2(event, d, g, s);
    if (is_on_btn(s, event.mouseButton, g->id)
    && my_strcmp(g->name, "white_minus"))
        sb_settings_change2(event, d, g, s);
}
