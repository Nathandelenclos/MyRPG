/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** slime_animation2
*/

#include "../../include/rpg.h"

void destroy_display(scene *d, game_obj *g, player *p_data)
{
    if (g->display != 0)
        push_items(p_data->inventory,
            get_free_space_inv(p_data->inventory), obj_dup(d, g));
    g->display = 0;
}
