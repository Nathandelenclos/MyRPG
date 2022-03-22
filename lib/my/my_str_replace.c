/*
** EPITECH PROJECT, 2021
** LIB
** File description:
** replace
*/

#include "./my.h"

char *my_str_replace(
    char const *strA, char *strB, char *final_buffer, int *index
)
{
    char buffer[my_strlen(strA) + my_strlen(strB)];
    int i = 0;
    for (i; i < my_strlen(strA); ++i)
        if (index[0] <= i)
            buffer[i] = strA[i + (index[1] - index[0])];
        else
            buffer[i] = strA[i];
    buffer[i + 1] = '\0';
    my_insert(buffer, strB, final_buffer, index[0]);
    return final_buffer;
}
