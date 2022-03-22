/*
** EPITECH PROJECT, 2021
** LIB
** File description:
** str cat
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int len_dest = my_strlen(dest);
    int i = 0;
    for (i; src[i] != '\0'; ++i)
        dest[len_dest + i] = src[i];
    dest[len_dest + i] = '\0';
    return dest;
}
