/*
** EPITECH PROJECT, 2021
** Day06
** File description:
** task01
*/

char *my_strcpy(char *dest, char const *src)
{
    int count = 0;
    for (count; src[count] != '\0'; ++count)
        dest[count] = src[count];
    dest[count] = '\0';
    return dest;
}
