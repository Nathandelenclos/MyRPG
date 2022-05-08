/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** regeneration
*/

#include "../../include/rpg.h"

void effects_regeneration(scene *d, player *p)
{
    if (p->hp > 0 && p->hp <= 15)
        get_env(d, LOW_LIFE)->active = sfTrue;
    else
        get_env(d, LOW_LIFE)->active = sfFalse;
    p->lb->main_color = sfColor_fromRGB(255 - (255 * p->hp / 100),
        (float )(p->hp) * 2.55, 0);
}

void regeneration_player2(game_obj *g, scene *d, player *p, sfVector2f sec)
{
    if (sec.x - sec.y >= 0.2 && p->hp > 0 && p->hp < 100) {
        p->hp += 1;
        p->old_time_hp = sfClock_getElapsedTime(g->clock);
    }
    if (p->hp >= 100)
        get_env(d, REGEN)->active = sfFalse;
    else
        get_env(d, REGEN)->active = sfTrue;
}

void regeneration_player(game_obj *g, scene *d)
{
    game_obj *map = get_object(d, "maps");
    player *p = (player *) g->data;
    sfVector2f pos_mapbg = sfSprite_getPosition(map->sprite);
    sfVector2f pos_maphd = pos_mapbg;
    sfVector2f pos_player = sfSprite_getPosition(g->sprite);
    pos_mapbg.x += 276 * 9.0;
    pos_mapbg.y += 303 * 9.0;
    pos_maphd.x += 341 * 9.0;
    pos_maphd.y += 225 * 9.0;
    p->time = sfClock_getElapsedTime(g->clock);
    float seconds = sfTime_asSeconds(p->time);
    float old_seconds = sfTime_asSeconds(p->old_time_hp);
    if (pos_player.x + 144 >= pos_mapbg.x && pos_player.x + 144 <= pos_maphd.x
    && pos_player.y + 144 <= pos_mapbg.y && pos_player.y + 144 >= pos_maphd.y
    && g->display)
        regeneration_player2(g, d, p, create_vector2f(seconds, old_seconds));
    else
        get_env(d, REGEN)->active = sfFalse;
    effects_regeneration(d, p);
}
