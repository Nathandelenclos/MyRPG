##
## EPITECH PROJECT, 2021
## Day12
## File description:
## makefile
##

MAIN	=	main.c	\

UTILS	=	life_bar.c	\
			rect.c	\
			game_obj.c	\
			free.c	\
			get_w_scale.c	\

SPRITES	=	l_btn.c	\
			r_btn.c	\
			s_btn.c	\

SCREENS	=	main_menu/main_menu.c	\

TEXTURES	=	characters/characters.c	\
				objects/chest_and_obj.c	\
				objects/particles.c	\
				objects/walls.c	\
				objects/tilesets.c	\
				ui/create_buttons_texture.c	\
				ui/banners/banner1.c	\
				ui/banners/banner2.c	\
				ui/controls/control1.c	\
				ui/controls/control2.c	\
				ui/icons/icon1.c	\
				ui/icons/icon2.c	\
				ui/icons/icon3.c	\

MANAGER =	sprites_manager.c	\
			time_manager.c	\
			text_manager.c	\
			sound_manager.c	\
			texture_manager.c	\
			screen_manager.c	\
			move_manager.c	\
			event_manager.c	\
			thread_manager.c	\

TEXTS	=	fps.c	\

TEXTS_PATH	=	texts/

SCREEN_PATH	=	screens/

SPRITE_PATH	=	sprites/

TEXTURE_PATH	=	textures/

MANAGER_PATH	=	manager/

UTIL_PATH	=	utils/

SRC	=		events.c	\
			$(addprefix $(MANAGER_PATH), $(MANAGER))	\
			$(addprefix $(TEXTS_PATH), $(TEXTS))	\
			$(addprefix $(TEXTURE_PATH), $(TEXTURES))	\
			$(addprefix $(SCREEN_PATH), $(SCREENS))	\
			$(addprefix $(SPRITE_PATH), $(SPRITES))	\
			$(addprefix $(UTIL_PATH), $(UTILS))	\

OBJ	=	$(MAIN:.c=.o) $(SRC:.c=.o)

TEST_FILE	=		\

NAME	=	my_rpg

LIB	=	-lcsfml-graphics	\
		-lcsfml-window	\
		-lcsfml-system	\
		-lcsfml-audio	\
		-llist	\
		-lm	\
		-lmy

CFLAGS	=	-I include

all:	buildlib $(NAME)

debug:	CFLAGS += -g
debug:	all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make -C ./lib/my/ fclean
	make -C ./lib/linked_list/ fclean

re:	fclean all

exe: all
	./$(NAME)

buildlib:
	make -C ./lib/linked_list/
	make -C ./lib/my/

tests_run:
	gcc -o unit_tests $(SRC) $(TEST_FILE) -L./lib $(LIB)
	./unit_tests
	rm unit_tests*

$(NAME):	$(OBJ)
	gcc $(CFLAGS) -o $(NAME) $(OBJ) -L./lib $(LIB)
