/*
** EPITECH PROJECT, 2021
** Day06
** File description:
** task03
*/

#include "my.h"

char *my_revstr(char *src)
{
    int len = my_strlen(src);
    for (int count = 0; count < len / 2; ++count) {
        char temp = src[len - count - 1];
        src[len - count - 1] = src[count];
        src[count] = temp;
    }
    return src;
}
