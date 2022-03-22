/*
** EPITECH PROJECT, 2021
** LIB
** File description:
** inssert str into str
*/

#include "./my.h"

char *my_insert(char *strA, char *strB, char *buffer, int position)
{
    my_strncpy(buffer, strA, position);
    buffer[position] = '\0';
    my_strcat(buffer, strB);
    my_strcat(buffer, strA + position);
    return buffer;
}
