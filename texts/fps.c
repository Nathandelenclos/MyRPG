/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** display money
*/

#include "../include/rpg.h"

void animate_fps(text *t, scene *d)
{
    char *points = my_int_to_str(d->hub->fps);
    char points_s[255];
    points_s[0] = '\0';
    my_strcat(points_s, "FPS: ");
    my_strcat(points_s, points);
    modify_string(d, t->string, points_s);
}

void display_fps(scene *d)
{
    char *points = my_int_to_str(d->hub->fps);
    char points_s[255];
    points_s[0] = '\0';
    my_strcat(points_s, "FPS: ");
    my_strcat(points_s, points);
    sfVector2f pos = {0, 0};
    text *t =
        create_text("./assets/fonts/motion-control.bold.otf", points_s,
            sfWhite, pos);
    t->animate = animate_fps;
    t->name = my_strdup("fps");
    t->display = 0;
    sfText_setCharacterSize(t->text, 50);
    put_in_list(&d->texts, t);
}
