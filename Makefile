##
## EPITECH PROJECT, 2023
## project
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/gloop.c \
		src/my_rpg.c \
		src/create_enemy.c \
		src/conversion.c \
		src/destroy_game.c \
		\
		src/map/create_map_object.c \
		src/map/create_tile.c \
		src/map/display_map.c \
		src/map/extract_map_object.c \
		src/map/get_manifest_info.c \
		src/map/load_manifest.c \
		src/map/load_layer.c \
		src/map/load_tile.c \
		src/map/destroy_map.c \
		src/map/detect_spawn.c \
		src/map/change_map.c \
		src/map/create_teleport.c \
		src/map/connect_teleporter.c \
		\
		src/event/main_event.c \
		\
		src/button/create_button.c \
		src/button/display_button.c \
		src/button/button_event.c \
		src/button/state_button_callback.c \
		src/button/update_button.c \
		\
		src/app/create_app.c \
		src/app/destroy_app.c \
		\
		src/window/create_window.c \
		\
		src/array_manipulation/split.c \
		src/array_manipulation/array_manipulation.c \
		\
		src/menu/escape_menu/create_escape_menu.c \
		src/menu/escape_menu/callback.c \
		src/menu/escape_menu/display_menu.c \
		\
		src/menu/splash_screen/create_splash_screen.c \
        src/menu/splash_screen/splash_screen.c \
        src/menu/splash_screen/update_splash_screen.c  \
        src/menu/splash_screen/clean_splash_screen.c \
		\
		src/menu/settings/resolution.c \
		src/menu/settings/music_callback.c \
		src/menu/settings/button_creation.c	\
		src/menu/settings/display_menu.c \
		src/menu/settings/create_settings_menu.c \
		\
		src/menu/main_menu/display_menu.c	\
		src/menu/main_menu/create_main_menu.c	\
		src/menu/main_menu/buttons.c	\
		\
		src/sounds/create_music_handler.c \
        src/sounds/launch_sound.c \
        src/sounds/stop_sound.c	\
		\
		src/fps/fps.c \
		src/fps/my_int_to_str.c	\
		\
		src/object/sprite.c \
		src/object/text.c	\
		\
		src/background/background.c \
		src/background/destroy_background.c \
		\
		src/cinematic/launch_cinematic.c \
		src/cinematic/selector.c \
		src/cinematic/destroy_ressources.c \
		src/cinematic/cinematic_events.c \
		\
		src/cursor/create_cursor.c \
		src/cursor/update_cursor.c \
		\
		src/entity/create_entity.c \
		src/entity/player_event.c \
		src/entity/detect_collision.c \
		\
		src/view/create_view.c \
		src/view/center_view.c \
		\
		src/generator/random.c \
		src/generator/display.c \
		src/generator/generator.c	\
		src/generator/free_resources.c \
		src/generator/init_resources.c \
		src/generator/complete_maze.c \
		src/generator/algo/recursive_division.c \
		src/generator/algo/kruskal/int_list.c \
		src/generator/algo/kruskal/prepare_maze.c \
		src/generator/algo/kruskal/kruskal.c \
		src/generator/algo/kruskal/get_node_list.c \
		src/generator/algo/kruskal/create_connection.c \
		src/generator/algo/kruskal/finish_maze.c \
		\
		src/particle_engine/add_particle.c \
		src/particle_engine/update_particle.c \
		src/particle_engine/clean_particle_list.c \
		\
		src/dialogue/dialogue_manager.c \
		src/dialogue/display.c \
		src/dialogue/ressources.c \
		src/dialogue/events.c \
		src/dialogue/init_speaker.c \
		src/dialogue/position.c \
		\
		src/string/remove_trailing.c \
		\
		src/sfText/create_text.c \
		\
		src/player/creation/create_player.c \
		src/player/creation/create_weapon.c \
		src/player/weapons/create_weapons_list.c \
		src/player/level_cost.c \
		src/player/level_up.c \
		src/player/attack.c \
		\
		src/credits/credits.c \
		\
		src/save/create_save.c	\
		src/save/choose_save.c	\
		src/save/map.c	\
		src/save/player.c	\
		src/save/weapon.c	\
		\
		src/load/load_save.c	\
		src/load/map.c	\
		src/load/player.c	\
		src/load/weapon.c \

OBJ    =    $(SRC:.c=.o)

CC	=	gcc
CFLAGS	= -Wall
LIB	=	-L./lib -lmy_string -lmy_printf -lmy_stdlib -lm
LDFLAGS	=	-lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio $(LIB)

EXE	=	my_rpg

all:	$(EXE)

%.o	:	%.c
		$(CC) -o $@ -c $^ $(CFLAGS) -g3

$(EXE): $(OBJ)
		@make -C ./lib
		$(CC) -o $(EXE) $(SRC) $(LDFLAGS) -g3

clean:
		@rm -rf $(OBJ)
		@make -C ./lib clean
		@make -C ./tests clean
		@rm -rf vgcore*
		@rm -rf *.gcda
		@rm -rf *.gcno

fclean:	clean
		@make -C ./lib fclean
		@make -C ./tests fclean
		@rm -rf $(EXE)

re:	fclean all

unit_tests:
			@make -C ./tests

tests_run:	unit_tests
			./tests/binary_test
