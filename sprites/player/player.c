/*
** EPITECH PROJECT, 2021
** MyRPG - Sprite
** File description:
** player sprite
*/

#include "../../include/rpg.h"

void print_life_bar_player(scene *d, player *p)
{
    life_percent(p->lb, p->hp);
    sfVector2f v = sfSprite_getPosition(p->inv->sprite);
    v.y -= 50;
    v.x = d->hub->mode.width / 2 - p->lb->rect.width / 2;
    sfSprite_setPosition(p->lb->sprite, v);
    sfRenderWindow_drawSprite(d->hub->window , p->lb->sprite, NULL);
}

player *create_player_data(scene *d)
{
    player *data = malloc(sizeof(player));
    data->old_time_an = sfTime_Zero;
    data->old_time_hit = sfTime_Zero;
    data->old_time_hp = sfTime_Zero;
    data->time = sfTime_Zero;
    data->state = IDLE;
    data->hp = 100;
    data->slot_select = 0;
    data->idle = idle_player_animation;
    data->move = move_player_animation;
    data->hit = hit_player_animation;
    data->inventory =
        create_inventory_data(d, 9, init_inventory_pos_places_p());
    data->animation_speed = 0.15;
    data->inv = create_inventory(d);
    data->lb = create_life_bar(500, 20, sfGreen, sfBlack);
    put_in_end(&d->objs, data->inv);
    put_in_end(&d->objs, create_slot_pointer(d));
    return data;
}

void create_player(scene *d)
{
    sfVector2f vector[2] = {{
            (d->hub->mode.width / 2) - ((48 * 6) / 2),
            (d->hub->mode.height / 2) - ((48 * 6) / 2)
        }, {0, 0}};
    sfIntRect rect = create_rect(48, 48, 0, 0);
    game_obj *hero = create_obj(d, "player", rect, vector);
    set_scale(d, hero->sprite, 6);
    hero->data = create_player_data(d);
    hero->type = PLAYER;
    hero->name = "player";
    hero->animate = animate_player;
    hero->event = event_player;
    hero->grp = ENTITY;
    hero->action = regeneration_player;
    hero->display = 4;
    sfSprite_setTextureRect(hero->sprite, hero->rect);
    sfRenderWindow_drawSprite(d->hub->window, hero->sprite, NULL);
    put_in_end(&d->objs, hero);
}
