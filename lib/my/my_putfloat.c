/*
** EPITECH PROJECT, 2021
** Rush2
** File description:
** put float
*/

#include "my.h"

void my_put_float(float f)
{
    f = f * 100;
    int nb = (int)f;
    my_put_nbr(nb / 100);
    my_putchar('.');
    my_put_nbr((nb / 10) % 10);
    my_put_nbr(nb % 10);
}
