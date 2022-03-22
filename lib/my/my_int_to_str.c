/*
** EPITECH PROJECT, 2021
** LIB
** File description:
** int to str
*/

#include "my.h"
#include "stdlib.h"

char *my_int_to_str(int value)
{
    int len = my_nbr_of_digit(value);
    char *str = malloc(sizeof(char) * len + 1);

    if (value == 0)
        return (my_strcpy(str, "0"));
    str[len] = '\0';
    if (value < 0) {
        str[0] = '-';
        value = -value;
    }
    while (value > 0) {
        str[--len] = value % 10 + '0';
        value = value / 10;
    }
    return str;
}
