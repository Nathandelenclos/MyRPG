/*
** EPITECH PROJECT, 2021
** LIB
** File description:
** printf
*/

#include "my.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

void print_string(int fd, char *arg, int index, va_list ap)
{
    char *string = (char *) va_arg(ap, char *);
    write(fd, string, my_strlen(string));
}

void print_char(int fd, char *arg, int index, va_list ap)
{
    char c = va_arg(ap, int);
    write(fd, &c, 1);
}

void tab_function(int fd, char *arg, int index, va_list ap)
{
    char **tab_string;
    int *tab_int;
    switch (arg[index + 2]) {
    case 's':
        tab_string = (char **)ap;
        for (int i = 0; tab_string[i] != NULL; ++i)
            my_printf(fd, "%s\n", tab_string[i]);
        break;
    case 'i':
        tab_int = (int *)ap;
        for (int i = 0; tab_int[i] != -0; ++i)
            my_printf(fd, "%i", tab_int[i]);
        break;
    }
    return;
}

void print_dictionary(void (*tab[])(int , char *, int , va_list ))
{
    tab['s'] = print_string;
    tab['S'] = print_string;
    tab['c'] = print_char;
    tab['C'] = print_char;
    tab['%'] = print_char;
    tab['t'] = tab_function;
    tab['i'] = print_int;
    tab['f'] = print_float;
}

int my_printf(int fd, char *str, ...)
{
    void (*print_entries[172])(int fd, char *arg, int index, va_list ap);
    print_dictionary(print_entries);
    va_list vaList;
    va_start(vaList, str);
    for (int i = 0; i < my_strlen(str); ++i) {
        if (str[i] == '%') {
            print_entries[str[i + 1]](fd, str, i, vaList);
            i++;
        } else
            write(fd, &str[i], 1);
    }
    va_end(vaList);
    return fd;
}
