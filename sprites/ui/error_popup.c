/*
** EPITECH PROJECT, 2021
** create long button
** File description:
** Sprite - create long button
*/

#include "../../include/rpg.h"

game_obj *create_sprite_popup(scene *d, sfVector2f p)
{
    sfVector2f pos[2] = {p, {0, 0}};
    game_obj *popup =
        create_obj(d, "popup", create_rect(723, 251, 0, 0), pos);
    set_scale(d, popup->sprite, 1);
    popup->name = "popup";
    popup->type = BUTTON;
    popup->grp = HOME_BTN;
    popup->display = 3;
    sfSprite_setTextureRect(popup->sprite, popup->rect);
    sfRenderWindow_drawSprite(d->hub->window, popup->sprite, NULL);
    put_in_end(&d->objs, popup);
    return popup;
}
