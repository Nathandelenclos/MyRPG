/*
** EPITECH PROJECT, 2021
** Day06
** File description:
** task08
*/

char *my_strupcase(char *str)
{
    for (int count = 0; str[count] != '\0'; ++count)
        str[count] = str[count] - 32;
    return str;
}
