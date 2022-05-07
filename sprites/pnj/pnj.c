/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** pnj
*/

#include "../../include/rpg.h"

void animate_pnj(scene *d, game_obj *g)
{
    pnj_simon *data = (pnj_simon *)g->data;
    data->time = sfClock_getElapsedTime(g->clock);
    float seconds = sfTime_asSeconds(data->time);
    float old_seconds = sfTime_asSeconds(data->old_time_an);
    if (seconds - old_seconds >= 0.23) {
        sfIntRect rect = sfSprite_getTextureRect(g->sprite);
        rect.left += 48;
        rect.top = 0;
        if (rect.left > g->texture->rect.width - 48)
            rect = g->rect;
        sfSprite_setTextureRect(g->sprite, rect);
        data->old_time_an = sfClock_getElapsedTime(g->clock);
    }
}

void action_pnj_simon(game_obj *g, scene *d)
{
    game_obj *map = get_object(d, "maps");
    game_obj *p = get_object(d, "pnj_simon");
    sfVector2f pos_map = sfSprite_getPosition(map->sprite);
    pos_map.x += g->vector.x * 9.0;
    pos_map.y += g->vector.y * 9.0;
    sfSprite_setPosition(g->sprite, pos_map);
}

pnj_simon *create_pnj_simon_data(scene *d)
{
    pnj_simon *data = malloc(sizeof(pnj_simon));
    data->old_time_an = sfTime_Zero;
    data->time = sfTime_Zero;
    return data;
}

void create_pnj_simon(scene *d, sfVector2f pos)
{
    sfVector2f vector[2] = {pos, pos};
    sfIntRect rect = create_rect(48, 35, 0, 0);
    game_obj *hero = create_obj(d, "pnj_simon", rect, vector);
    game_obj *map = get_object(d, "maps");
    sfVector2f pos_map = sfSprite_getPosition(map->sprite);
    set_scale(d, hero->sprite, 6);
    hero->data = create_pnj_simon_data(d);
    hero->type = PNJ;
    hero->name = "pnj_simon";
    hero->animate = animate_pnj;
    hero->grp = PNJ_ENTITY;
    hero->action = action_pnj_simon;
    hero->display = 1;
    pos_map.x += pos.x * 9.0;
    pos_map.y += pos.y * 9.0;
    sfSprite_setPosition(hero->sprite, pos_map);
    sfSprite_setTextureRect(hero->sprite, hero->rect);
    sfRenderWindow_drawSprite(d->hub->window, hero->sprite, NULL);
    put_in_end(&d->objs, hero);
}

game_obj *create_big_pnj(scene *d, sfVector2f pos, int scale)
{
    sfVector2f vector[2] = {pos, pos};
    sfIntRect rect = create_rect(48, 35, 0, 0);
    game_obj *hero = create_obj(d, NULL, rect, vector);
    set_scale(d, hero->sprite, scale);
    hero->type = PNJ;
    hero->name = "big_pnj";
    hero->grp = PNJ_ENTITY;
    hero->display = 1;
    sfSprite_setPosition(hero->sprite, pos);
    sfSprite_setTextureRect(hero->sprite, hero->rect);
    sfRenderWindow_drawSprite(d->hub->window, hero->sprite, NULL);
    put_in_end(&d->objs, hero);
    return hero;
}
