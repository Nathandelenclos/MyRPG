/*
** EPITECH PROJECT, 2021
** bed.c
** File description:
** Created by Bastien Mazzolini
*/

#include "../../include/rpg.h"

void action_bed(game_obj *g, scene *d)
{
    game_obj *map = get_object(d, "maps");
    sfVector2f pos_map = sfSprite_getPosition(map->sprite);
    pos_map.x += g->vector.x * 9.0;
    pos_map.y += g->vector.y * 9.0;
    sfSprite_setPosition(g->sprite, pos_map);
}

void create_bed(scene *d, sfVector2f pos)
{
    sfVector2f vector_bed[2] = {pos, pos};
    sfIntRect rect = create_rect(16, 30, 176, 32);
    game_obj *bed = create_obj(d, "objects", rect, vector_bed);
    game_obj *map = get_object(d, "maps");
    sfVector2f pos_map = sfSprite_getPosition(map->sprite);

    set_scale(d, bed->sprite, 6);
    bed->type = BED;
    bed->name = my_strdup("objects");
    bed->action = action_bed;
//    bed->event = event_bed;
    bed->grp = OBJECT;
    bed->display = 1;
    pos_map.x += pos.x * 9.0;
    pos_map.y += pos.y * 9.0;
    sfSprite_setPosition(bed->sprite, pos_map);
    sfSprite_setTextureRect(bed->sprite, bed->rect);
    sfRenderWindow_drawSprite(d->hub->window, bed->sprite, NULL);
    put_in_end(&d->objs, bed);
}
