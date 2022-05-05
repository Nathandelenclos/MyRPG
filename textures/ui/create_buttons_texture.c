/*
** EPITECH PROJECT, 2021
** MyRpg - textures
** File description:
** Long buttons
*/

#include "../../include/rpg.h"

void create_long_buttons(scene *d)
{
    put_in_list(&d->textures,
    create_texture("./assets/ui/long_buttons/blue_lb.png",
    "blue_lb", create_rect(55, 41, 0, 0)));
    put_in_list(&d->textures,
    create_texture("./assets/ui/long_buttons/green_lb.png",
    "green_lb", create_rect(55, 41, 0, 0)));
    put_in_list(&d->textures,
    create_texture("./assets/ui/long_buttons/orange_lb.png",
    "orange_lb", create_rect(55, 41, 0, 0)));
    put_in_list(&d->textures,
    create_texture("./assets/ui/long_buttons/purple_lb.png",
    "purple_lb", create_rect(55, 41, 0, 0)));
    put_in_list(&d->textures,
    create_texture("./assets/ui/long_buttons/red_lb.png",
    "red_lb", create_rect(55, 41, 0, 0)));
    put_in_list(&d->textures,
    create_texture("./assets/ui/long_buttons/white_lb.png",
    "white_lb", create_rect(55, 41, 0, 0)));
}

void create_square_buttons(scene *d)
{
    put_in_list(&d->textures,
    create_texture("./assets/ui/square_buttons/blue_sb.png",
    "blue_sb", create_rect(55, 41, 0, 0)));
    put_in_list(&d->textures,
    create_texture("./assets/ui/square_buttons/green_sb.png",
    "green_sb", create_rect(55, 41, 0, 0)));
    put_in_list(&d->textures,
    create_texture("./assets/ui/square_buttons/orange_sb.png",
    "orange_sb", create_rect(55, 41, 0, 0)));
    put_in_list(&d->textures,
    create_texture("./assets/ui/square_buttons/purple_sb.png",
    "purple_sb", create_rect(55, 41, 0, 0)));
    put_in_list(&d->textures,
    create_texture("./assets/ui/square_buttons/red_sb.png",
    "red_sb", create_rect(55, 41, 0, 0)));
    put_in_list(&d->textures,
    create_texture("./assets/ui/square_buttons/white_sb.png",
    "white_sb", create_rect(55, 41, 0, 0)));
}

void create_round_buttons(scene *d)
{
    put_in_list(&d->textures,
    create_texture("./assets/ui/round_buttons/blue_rb.png",
    "blue_rb", create_rect(55, 41, 0, 0)));
    put_in_list(&d->textures,
    create_texture("./assets/ui/round_buttons/green_rb.png",
    "green_rb", create_rect(55, 41, 0, 0)));
    put_in_list(&d->textures,
    create_texture("./assets/ui/round_buttons/orange_rb.png",
    "orange_rb", create_rect(55, 41, 0, 0)));
    put_in_list(&d->textures,
    create_texture("./assets/ui/round_buttons/purple_rb.png",
    "purple_rb", create_rect(55, 41, 0, 0)));
    put_in_list(&d->textures,
    create_texture("./assets/ui/round_buttons/red_rb.png",
    "red_rb", create_rect(55, 41, 0, 0)));
    put_in_list(&d->textures,
    create_texture("./assets/ui/round_buttons/white_rb.png",
    "white_rb", create_rect(55, 41, 0, 0)));
}

void create_others(scene *d)
{
    put_in_list(&d->textures,
    create_texture("./assets/ui/square_buttons/white_plus_sb.png",
    "white_plus", create_rect(55, 41, 0, 0)));
    put_in_list(&d->textures,
    create_texture("./assets/ui/square_buttons/white_minus_sb.png",
    "white_minus", create_rect(55, 41, 0, 0)));
    put_in_list(&d->textures,
    create_texture("./assets/ui/long_buttons/white_lt.png",
    "white_lt", create_rect(55, 20, 0, 0)));
}

int create_buttons_texture(scene *d)
{
    create_long_buttons(d);
    create_square_buttons(d);
    create_round_buttons(d);
    create_others(d);
    return 0;
}
