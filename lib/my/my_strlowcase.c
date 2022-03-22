/*
** EPITECH PROJECT, 2021
** Day06
** File description:
** task09
*/

char *my_strlowcase(char *str)
{
    for (int count = 0; str[count] != '\0'; ++count)
        if (str[count] < 91 && str[count] > 64)
            str[count] = str[count]+32;
    return str;
}
