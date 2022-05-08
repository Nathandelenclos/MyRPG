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

void create_all_trees(scene *d)
{
    create_tree(d, create_vector2f(270, 420));
    create_tree(d, create_vector2f(444, 298));
    create_tree(d, create_vector2f(592, 434));
    create_tree(d, create_vector2f(190, 300));
    create_tree(d, create_vector2f(160, 200));
    create_tree(d, create_vector2f(160, 400));
    create_tree(d, create_vector2f(320, 350));
}
