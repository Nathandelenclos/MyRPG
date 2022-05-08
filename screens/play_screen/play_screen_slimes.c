/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** Screen
*/

#include "../../include/my.h"
#include "../../include/rpg.h"
#include <SFML/Window.h>
#include <SFML/Graphics.h>

void create_pink_slimes(scene *d)
{
    create_slime
        (d, create_vector2f(530, 220), PINK, create_vector2f(9, 2));
    create_slime
        (d, create_vector2f(520, 180), PINK, create_vector2f(9, 2));
    create_slime
        (d, create_vector2f(580, 205), PINK, create_vector2f(9, 2));
    create_slime
        (d, create_vector2f(630, 180), PINK, create_vector2f(9, 2));
    create_slime
        (d, create_vector2f(630, 220), PINK, create_vector2f(9, 2));
}

void create_blue_slimes(scene *d)
{
    create_slime
        (d, create_vector2f(280, 180), BLUE, create_vector2f(12, 3));
    create_slime
        (d, create_vector2f(280, 90), BLUE, create_vector2f(12, 3));
    create_slime
        (d, create_vector2f(350, 155), BLUE, create_vector2f(12, 3));
    create_slime
        (d, create_vector2f(400, 90), BLUE, create_vector2f(12, 3));
    create_slime
        (d, create_vector2f(400, 180), BLUE, create_vector2f(12, 3));
    create_pink_slimes(d);
}

void create_green_slimes(scene *d)
{
    create_slime
        (d, create_vector2f(530, 410), GREEN, create_vector2f(15, 4));
    create_slime
        (d, create_vector2f(530, 330), GREEN, create_vector2f(15, 4));
    create_slime
        (d, create_vector2f(595, 370), GREEN, create_vector2f(15, 4));
    create_slime
        (d, create_vector2f(670, 330), GREEN, create_vector2f(15, 4));
    create_slime
        (d, create_vector2f(670, 410), GREEN, create_vector2f(15, 4));
    create_blue_slimes(d);
}

void create_yellow_slimes(scene *d)
{
    create_slime
        (d, create_vector2f(480, 610), YELLOW, create_vector2f(18, 5));
    create_slime
        (d, create_vector2f(480, 500), YELLOW, create_vector2f(18, 5));
    create_slime
        (d, create_vector2f(530, 560), YELLOW, create_vector2f(18, 5));
    create_slime
        (d, create_vector2f(570, 500), YELLOW, create_vector2f(18, 5));
    create_slime
        (d, create_vector2f(570, 610), YELLOW, create_vector2f(18, 5));
    create_green_slimes(d);
}

void create_all_slimes(scene *d)
{
    create_slime
        (d, create_vector2f(280, 570), BLACK, create_vector2f(24, 7));
    create_slime
        (d, create_vector2f(310, 518), BLACK, create_vector2f(24, 7));
    create_slime
        (d, create_vector2f(365, 491), BLACK, create_vector2f(24, 7));
    create_slime
        (d, create_vector2f(290, 483), BLACK, create_vector2f(24, 7));
    create_slime
        (d, create_vector2f(307, 440), BLACK, create_vector2f(24, 7));
    create_yellow_slimes(d);
}
