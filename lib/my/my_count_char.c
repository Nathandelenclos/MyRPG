/*
** EPITECH PROJECT, 2021
** LIB MY
** File description:
** count char in string
*/

int my_count_char(char *string, char c)
{
    int count = 0;

    for (int i = 0; string[i] != '\0'; ++i)
        if (string[i] == c)
            count++;
    return count;
}