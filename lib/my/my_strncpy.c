/*
** EPITECH PROJECT, 2021
** Day06
** File description:
** task02
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    for (int count = 0; count < n; ++count)
        dest[count] = src[count];
    dest[n] = '\0';
    return dest;
}
