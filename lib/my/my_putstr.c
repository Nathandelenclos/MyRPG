/*
** EPITECH PROJECT, 2021
** Put STR
** File description:
** file for my_put_str
*/

#include "my.h"

int my_putstr(char const *str)
{
    for (int count = 0; str[count] != '\0'; ++count) {
        my_putchar(str[count]);
    }
    return (0);
}
