/*
** EPITECH PROJECT, 2021
** MyRPG - text
** File description:
** display delta time
*/

#include "../include/rpg.h"

void animate_delta(text *t, scene *d)
{
    char *points = my_int_to_str(d->hub->delta_time);
    char points_s[255];
    points_s[0] = '\0';
    my_strcat(points_s, "Delta time: ");
    my_strcat(points_s, points);
    modify_string(d, t->string, points_s);
}

void display_delta_time(scene *d)
{
    char *points = my_int_to_str(d->hub->delta_time);
    char points_s[255];
    points_s[0] = '\0';
    my_strcat(points_s, "Delta time: ");
    my_strcat(points_s, points);
    sfVector2f pos = {0, 100};
    text *t = create_text("./assets/fonts/motion-control.bold.otf",
        points_s, sfWhite, pos);
    t->animate = animate_delta;
    t->name = my_strdup("delta_time");
    t->display = 0;
    sfText_setCharacterSize(t->text, 50);
    put_in_list(&d->texts, t);
}
