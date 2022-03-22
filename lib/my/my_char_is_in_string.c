/*
** EPITECH PROJECT, 2021
** LIBMY
** File description:
** char is in string
*/

#include "my.h"

int my_char_is_in_string(char const c, char const *string)
{
    for (int i = 0; i < my_strlen(string); ++i) {
        if (c == string[i])
            return 1;
    }
    return 0;
}

int my_chars_is_in_string(char const *chars, char const *string)
{
    for (int i = 0; i < my_strlen(chars); ++i) {
        if (my_char_is_in_string(chars[i], string))
            return 1;
    }
    return 0;
}
