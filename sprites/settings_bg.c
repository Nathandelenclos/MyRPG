/*
** EPITECH PROJECT, 2021
** create long button
** File description:
** Sprite - create long button
*/

#include "../include/rpg.h"

int create_settings_menu_sprite(scene *d)
{
    sfVector2f pos[2] = {{0, 0}, {0, 0}};
    game_obj *menu =
        create_obj(d, "settings", create_rect(1280, 720, 0, 0), pos);
    sfVector2f resize = {1.5, 1.5};
    sfSprite_setScale(menu->sprite, resize);
    menu->type = MENU_BG;
    menu->name = "settings";
    menu->grp = HOME_BTN;
    menu->display = 1;
    sfSprite_setTextureRect(menu->sprite, menu->rect);
    sfRenderWindow_drawSprite(d->hub->window, menu->sprite, NULL);
    put_in_end(&d->objs, menu);
    return 0;
}

int create_settings_hud_sprite(scene *d)
{
    sfVector2f pos[2] = {{0, 0}, {0, 0}};
    game_obj *menu =
        create_obj(d, "hud_settings", create_rect(1280, 720, 0, 0), pos);
    sfVector2f resize = {1.5, 1.5};
    sfSprite_setScale(menu->sprite, resize);
    menu->type = MENU_BG;
    menu->name = "hud_settings";
    menu->grp = HOME_BTN;
    menu->display = 2;
    sfSprite_setTextureRect(menu->sprite, menu->rect);
    sfRenderWindow_drawSprite(d->hub->window, menu->sprite, NULL);
    put_in_end(&d->objs, menu);
    return 0;
}
