/*
** EPITECH PROJECT, 2021
** LIB
** File description:
** str to int
*/

#include "./my.h"

int my_str_to_int(char *string)
{
    int value = 0;
    for (int i = 0; i < my_strlen(string); ++i)
        value = (value * 10) + (string[i] - '0');
    return value;
}
