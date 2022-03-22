/*
** EPITECH PROJECT, 2021
** Day06
** File description:
** task05
*/

#include "my.h"

char *my_strstr(char *str, char const *to_find)
{
    char *result[my_strlen(to_find)+1];
    for (int i = 0; str[i] != '\0'; ++i) {
        for (int count = 0; str[count] == to_find[count + i]; ++count)
            str[count] = to_find[i + count];
    }
    return str;
}
