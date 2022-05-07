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

void action_click_on_case(
    int i, sfMouseButtonEvent event, sfVector2f pos,
    inventory *data
)
{
    if (event.x >= pos.x && event.x <= pos.x + 140 && event.y >= pos.y &&
        event.y <= pos.y + 140) {
        if (data->state == FIRST_CLICK) {
            data->stamp = data->slot[i];
            data->stamp = data->slot[i];
            data->state = SECOND_CLICK;
        } else {
            data->slot[i] = data->stamp;
            data->slot[i] = data->stamp;
            sfSprite_setPosition(data->slot[i]->sprite, data->pos[i]);
            data->state = FIRST_CLICK;
        }
    }
}

void events_chest(scene *d, sfEvent event)
{
    game_obj *g = get_object(d, "chest_inventory");
    inventory *data = (inventory *) g->data;
    events_manage(d, event);
    switch (event.type) {
    case sfEvtClosed:
        sfRenderWindow_close(d->hub->window);
        break;
    case sfEvtKeyPressed:
        if (event.key.code == sfKeyEscape)
            switch_scene(d, PLAY);
        break;
        /*case sfEvtMouseButtonPressed:
            for (int i = 0; i < 36; i++) {
                action_click_on_case(i, event.mouseButton, data->pos[i], data);
            }
            break;*/
    }
}

void display_chest(scene *d, inventory *ci)
{
    double f = 0.0;
    double y = 0.0;
    for (int i = 0; i < 27; ++i) {
        if (ci->slot[i] != NULL) {
            f = (ci->slot[i]->rect.width / 140.0);
            y = 1 / f;
            set_scale(d, ci->slot[i]->sprite, y);
            sfSprite_setPosition(ci->slot[i]->sprite, ci->pos[i]);
            sfRenderWindow_drawSprite(d->hub->window, ci->slot[i]->sprite, NULL);
        }
    }
}

void chest_screen(scene *data)
{
    sprites_manager(data);
    move_manager(data);
    time_manager(data);
    text_manager(data);
    game_obj *obj = get_closer_object(get_scene(data, PLAY),
        get_object(get_scene(data, PLAY), "player"), CHESTS_G);
    display_chest(data, ((chest *) obj->data)->inventory);
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
