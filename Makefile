##
## EPITECH PROJECT, 2023
## project
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/gloop.c \
		src/my_rpg.c \
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
		\
		src/event/main_event.c \
		\
		src/app/create_app.c \
		src/app/destroy_app.c \
		\
		src/window/create_window.c \
		\
		src/array_manipulation/split.c \
		src/array_manipulation/array_manipulation.c \
		\
		src/splash_screen/create_splash_screen.c \
        src/splash_screen/splash_screen.c \
        src/splash_screen/update_splash_screen.c  \
        src/splash_screen/clean_splash_screen.c \
		\
        src/sounds/musics/startup_sound.c \
		\
		src/fps/fps.c \
		src/fps/my_int_to_str.c	\
		\
		src/object/sprite.c \
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
		src/entity/create_entity.c \
		src/entity/player_event.c \
		src/entity/detect_collision.c \
		\
		src/view/create_view.c \
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
		\
		src/string/remove_trailing.c \

OBJ	=	$(SRC:.c=.o)

CC	=	gcc
CFLAGS	= -Wall
LDFLAGS	= -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio \
-L./lib -lmy_string -lmy_printf -lmy_stdlib
EXE	=	my_rpg

all:	$(EXE)

%.o	:	%.c
		@echo COMPILATION
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
