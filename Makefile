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
			utils.c	\
<<<<<<< HEAD
			init_settings_structs.c	\
=======
			collision.c	\
>>>>>>> preprod

SPRITES	=	banners/banners1.c	\
			banners/banners2.c	\
			controls/control1.c	\
			controls/control2.c	\
			icons/icon1.c	\
			icons/icon2.c	\
			icons/icon3.c	\
      		ennemies/slime.c	\
			ennemies/slime_animation.c	\
      		objects/chests.c	\
      		ui/l_btn.c	\
      		ui/event_change_input_setting.c	\
			ui/change_move_input.c	\
			ui/change_interact_input.c	\
			ui/change_slot_input.c	\
			ui/r_btn.c	\
			ui/s_btn.c	\
			ui/slide_bar.c	\
			menu_bg.c	\
			settings_bg.c	\
			ui/tiles.c	\
			ui/input_error_handling.c	\
			ui/create_settings_background.c	\
			ui/error_popup.c	\
			map.c	\
			player/player.c	\
			player/player_animation.c	\
			chest_inventory.c	\

SCREENS	=	main_menu/main_menu.c	\
			settings_menu/settings_menu.c	\
			settings_menu/moving_button.c	\
			settings_menu/slot_button.c	\
			settings_menu/wrong_input_screen.c	\
			play_screen/play_screen.c	\
			open_inventory_chest.c	\

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
				ui/others/other_textures.c	\
				map.c	\
				ui/chest_inventory.c	\
				ui/create_menu_textures.c	\
				ui/create_slide_bar_texture.c	\
				ui/create_popup_texture.c	\

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
			menu.c	\

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
