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
			free2.c	\
			get_w_scale.c	\
			utils.c	\
			utils2.c	\
			init_settings_structs.c	\
			collision.c	\
			position.c	\
			fade_scene.c	\
			quest.c	\

SPRITES	=	banners/banners1.c	\
			banners/banners2.c	\
			controls/control1.c	\
			controls/control2.c	\
			icons/icon1.c	\
			icons/icon2.c	\
			icons/icon3.c	\
			ennemies/slime.c	\
			ennemies/slime2.c	\
			ennemies/slime_animation.c	\
			ennemies/slime_animation2.c	\
			objects/chests.c	\
			objects/apples.c	\
			objects/chests_animation.c	\
			ui/l_btn.c	\
			ui/event_change_input_setting.c	\
			ui/change_move_input.c	\
			ui/change_interact_input.c	\
			ui/change_slot_input.c	\
			ui/r_btn.c	\
			ui/s_btn.c	\
			ui/s_btn2.c	\
			ui/slide_bar.c	\
			menu_bg.c	\
			settings_bg.c	\
			ui/tiles.c	\
			ui/input_error_handling.c	\
			ui/create_settings_background.c	\
			ui/create_lose_background.c	\
			ui/error_popup.c	\
			map.c	\
			player/player.c	\
			player/player2.c	\
			player/regeneration.c	\
			player/player_animation.c	\
			player/player_animation_mirror.c	\
			player/player_inventory.c	\
			player/player_inventory2.c	\
			player/case_animation.c	\
			chest_inventory.c	\
			bed/bed.c	\
			pnj/pnj.c	\
			trees/trees.c	\

ENVIRONMENTS	=	rain.c	\
					regen.c	\
					low_life.c	\

SCREENS	=	main_menu/main_menu.c	\
			main_menu/pause_menu.c	\
			settings_menu/settings_menu.c	\
			settings_menu/moving_button.c	\
			settings_menu/moving_button_text.c	\
			settings_menu/slot_button.c	\
			settings_menu/wrong_input_screen.c	\
			play_screen/play_screen.c	\
			play_screen/play_screen_trees.c	\
			play_screen/play_screen_slimes.c	\
			play_screen/play_screen_data.c	\
			play_screen/game_over_screen.c	\
			play_screen/win_screen.c	\
			open_inventory_chest.c	\
			open_inventory_chest_event.c	\
			open_inventory_chest_data.c	\
			discuss.c	\

TEXTURES	=	characters/characters.c	\
				characters/characters2.c	\
				characters/particle.c	\
				objects/chest_and_obj.c	\
				objects/bed_texture.c	\
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
			env_manager.c	\

QUEST =	simon_quest.c	\
		second_quest.c	\
		four_quest.c	\
		third_quest.c	\

TEXTS	=	fps.c	\
			menu.c	\
			discuss.c	\
			entity_load.c	\
			delta_time.c	\

TEXTS_PATH	=	texts/

SCREEN_PATH	=	screens/

QUEST_PATH	=	quest/

SPRITE_PATH	=	sprites/

TEXTURE_PATH	=	textures/

MANAGER_PATH	=	manager/

UTIL_PATH	=	utils/

ENV_PATH	=	environment/

SRC	=		events.c	\
			$(addprefix $(MANAGER_PATH), $(MANAGER))	\
			$(addprefix $(TEXTS_PATH), $(TEXTS))	\
			$(addprefix $(TEXTURE_PATH), $(TEXTURES))	\
			$(addprefix $(SCREEN_PATH), $(SCREENS))	\
			$(addprefix $(SPRITE_PATH), $(SPRITES))	\
			$(addprefix $(UTIL_PATH), $(UTILS))	\
			$(addprefix $(ENV_PATH), $(ENVIRONMENTS))	\
			$(addprefix $(QUEST_PATH), $(QUEST))	\

OBJ	=	$(MAIN:.c=.o) $(SRC:.c=.o)

TEST_FILE	=		\

NAME	=	my_rpg

LIB	=	-lcsfml-graphics	\
		-lcsfml-window	\
		-lcsfml-system	\
		-lcsfml-audio	\
		-llist	\
		-lm	\
		-lmy	\

CFLAGS	=	-I include

all:	buildlib $(NAME)

debug:	CFLAGS += -g
debug:	all

clean:
	find . -name "*.o" -delete
	find . -name "vgcore*" -delete

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
