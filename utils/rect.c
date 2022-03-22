/*
** EPITECH PROJECT, 2021
** MyRPG - utils
** File description:
** rect
*/

#include "../include/rpg.h"

sfIntRect create_simple_rect(int width, int height)
{
    return create_rect(width, height, 0, 0);
}

sfIntRect create_rect(int width, int height, int left, int top)
{
    sfIntRect rect;
    rect.left = left;
    rect.width = width;
    rect.height = height;
    rect.top = top;
    return rect;
}
