/*
** EPITECH PROJECT, 2021
** create long button
** File description:
** Sprite - create long button
*/

#include "../include/rpg.h"

menu_bg *create_menu_struct(void)
{
    menu_bg *data = malloc(sizeof(menu_bg));
    data->old_time_an = sfTime_Zero;
    data->time = sfTime_Zero;
    return data;
}

void animate_menu(scene *s, game_obj *g)
{
    menu_bg *data = (menu_bg *)g->data;
    data->time = sfClock_getElapsedTime(g->clock);
    float seconds = sfTime_asSeconds(data->time);
    float old_seconds = sfTime_asSeconds(data->old_time_an);
    if (seconds - old_seconds >= 0.05) {
        if (g->rect.left < 7800)
            g->rect.left += 600;
        else
            g->rect.left = 0;
        sfSprite_setTextureRect(g->sprite, g->rect);
        data->old_time_an = sfClock_getElapsedTime(g->clock);
    }
}

int create_sprite_menu(scene *d)
{
    sfVector2f pos[2] = {{0, -50}, {0, 0}};
    game_obj *menu =
        create_obj(d, "menu", create_rect(600, 450, 0, 0), pos);
    sfVector2f resize = {d->hub->mode.width / 600.0, d->hub->mode.width / 600.0};
    sfSprite_setScale(menu->sprite, resize);
    menu->data = create_menu_struct();
    menu->type = MENU_BG;
    menu->name = "menu";
    menu->grp = HOME_BTN;
    menu->display = 1;
    menu->animate = animate_menu;
    sfSprite_setTextureRect(menu->sprite, menu->rect);
    sfRenderWindow_drawSprite(d->hub->window, menu->sprite, NULL);
    put_in_end(&d->objs, menu);
    return 0;
}
