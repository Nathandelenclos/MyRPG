/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** display money
*/

#include "../include/rpg.h"

void animate_entity(text *t, scene *d)
{
    char *points = my_int_to_str(d->hub->entity_load);
    char points_s[255];
    points_s[0] = '\0';
    my_strcat(points_s, "Sprite Load: ");
    my_strcat(points_s, points);
    modify_string(d, t->string, points_s);
}

void display_sprite_load(scene *d)
{
    char *points = my_int_to_str(d->hub->entity_load);
    char points_s[255];
    points_s[0] = '\0';
    my_strcat(points_s, "Loaded sprite: ");
    my_strcat(points_s, points);
    sfVector2f pos = {0, 50};
    text *t = create_text("./assets/fonts/motion-control.bold.otf",
        points_s, sfWhite, pos);
    t->animate = animate_entity;
    t->name = my_strdup("entity");
    t->display = 0;
    sfText_setCharacterSize(t->text, 50);
    put_in_list(&d->texts, t);
}

void create_debug(scene *d)
{
    if (get_text(d, "fps") == NULL)
        display_fps(d);
    if (get_text(d, "entity") == NULL)
        display_sprite_load(d);
    if (get_text(d, "delta_time") == NULL)
        display_delta_time(d);
}
