/*
** EPITECH PROJECT, 2021
** LIB
** File description:
** return number of digit in integer.
*/

int my_nbr_of_digit(int nb)
{
    int count = 1;
    while (nb >= 10) {
        nb /= 10;
        count++;
    }
    return count;
}
