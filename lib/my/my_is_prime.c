/*
** EPITECH PROJECT, 2021
** Is Prime
** File description:
** file my_is_prime.c
*/

int my_is_prime(int nb)
{
    int is_prime = 1;
    for (int count = 2; count < nb; ++count)
        if (nb % count == 0)
            is_prime = 0;
    return is_prime;
}
