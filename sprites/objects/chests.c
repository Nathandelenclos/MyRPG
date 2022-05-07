/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** chests
*/

#include "../../include/rpg.h"

void push_items(inventory *ci, int i, game_obj *obj)
{
    if (obj == NULL)
        return;
    ci->slot[i] = malloc(sizeof(slot_inv));
    ci->slot[i]->obj = obj;
    ci->slot[i]->sprite = sfSprite_create();
    ci->slot[i]->rect = obj->rect;
    ci->slot[i]->texture = obj->texture->texture;
    sfSprite_setTexture(ci->slot[i]->sprite, ci->slot[i]->texture, sfTrue);
    sfSprite_setTextureRect(ci->slot[i]->sprite, ci->slot[i]->rect);
}

void action_chest(game_obj *obj, scene *d)
{
    game_obj *map = get_object(d, "maps");
    chest *data = obj->data;
    sfVector2f pos_map = sfSprite_getPosition(map->sprite);
    pos_map.x += obj->vector.x * 9.0;
    pos_map.y += obj->vector.y * 9.0;
    sfSprite_setPosition(obj->sprite, pos_map);
    if (get_distance(get_object(d, "player"), obj) < 150) {
        data->state= OPEN;
        data->open(d, obj);
    }
    else if (get_distance(get_object(d, "player"), obj) > 150) {
        data->state= CLOSE;
        data->close(d, obj);
    }
}

void create_basic_chest(scene *d, float x, float y)
{
    sfVector2f vector[2] = {{-50, -50}, {x, y}};
    sfIntRect rect = create_rect(16, 16, 0, 0);
    game_obj *hero = create_obj(d, "basic_chest", rect, vector);
    set_scale(d, hero->sprite, 5);
    hero->data = create_chest_data(d);
    hero->type = CHESTS;
    hero->name = "basic_chest";
    hero->grp = CHESTS_G;
    hero->display = 1;
    hero->action = action_chest;
    sfSprite_setTextureRect(hero->sprite, hero->rect);
    sfRenderWindow_drawSprite(d->hub->window, hero->sprite, NULL);
    put_in_end(&d->objs, hero);
}

void create_golden_chest(scene *d)
{
    sfVector2f vector[2] = {{100, 100}, {0, 0}};
    sfIntRect rect = create_rect(16, 16, 0, 0);
    game_obj *hero = create_obj(d, "golden_chest", rect, vector);
    set_scale(d, hero->sprite, 5);
    hero->data = create_chest_data(d);
    hero->type = CHESTS;
    hero->name = "golden_chest";
    hero->grp = CHESTS_G;
    hero->display = 1;
    sfSprite_setTextureRect(hero->sprite, hero->rect);
    sfRenderWindow_drawSprite(d->hub->window, hero->sprite, NULL);
    put_in_end(&d->objs, hero);
}
