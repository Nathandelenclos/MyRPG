/*
** EPITECH PROJECT, 2021
** LIB
** File description:
** printf
*/

#include <stdarg.h>
#include "my.h"

char *norme_octo(char *str, char *buff, int size)
{
    int size_str = my_strlen(str);
    int diff = size - size_str;

    for (int i = 0; i < diff; ++i)
        buff[i] = '0';
    for (int i = diff; i < size; ++i)
        buff[i] = str[i - diff];
    buff[size] = '\0';
    return buff;
}

void print_arg(char *string, int i, va_list vaList)
{
    switch (string[i + 1]) {
    case 's':
        my_putstr((char *) va_arg(vaList, char *));
        break;
    case 'c' | 'C':
        my_putchar((int) va_arg(vaList,
        int));
        break;
    case '%':
        my_putchar('%');
        break;
    default:
        my_error("Invalid type.");
        break;
    }
}

int my_printf(char *str, ...)
{
    va_list vaList;
    va_start(vaList, str);
    for (int i = 0; i < my_strlen(str); ++i) {
        if (str[i] == '%') {
            print_arg(str, i, vaList);
            i++;
        } else
            my_putchar(str[i]);
    }
    va_end(vaList);
    return (1);
}
