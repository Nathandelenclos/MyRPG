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
            switch_scene(d, START);
        if (event.key.code == d->hub->s->c->interact && get_distance(p, chest) < 150)
            switch_scene(d, CHEST);
        break;
    }
}

void play_screen(scene *data)
{
    sprites_manager(data);
    move_manager(data);
    time_manager(data);
    text_manager(data);
    env_manager(data);
    game_obj *p = get_object(data, "player");
    if (p != NULL)
        display_chest(data, ((player *) p->data)->inventory);
}

void create_all_slimes(scene *d)
{
    create_slime
        (d, create_vector2f(530, 220), PINK, create_vector2f(9, 2));
    create_slime
        (d, create_vector2f(520, 180), PINK, create_vector2f(9, 2));
    create_slime
        (d, create_vector2f(580, 205), PINK, create_vector2f(9, 2));
    create_slime
        (d, create_vector2f(630, 180), PINK, create_vector2f(9, 2));
    create_slime
        (d, create_vector2f(630, 220), PINK, create_vector2f(9, 2));
    create_slime
        (d, create_vector2f(280, 180), BLUE, create_vector2f(12, 3));
    create_slime
        (d, create_vector2f(280, 90), BLUE, create_vector2f(12, 3));
    create_slime
        (d, create_vector2f(350, 155), BLUE, create_vector2f(12, 3));
    create_slime
        (d, create_vector2f(400, 90), BLUE, create_vector2f(12, 3));
    create_slime
        (d, create_vector2f(400, 180), BLUE, create_vector2f(12, 3));
    create_slime
        (d, create_vector2f(530, 410), GREEN, create_vector2f(15, 4));
    create_slime
        (d, create_vector2f(530, 330), GREEN, create_vector2f(15, 4));
    create_slime
        (d, create_vector2f(595, 370), GREEN, create_vector2f(15, 4));
    create_slime
        (d, create_vector2f(670, 330), GREEN, create_vector2f(15, 4));
    create_slime
        (d, create_vector2f(670, 410), GREEN, create_vector2f(15, 4));
    create_slime
        (d, create_vector2f(480, 610), YELLOW, create_vector2f(18, 5));
    create_slime
        (d, create_vector2f(480, 500), YELLOW, create_vector2f(18, 5));
    create_slime
        (d, create_vector2f(530, 560), YELLOW, create_vector2f(18, 5));
    create_slime
        (d, create_vector2f(570, 500), YELLOW, create_vector2f(18, 5));
    create_slime
        (d, create_vector2f(570, 610), YELLOW, create_vector2f(18, 5));
    create_slime
        (d, create_vector2f(280, 570), BLACK, create_vector2f(24, 7));
    create_slime
        (d, create_vector2f(310, 518), BLACK, create_vector2f(24, 7));
    create_slime
        (d, create_vector2f(365, 491), BLACK, create_vector2f(24, 7));
    create_slime
        (d, create_vector2f(290, 483), BLACK, create_vector2f(24, 7));
    create_slime
        (d, create_vector2f(307, 440), BLACK, create_vector2f(24, 7));
}

void create_all_trees(scene *d)
{
    create_tree(d, create_vector2f(270, 420));
    create_tree(d, create_vector2f(444, 298));
    create_tree(d, create_vector2f(592, 434));
    create_tree(d, create_vector2f(190, 300));
    create_tree(d, create_vector2f(160, 200));
    create_tree(d, create_vector2f(160, 418));
    create_tree(d, create_vector2f(320, 350));
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
