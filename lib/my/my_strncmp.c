/*
** EPITECH PROJECT, 2021
** Day06
** File description:
** task07
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (int i = 0; i < n; ++i) {
        if (s1[0] != s2[0])
            return 0;
    }
    return 1;
}
