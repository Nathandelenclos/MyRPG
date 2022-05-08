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

void display_chest(scene *d, inventory *ci)
{
    double f = 0.0;
    double y = 0.0;
    for (int i = 0; i < ci->size; ++i) {
        if (ci->slot[i] != NULL) {
            ci->pos = d->state == CHEST ? init_inventory_pos_places_c()
                                        : inventory_pos_places_p();
            f = (ci->slot[i]->rect.width / (d->state == CHEST ? 140.0 : 70.0));
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
    sfColor c = sfSprite_getColor(g->sprite);
    c.a = 135;
    sfSprite_setColor(g->sprite, c);
    sfSprite_setTexture(g->sprite, texture, sfTrue);
    sfRenderWindow_setMouseCursorVisible(new->hub->window, sfTrue);
}
