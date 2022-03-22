/*
** EPITECH PROJECT, 2021
** STR Len
** File description:
** put dor my_strlen
*/

int my_strlen(char const *str)
{
    int count = 0;
    while (str[count] != '\0')
        count++;
    return (count);
}
