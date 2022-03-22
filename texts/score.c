/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** display score
*/

#include "../include/rpg.h"

void animate_score(text *t, scene *d)
{
    char *points = my_int_to_str(d->stat->score);
    char points_s[255];
    points_s[0] = '\0';
    my_strcat(points_s, "Score: ");
    my_strcat(points_s, points);
    modify_string(d, t->string, points_s);
    free(points);
}

void display_score(scene *d)
{
    char *points = my_int_to_str(d->stat->score);
    char points_s[255];
    points_s[0] = '\0';
    my_strcat(points_s, "Score: ");
    my_strcat(points_s, points);
    sfVector2f pos = {400, 120};
    text *t =
        create_text("./assets/josefin_sans/josefin_sans_light.ttf", points_s,
            sfWhite, pos);
    t->animate = animate_score;
    put_in_list(&d->texts, t);
    free(points);
}
