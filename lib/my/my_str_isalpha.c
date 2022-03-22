/*
** EPITECH PROJECT, 2021
** LIB
** File description:
** isalpha
*/

int my_str_isalpha(char const *str)
{
    int is_alpha = 0;
    for (int count = 0; str[count] != '\0'; ++count) {
        if (str[count] > 64 && str[count] < 91)
            is_alpha = 1;
        if (str[count] > 96 && str[count] < 123)
            is_alpha = 1;
    }
}
