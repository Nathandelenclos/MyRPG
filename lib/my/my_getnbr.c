/*
** EPITECH PROJECT, 2021
** LIB
** File description:
** my_getnbr
*/

int my_getnbr(char const *str)
{
    int nb = 0;
    int is_neg = 1;
    int count = 0;

    for (count; str[count] == '+' || str[count] == '-'; ++count)
        if (str[count] == '-')
            is_neg = is_neg * -1;
    while (str[count] != '\0') {
        if (str[count] >= '0' && str[count] <= '9') {
            nb = nb * 10;
            nb = nb + str[count] - '0';
            ++count;
        } else {
            return (nb * is_neg);
        }
    }
    return (nb * is_neg);
}
