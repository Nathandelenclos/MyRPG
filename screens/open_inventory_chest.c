/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** open_inventory_chest
*/

#include "../include/rpg.h"
#include "../include/my.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

void action_click_on_case(scene *d, int i, sfMouseButtonEvent event, inventory *data)
{
    sfVector2f *pos = d->state == CHEST ? init_inventory_pos_places_c() : init_inventory_pos_places_p();
    static slot_inv *stamp = NULL;
    static int stamp_i = -1;
    static inventory *stamp_inv = NULL;
    static inventory_chest_state state = FIRST_CLICK;
    printf("i => %i, pos[i].x => %f, pos[i].y => %f\n", i, pos[i].x, pos[i].y);
    if (event.x >= pos[i].x && event.x <= pos[i].x + 140 && event.y >= pos[i].y &&
        event.y <= pos[i].y + 140) {
        printf("%i\n", i);
        if (data->size == 9 && i >= 27)
            i -= 27;
        printf("%i\n", i);
        if (state == FIRST_CLICK) {
            stamp = data->slot[i];
            stamp_i = i;
            stamp_inv = data;
            printf("FIRST CLICK\n");
            state = SECOND_CLICK;
        } else {
            stamp_inv->slot[stamp_i] = data->slot[i];
            data->slot[i] = stamp;
            printf("SECOND CLICK\n");
            state = FIRST_CLICK;
        }
    }
    free(pos);
}

void events_chest(scene *d, sfEvent event)
{
    events_manage(d, event);
    scene *play = get_scene(d, PLAY);
    game_obj *p = get_object(play, "player");
    game_obj *c = get_closer_object(play, p, CHESTS_G);
    inventory *inv = NULL;
    switch (event.type) {
    case sfEvtClosed:
        sfRenderWindow_close(d->hub->window);
        break;
    case sfEvtKeyPressed:
        if (event.key.code == sfKeyEscape) {
            switch_scene(d, PLAY);
            action_click_on_case(d, 0, event.mouseButton, NULL);
        }
        break;
    case sfEvtMouseButtonPressed:
        for (int i = 0; i < 36; i++) {
            inv = i >= 27 ? ((player *)p->data)->inventory: ((chest *)c->data)->inventory;
            action_click_on_case(d, i, event.mouseButton, inv);
        }
        break;
    }
}

void display_chest(scene *d, inventory *ci)
{
    double f = 0.0;
    double y = 0.0;
    for (int i = 0; i < ci->size; ++i) {
        if (ci->slot[i] != NULL) {
            ci->pos = d->state == CHEST ? init_inventory_pos_places_c()
                                        : init_inventory_pos_places_p();
            f = (ci->slot[i]->rect.width / 140.0);
            y = 1 / f;
            set_scale(d, ci->slot[i]->sprite, y);
            sfSprite_setPosition(ci->slot[i]->sprite,
                ci->pos[d->state == CHEST && ci->size == 9 ? i + 27 : i]);

            sfRenderWindow_drawSprite(d->hub->window, ci->slot[i]->sprite,
                NULL);
            free(ci->pos);
        }
    }
}

void chest_screen(scene *data)
{
    sprites_manager(data);
    move_manager(data);
    time_manager(data);
    text_manager(data);
    scene *play = get_scene(data, PLAY);
    game_obj *obj = get_closer_object(play,
        get_object(play, "player"), CHESTS_G);
    game_obj *p = get_object(play, "player");
    display_chest(data, ((chest *) obj->data)->inventory);
    display_chest(data, ((player *) p->data)->inventory);
}

void create_chest_scene_data(scene *d)
{
    d->textures = get_scene(d, START)->textures;
    create_chest_background_sprite(d);
    create_chest_inventory_sprite(d);
}

void save_chest_background(scene *old, scene *new)
{
    sfTexture *texture =
        sfTexture_create(old->hub->mode.width, old->hub->mode.height);
    sfTexture_updateFromRenderWindow(texture, old->hub->window, 0, 0);
    game_obj *g = get_object(new, "background");
    sfSprite_setTexture(g->sprite, texture, sfTrue);
    sfRenderWindow_setMouseCursorVisible(new->hub->window, sfTrue);
}

void data_chest(screen *screen1)
{
    scene *d = create_scene(screen1, CHEST);
    d->screen = chest_screen;
    d->event = events_chest;
    d->active = save_chest_background;
    create_chest_scene_data(d);
    put_in_list(&screen1->datas, d);
}
