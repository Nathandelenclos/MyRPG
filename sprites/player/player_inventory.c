/*
** EPITECH PROJECT, 2021
** MyRPG - game object
** File description:
** create game object of inventory
*/

#include "../../include/rpg.h"

void event_slot(game_obj *g, scene *d, sfEvent event)
{
    player *p = get_object(d, "player")->data;
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == d->hub->s->c->slot1)
            p->slot_select = 0;
        if (event.key.code == d->hub->s->c->slot2)
            p->slot_select = 1;
        if (event.key.code == d->hub->s->c->slot3)
            p->slot_select = 2;
        if (event.key.code == d->hub->s->c->slot4)
            p->slot_select = 3;
        if (event.key.code == d->hub->s->c->slot5)
            p->slot_select = 4;
        if (event.key.code == d->hub->s->c->slot6)
            p->slot_select = 5;
        if (event.key.code == d->hub->s->c->slot7)
            p->slot_select = 6;
        if (event.key.code == d->hub->s->c->slot8)
            p->slot_select = 7;
        if (event.key.code == d->hub->s->c->slot9)
            p->slot_select = 8;
    }
}

void animate_slot(scene *d, game_obj *g)
{
    sfVector2f *v = init_inventory_pos_places_p();
    player *p = get_object(d, "player")->data;
    sfSprite_setPosition(g->sprite, v[p->slot_select]);
}

game_obj *create_inventory(scene *d)
{
    sfVector2f vector[2] = {
        {(d->hub->mode.width / 2) - (543 / 2),
            (d->hub->mode.height - 61 )
            }, {0, 0}};
    sfIntRect rect = create_rect(543, 61, 0, 0);
    game_obj *obj = create_obj(d, "hotbar", rect, vector);
    obj->data = malloc(sizeof(player_inv));
    player_inv *inv = obj->data;
    inv->slots = malloc(sizeof(slot_inv *) * 10);
    for (int i = 0; i < 9; ++i) {
        inv->slots[i] = malloc(sizeof(slot_inv));
        inv->slots[i]->obj = NULL;
        inv->slots[i]->texture = NULL;
        inv->slots[i]->sprite = NULL;
    }
    obj->type = INV;
    obj->name = "inventory";
    obj->grp = UI;
    obj->display = 2;
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    sfRenderWindow_drawSprite(d->hub->window, obj->sprite, NULL);
    return obj;
}

game_obj *create_slot_pointer(scene *d)
{
    sfVector2f *v = init_inventory_pos_places_p();
    sfVector2f vector[2] = {{v[0].x + 12, v[0].y + 13}, {0, 0}};
    sfIntRect rect = create_rect(60, 61, 0, 0);
    game_obj *obj = create_obj(d, "slot_pointer", rect, vector);
    obj->type = INV;
    obj->name = "slot_pointer";
    obj->event = event_slot;
    obj->animate = animate_slot;
    obj->grp = UI;
    obj->display = 4;
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    sfRenderWindow_drawSprite(d->hub->window, obj->sprite, NULL);
    free(v);
    return obj;
}
