/*
** EPITECH PROJECT, 2021
** MyRpg - textures
** File description:
** Long buttons
*/

#include "../../include/rpg.h"

int create_slide_bar_texture(scene *d)
{
    put_in_list(&d->textures,
    create_texture("./assets/ui/slide_bar.png",
    "slide_bar", create_rect(98, 10, 0, 0)));
    return 0;
}
