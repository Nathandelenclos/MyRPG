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
    sfVector2f pos = {0, d->hub->mode.height - 110};
    text *t =
        create_text("./assets/josefin_sans/josefin_sans_light.ttf", points_s,
            sfWhite, pos);
    t->animate = animate_fps;
    sfText_setCharacterSize(t->text, 108);
    put_in_list(&d->texts, t);
}
