/*
** EPITECH PROJECT, 2021
** LIB
** File description:
** putchar
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
