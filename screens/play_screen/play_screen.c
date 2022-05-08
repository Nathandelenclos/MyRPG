/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** Screen
*/

#include "../../include/my.h"
#include "../../include/rpg.h"
#include <SFML/Window.h>
#include <SFML/Graphics.h>

void events_play(scene *d, sfEvent event)
{
    events_manage(d, event);
    game_obj *p = get_object(d, "player");
    game_obj *chest = get_closer_object(d, p, CHESTS_G);
    switch (event.type) {
    case sfEvtClosed:
        sfRenderWindow_close(d->hub->window);
        break;
    case sfEvtKeyPressed:
        if (event.key.code == d->hub->s->c->menu)
            switch_scene(d, PAUSE);
        if (event.key.code == d->hub->s->c->interact &&
            get_distance(p, chest) < 150)
            switch_scene(d, CHEST);
        if (sfKeyboard_isKeyPressed(sfKeyF12))
            switch_scene(d, WIN);
        break;
    }
}

void create_data_play(scene *d)
{
    d->textures = get_scene(d, START)->textures;
    create_env(d);
    create_sprite_map(d);
    create_player(d);
    create_pnj(d, create_vector2f(269, 281));
    create_all_slimes(d);
    create_bed(d, create_vector2f(292, 227));
    create_all_trees(d);
    display_fps(d);
    create_basic_chest(d, 304, 225);
    create_golden_chest(d, 328, 225);
    game_obj *p = get_object(d, "player");
    game_obj *c = get_closer_object(d, p, CHESTS_G);
    chest *ci = c->data;
    push_items(ci->inventory, 0, create_apple(d));
}

void active_play(scene *old, scene *new)
{
    sfRenderWindow_setMouseCursorVisible(new->hub->window, sfFalse);
    fade_scene(old);
}

void data_play(screen *screen1)
{
    scene *d = create_scene(screen1, PLAY);
    d->screen = play_screen;
    d->event = events_play;
    d->active = active_play;
    create_data_play(d);
    put_in_list(&screen1->datas, d);
}
