/*
** EPITECH PROJECT, 2021
** Square root
** File description:
** square root
*/

#include "my.h"

int my_compute_square_root(int nb)
{
    if (nb < 0)
        return (0);
    int count = 1;
    for (count; count < nb; ++count) {
        int power = my_compute_power_rec(count, 2);
        if (power == nb)
            return count;
    }
    return (0);
}
