/*
** EPITECH PROJECT, 2021
** My Put NBR
** File description:
** Put NBR
*/

#include "my.h"

int my_put_nbr(int nb)
{
    int d;
    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
    }
    if (nb > 9)
        my_put_nbr(nb / 10);
    d = nb % 10 + 48;
    my_putchar(d);
    return (0);
}
