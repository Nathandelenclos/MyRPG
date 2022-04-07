##
## EPITECH PROJECT, 2021
## Day10
## File description:
## Makefile
##

SRC	=	put_in_list.c	\
		show_list.c	\
		free_list.c	\
		delete_in_list.c	\
		len_list.c	\
		delete_first.c	\
		insert_in_list.c	\
		reverse_list.c	\
		put_in_end.c	\
		my_free.c	\
		my_malloc.c	\
		search_in_list.c	\

OBJ	=	$(SRC:.c=.o)

TEST_FILE	=	../../tests/test_liblist.c	\

NAME	=	test

CFLAGS	+=	-g

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm ./*.a
	rm ../../include/list.h

re: fclean all

tests_run:
	gcc -o unit_tests $(SRC) $(TEST_FILE) -L../ -llist --coverage -lcriterion
	./unit_tests

$(NAME):	$(OBJ)
	ar rc liblist.a $(OBJ)
	cp liblist.a ../
	cp list.h ../../include/
