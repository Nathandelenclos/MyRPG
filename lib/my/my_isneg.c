/*
** EPITECH PROJECT, 2021
** My Isneg
** File description:
** file for my isneg
*/

#include "my.h"

int my_isneg(int n)
{
    if (n < 0 )
        my_putchar('N');
    else
        my_putchar('P');
    return (0);
}
