/*
** EPITECH PROJECT, 2021
** Rush2
** File description:
** put float
*/

#include "my.h"

void my_putfloat(int nb)
{
    my_put_nbr(nb / 100);
    my_putchar('.');
    my_put_nbr((nb / 10) % 10);
    my_put_nbr(nb % 10);
}
