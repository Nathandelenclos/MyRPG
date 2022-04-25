/*
** EPITECH PROJECT, 2021
** LIB - Printf
** File description:
** Printf bis
*/

#include "my.h"

void print_int(int fd, char *arg, int index, va_list ap)
{
    my_put_nbr((int) va_arg(ap, int));
}

void print_float(int fd, char *arg, int index, va_list ap)
{
    my_put_float((float ) va_arg(ap, double));
}
