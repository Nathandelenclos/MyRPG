/*
** EPITECH PROJECT, 2021
** MyRPG - game object
** File description:
** create game object of inventory
*/

#include "../../include/rpg.h"

game_obj *create_inventory(scene *d)
{
    sfVector2f vector[2] = {
        {(d->hub->mode.width / 2) - ((543 * 6) / 2),
            (d->hub->mode.height - 61)
        }, {0, 0}};
    sfIntRect rect = create_rect(543, 61, 0, 0);
    game_obj *obj = create_obj(d, "hotbar", rect, vector);
    obj->type = INV;
    obj->name = "inventory";
    obj->grp = UI;
    obj->display = 2;
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    sfRenderWindow_drawSprite(d->hub->window, obj->sprite, NULL);
    return obj;
}
