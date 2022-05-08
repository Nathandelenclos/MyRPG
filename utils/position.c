/*
** EPITECH PROJECT, 2021
** MyRPG - utils
** File description:
** create position
*/

#include "../include/rpg.h"

sfVector2f *init_inventory_pos_places_p(void)
{
    sfVector2f *pos = malloc(sizeof(sfVector2f) * 9);
    for (int i = 0; i < 9; i++) {
        pos[i].x = 685 + i * 60.5;
        pos[i].y = 1015;
    }
    return (pos);
}

sfVector2f *init_inventory_pos_places_c(void)
{
    sfVector2f *pos = malloc(sizeof(sfVector2f) * 36);
    for (int i = 0; i < 36; i++) {
        if (i >= 0 && i < 9) {
            pos[i].x = 275 + i * 157;
            pos[i].y = 356 - 140;
        }
        if (i >= 9 && i < 18) {
            pos[i].x = 275 + (i - 9) * 157;
            pos[i].y = 356 + 157 - 140;
        }
        if (i >= 18 && i < 27) {
            pos[i].x = 275 + (i - 18) * 157;
            pos[i].y = 356 + 157 * 2 - 140;
        }
        if (i >= 27 && i < 36) {
            pos[i].x = 275 + (i - 27) * 157;
            pos[i].y = 869 - 140;
        }
    }
    return (pos);
}

int get_free_space_inv(inventory *inv)
{
    int i = 0;
    for (; inv->slot[i] != NULL; ++i);
    return i;
}

int check_point_on_window(sfVector2f p, scene *d)
{
    int width = d->hub->mode.width;
    int height = d->hub->mode.height;

    return p.x > 0 && p.x < width && p.y > 0 && p.y < height;
}

int is_on_window(game_obj *g, scene *d)
{
    if (d->state != PLAY)
        return 1;
    sfVector2f scale = sfSprite_getScale(g->sprite);
    sfVector2f left_top = sfSprite_getPosition(g->sprite);
    sfVector2f left_bottom =
    {left_top.x, left_top.y + (g->rect.height * scale.y)};
    sfVector2f right_top = {left_top.x + (g->rect.width * scale.x), left_top.y};
    sfVector2f right_bottom = {left_top.x + (g->rect.width * scale.x),
    left_top.y + (g->rect.height * scale.y)};
    sfVector2f points[5] = {left_top, left_bottom, right_top, right_bottom, 0};
    if (my_strcmp(g->name, "maps"))
        return 1;
    for (int i = 0; i < 5; ++i)
        if (check_point_on_window(points[i], d))
            return 1;
    return 0;
}
