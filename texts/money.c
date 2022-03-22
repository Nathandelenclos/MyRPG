/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** display money
*/

#include "../include/rpg.h"

void animate_money(text *t, scene *d)
{
    char *points = my_int_to_str(d->stat->money);
    char points_s[255];
    points_s[0] = '\0';
    my_strcat(points_s, "Money: ");
    my_strcat(points_s, points);
    modify_string(d, t->string, points_s);
}

void display_money(scene *d)
{
    char *points = my_int_to_str(d->stat->money);
    char points_s[255];
    points_s[0] = '\0';
    my_strcat(points_s, "Money: ");
    my_strcat(points_s, points);
    sfVector2f pos = {400, 170};
    text *t =
        create_text("./assets/josefin_sans/josefin_sans_light.ttf", points_s,
            sfWhite, pos);
    t->animate = animate_money;
    put_in_list(&d->texts, t);
}
