/*
** EPITECH PROJECT, 2021
** Day09
** File description:
** libmy.a
*/

#include <stdarg.h>

#ifndef MY_H
    #define MY_H
    #define true 1
    #define TRUE 1
    #define false 0
    #define FALSE 0

int my_printf(int fd, char *str, ...);
char *my_strdup(char *str);
int my_str_to_int(char *string);
int my_char_is_in_string(char const c, char const *string);
int my_chars_is_in_string(char const *chars, char const *string);
char *my_str_replace(
    char const *strA, char *strB, char *final_buffer, int *index
);
char *my_insert(char *strA, char *strB, char *buffer, int position);
char *my_int_to_str(int);
int my_nbr_of_digit(int);
void unprint(char *string);
int my_error(char *);
void my_put_float(float);
char my_charlowcase(char);
void my_putchar(char);
int value_of_string_n(char const *, int);
int value_of_string(char const *);
int my_isneg(int);
int my_put_nbr(int);
void my_swap(int *, int *);
int my_putstr(char const *);
int my_strlen(char const *);
int my_getnbr(char const *);
void my_sort_int_array(int *, int);
int my_str_isnum(char const *);
int my_compute_power_rec(int, int);
int my_str_islower(char const *);
int my_str_isalpha(char const *);
char *my_strcapitalize(char *);
char *my_strlowcase(char *);
char *my_strupcase(char *);
char *my_strstr(char *, char const *);
int my_strcmp(char const *, char const *);
int my_strncmp(char const *, char const *, int);
int my_compute_square_root(int);
int my_str_isupper(char const *);
int my_is_prime(int);
int my_str_isprintable(char const *);
int my_find_prime_sup(int);
int my_showstr(char const *);
char *my_strcpy(char *, char const *);
int my_showmem(char const *, int);
char *my_strncpy(char *, char const *, int);
char *my_strcat(char *, char const *);
char *my_revstr(char *);
char *my_strncat(char *, char const *, int);
void print_int(int fd, char *arg, int index, va_list ap);
void print_float(int fd, char *arg, int index, va_list ap);
int my_count_char(char *string, char c);

#endif
