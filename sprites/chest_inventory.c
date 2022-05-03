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

chest_inventory *create_chest_inventory_data(scene *d)
{
    chest_inventory *data = malloc(sizeof(chest_inventory));
    data->pos = init_inventory_pos_places();
    data->state = FIRST_CLICK;
    sfIntRect rect = create_rect(1024, 1024, 0, 0);
    sfIntRect rect_empty = create_rect(140, 140, 0, 0);
    for (int i = 0; i < 36; i++) {
        if (i == 2) {
            data->slot_s[i] = sfSprite_create();
            data->slot_t[i] =  sfTexture_createFromFile
            ("./assets/logo.png", &rect);
            sfSprite_setPosition(data->slot_s[i], data->pos[i]);
            set_scale(d, data->slot_s[i], 0.1);
            sfSprite_setTexture(data->slot_s[i], data->slot_t[i], sfFalse);
            sfRenderWindow_drawSprite(d->hub->window, data->slot_s[i], NULL);
        } else {
            data->slot_s[i] = sfSprite_create();
            data->slot_t[i] =  sfTexture_createFromFile
            ("./assets/ui/inventory_empty_slot.png", &rect_empty);
            sfSprite_setTexture(data->slot_s[i], data->slot_t[i], sfFalse);
            sfSprite_setPosition(data->slot_s[i], data->pos[i]);
            sfRenderWindow_drawSprite(d->hub->window, data->slot_s[i], NULL);
        }
    }
    return data;
}

void create_chest_inventory_sprite(scene *d)
{
    sfVector2f vector[2] = {{d->hub->mode.width / 2 - 913 * 1.75 / 2,
    d->hub->mode.height / 2 - 490 * 1.75 / 2}, {0, 0}};
    sfIntRect rect = create_rect(913, 490, 0, 0);
    game_obj *hero = create_obj(d, "chest_inventory", rect, vector);
    set_scale(d, hero->sprite, 1.75);
    hero->data = create_chest_inventory_data(d);
    hero->name = "chest_inventory";
    hero->grp = UI;
    hero->display = 1;
    sfSprite_setTextureRect(hero->sprite, hero->rect);
    sfRenderWindow_drawSprite(d->hub->window, hero->sprite, NULL);
    put_in_end(&d->objs, hero);
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
