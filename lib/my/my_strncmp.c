/*
** EPITECH PROJECT, 2021
** Day06
** File description:
** task07
*/

int value_of_string_n(char const *s, int n)
{
    int result = 0;
    for (int count = 0; s[count] != '\0' && count < n; ++count)
        result += s[count];
    return result;
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int count1 = value_of_string_n(s1, n);
    int count2 = value_of_string_n(s2, n);
    if (count1 > count2)
        return (1);
    else if (count1 < count2)
        return (-1);
    else
        return (0);
}
