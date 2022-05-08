/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** chest_inventory
*/

#include "../include/rpg.h"

sfVector2f *init_inventory_pos_places(void)
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

void create_chest_inventory_sprite(scene *d)
{
    sfVector2f vector[2] = {{
        d->hub->mode.width / 2 - 913 * 1.75 / 2,
        d->hub->mode.height / 2 - 490 * 1.75 / 2
    }, {0, 0}};
    sfIntRect rect = create_rect(913, 490, 0, 0);
    game_obj *hero = create_obj(d, "chest_inventory", rect, vector);
    set_scale(d, hero->sprite, 1.75);
    put_in_end(&d->objs, hero);
    hero->name = "chest_inventory";
    hero->grp = UI;
    hero->display = 1;
    sfSprite_setTextureRect(hero->sprite, hero->rect);
    sfRenderWindow_drawSprite(d->hub->window, hero->sprite, NULL);
}

void create_chest_background_sprite(scene *d)
{
    sfVector2f vector[2] = {{0, 0}, {0, 0}};
    sfIntRect rect = create_rect(1920, 1080, 0, 0);
    game_obj *hero = create_obj(d, NULL, rect, vector);
    hero->name = "background";
    hero->grp = UI;
    hero->display = 1;
    sfSprite_setTextureRect(hero->sprite, hero->rect);
    sfRenderWindow_drawSprite(d->hub->window, hero->sprite, NULL);
    put_in_end(&d->objs, hero);
}
