##
## EPITECH PROJECT, 2021
## Day10
## File description:
## Makefile
##

SRC	=	my_insert.c	\
		my_str_to_int.c	\
		my_putstr.c	\
		my_strdup.c	\
		my_char_is_in_string.c	\
		my_nbr_of_digit.c	\
		my_str_replace.c	\
		my_int_to_str.c	\
		my_error.c	\
		my_putfloat.c	\
		my_charlowcase.c\
		my_str_isnum.c	\
		my_count_char.c	\
		my_compute_power_rec.c	\
		my_revstr.c	\
		my_str_isprintable.c	\
		my_str_showstr.c	\
		my_compute_square_root.c\
		my_sort_int_array.c	\
		my_str_isupper.c	\
		my_showmem.c	\
		my_find_prime_sup.c	\
		my_strcapitalize.c	\
		my_strlen.c	\
		my_strstr.c	\
		my_getnbr.c	\
		my_strcat.c	\
		my_strlowcase.c	\
		my_strupcase.c	\
		my_isneg.c	\
		my_strcmp.c	\
		my_strncat.c	\
		my_swap.c	\
		my_is_prime.c	\
		my_strcpy.c	\
		my_strncmp.c	\
		my_putchar.c	\
		my_str_isalpha.c\
		my_strncpy.c	\
		my_put_nbr.c	\
		my_str_islower.c\
		my_printf.c	\
		my_printf_bis.c	\

OBJ	=	$(SRC:.c=.o)

TEST_FILE	=	../../tests/test_lib2.c	\
				../../tests/test_lib1.c	\

NAME	=	test

CFLAGS	=	-g

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm ../*.a
	rm ./*.a
	rm ../../include/my.h

re: fclean all

tests_run:
	gcc -o unit_tests $(SRC) $(TEST_FILE) -L../ -lmy --coverage -lcriterion
	./unit_tests

$(NAME):	$(OBJ)
	ar rc libmy.a $(OBJ)
	cp libmy.a ../
	cp my.h ../../include/
