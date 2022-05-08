/*
** EPITECH PROJECT, 2021
** trees.c
** File description:
** Created by Bastien Mazzolini
*/

#include "../../include/rpg.h"

void action_tree(game_obj *g, scene *d)
{
    tree *p = (tree *) g->data;
    game_obj *map = get_object(d, "maps");
    sfVector2f pos_map = sfSprite_getPosition(map->sprite);

    p->fruit(d, g);
    pos_map.x += g->vector.x * 9.0;
    pos_map.y += g->vector.y * 9.0;
    sfSprite_setPosition(g->sprite, pos_map);
}

void fruit_tree(scene *d, game_obj *g)
{
    tree *data = (tree *) g->data;
    float seconds;
    float old_seconds;
    sfIntRect rect;

    if (data->state != NO_FRUIT)
        return;
    data->time = sfClock_getElapsedTime(g->clock);
    seconds = sfTime_asSeconds(data->time);
    old_seconds = sfTime_asSeconds(data->old_time_fruit);
    if (seconds - old_seconds >= data->regen) {
        rect = sfSprite_getTextureRect(g->sprite);
        rect.left = 48;
        if (rect.left > g->texture->rect.width - 48)
            rect = g->rect;
        sfSprite_setTextureRect(g->sprite, rect);
        data->old_time_fruit = sfClock_getElapsedTime(g->clock);
        data->state = FRUIT;
    }
}

tree *create_tree_data(scene *d)
{
    tree *data = malloc(sizeof(tree));

    data->time = sfTime_Zero;
    data->old_time_fruit = sfTime_Zero;
    data->state = NO_FRUIT;
    data->regen = rand() % ((60 + 1) - 10) + 10;
    data->fruit = fruit_tree;
    return (data);
}

void event_tree(game_obj *g, scene *d, sfEvent event)
{
    game_obj *p = get_object(d, "player");
    game_obj *obj = get_closer_object(d, p, TREES);
    float distance = get_distance(p, obj);
    player *p_data = p->data;
    tree *t = (tree *) obj->data;

    if (t->state != FRUIT)
        return;
    if (sfKeyboard_isKeyPressed(d->hub->s->c->interact) && distance < 170) {
        obj->rect.left = 0;
        sfSprite_setTextureRect(obj->sprite, obj->rect);
        t->old_time_fruit = sfClock_getElapsedTime(obj->clock);
        if (rand() % 10 == 1)
            push_items(p_data->inventory, get_free_space_inv(p_data->inventory),
                create_golden_apple(d));
        else
            push_items(p_data->inventory, get_free_space_inv(p_data->inventory),
                create_apple(d));
        t->state = NO_FRUIT;
    }
}

void create_tree(scene *d, sfVector2f pos)
{
    sfVector2f vector_tree[2] = {pos, pos};
    sfIntRect rect = create_rect(48, 64, 0, 80);
    game_obj *tree = create_obj(d, "objects", rect, vector_tree);
    game_obj *map = get_object(d, "maps");
    sfVector2f pos_map = sfSprite_getPosition(map->sprite);

    set_scale(d, tree->sprite, 6);
    tree->data = create_tree_data(d);
    tree->type = TREE;
    tree->name = my_strdup("objects");
    tree->action = action_tree;
    tree->event = event_tree;
    tree->grp = TREES;
    tree->display = 1;
    pos_map.x += pos.x * 9.0;
    pos_map.y += pos.y * 9.0;
    sfSprite_setPosition(tree->sprite, pos_map);
    sfSprite_setTextureRect(tree->sprite, tree->rect);
    sfRenderWindow_drawSprite(d->hub->window, tree->sprite, NULL);
    put_in_end(&d->objs, tree);
}
