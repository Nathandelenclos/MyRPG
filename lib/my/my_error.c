/*
** EPITECH PROJECT, 2021
** Rush2
** File description:
** error
*/

#include "my.h"
#include <unistd.h>

int my_error(char *m)
{
    write(2, m, my_strlen(m));
    return (84);
}
