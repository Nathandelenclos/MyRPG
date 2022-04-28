/*
** EPITECH PROJECT, 2021
** MyRPG - Game Object
** File description:
** Game object slime
*/

#include "../../include/rpg.h"

void animate_slime(scene *d, game_obj *g)
{
    slime *data = (slime *) g->data;
    switch (data->state) {
    case HIT:
        data->hit(d, g);
        break;
    case DESTROY:
        data->destroy(d, g);
        break;
    case IDLE:
        data->idle(d, g);
        break;
    case JUMP:
        data->jump(d, g);
        break;
    case MOVE:
        data->move(d, g);
        break;
    default:
        data->idle(d, g);
    }
}

slime *create_slime_data(void)
{
    slime *data = malloc(sizeof(slime));
    data->old_time_an = sfTime_Zero;
    data->state = HIT;
    data->time = sfTime_Zero;
    data->destroy = destroy_animate_slime;
    data->hit = hit_animate_slime;
    data->jump = jump_animate_slime;
    data->idle = idle_animate_slime;
    data->move = move_animate_slime;
    return data;
}

void create_slime_(scene *d, int x, int y, char *name)
{
    sfVector2f vector[2] = {{x, y}, {2, 1.2}};
    sfIntRect rect = create_rect(32, 32, 0, 0);
    game_obj *hero = create_obj(d, name, rect, vector);
    set_scale(d, hero->sprite, 5);;
    hero->data = create_slime_data();
    hero->type = SLIME;
    hero->name = my_strdup(name);
    hero->animate = animate_slime;
    hero->grp = ENTITY;
    hero->display = 1;
    sfSprite_setTextureRect(hero->sprite, hero->rect);
    sfRenderWindow_drawSprite(d->hub->window, hero->sprite, NULL);
    put_in_end(&d->objs, hero);
}

void create_slime(scene *d, int x, int y, slime_type type)
{
    switch (type) {
    case BLACK:
        create_slime_(d, x, y, "enemy_slime");
        break;
    case BLUE:
        create_slime_(d, x, y, "slime");
        break;
    case GREEN:
        create_slime_(d, x, y, "green_slime");
        break;
    case PINK:
        create_slime_(d, x, y, "pink_slime");
        break;
    case YELLOW:
        create_slime_(d, x, y, "yellow_slime");
        break;
    }
}
