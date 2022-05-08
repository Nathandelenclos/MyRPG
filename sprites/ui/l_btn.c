/*
** EPITECH PROJECT, 2021
** create long button
** File description:
** Sprite - create long button
*/

#include "../../include/rpg.h"

void lb_window_change(sfEvent event, button *d, game_obj *g, scene *s)
{
    if (is_on_btn(s, event.mouseButton, g->id) &&
        my_strcmp(d->t->string, "   QUIT"))
        sfRenderWindow_close(s->hub->window);
    if (is_on_btn(s, event.mouseButton, g->id) &&
        (my_strcmp(d->t->string, "   PLAY") ||
        my_strcmp(d->t->string, "RESPAWN"))) {
        switch_scene(s, PLAY);
    }
    if (is_on_btn(s, event.mouseButton, g->id) &&
        my_strcmp(d->t->string, " SETTINGS"))
        switch_scene(s, SETTINGS);
    if (is_on_btn(s, event.mouseButton, g->id) &&
        (my_strcmp(d->t->string, "   DONE") ||
        my_strcmp(d->t->string, "MAIN MENU")))
        switch_scene(s, START);
}

void long_button_event(sfEvent event, button *d, game_obj *g, scene *s)
{
    if (event.type == sfEvtMouseButtonReleased) {
        if (is_on_btn(s, event.mouseButton, g->id)) {
            lb_window_change(event, d, g, s);
            lb_change_input(event, d, g, s);
            g->rect.top = 0;
            g->position.y -= 3;
            g->rect.height = 21;
            d->t->position.y -= 3;
            sfSprite_setPosition(g->sprite, g->position);
            sfText_setPosition(d->t->text, d->t->position);
            sfSprite_setTextureRect(g->sprite, g->rect);
        }
    }
}

void animate_lb(game_obj *g, scene *s, sfEvent event)
{
    button *d = (button *) g->data;
    d->t->position = sfText_getPosition(d->t->text);
    g->position = sfSprite_getPosition(g->sprite);
    if (hover_on_btn(s, g->id)) {
        sfColor color = sfSprite_getColor(g->sprite);
        color.a = 135;
        sfSprite_setColor(g->sprite, color);
    } else {
        sfColor color = sfSprite_getColor(g->sprite);
        color.a = 255;
        sfSprite_setColor(g->sprite, color);
    }
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
    long_button_event(event, d, g, s);
}

int create_sprite_lb(scene *d, char *name, btn_param *p, char *text)
{
    sfVector2f pos[2] = {{p->pos.x, p->pos.y}, {0, 0}};
    game_obj *long_b =
        create_obj(d, name, create_rect(55, 21, 0, 0), pos);
    set_scale(d, long_b->sprite, p->scale);
    if (text != NULL)
        long_b->data = create_button_data(text, d, pos[0]);
    long_b->name = my_strdup(name);
    long_b->type = BUTTON;
    long_b->grp = p->grp;
    long_b->display = p->zindex;
    long_b->event = animate_lb;
    sfSprite_setTextureRect(long_b->sprite, long_b->rect);
    sfRenderWindow_drawSprite(d->hub->window, long_b->sprite, NULL);
    put_in_end(&d->objs, long_b);
    return 0;
}
