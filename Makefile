##
## EPITECH PROJECT, 2023
## project
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/gloop.c \
		src/my_rpg.c \
		\
		src/map/create_map_object.c \
		src/map/create_tile.c \
		src/map/display_map.c \
		src/map/extract_map_object.c \
		src/map/get_manifest_info.c \
		src/map/load_manifest.c \
		src/map/load_map.c \
		\
		src/event/main_event.c \
		src/app/create_app.c \
		src/app/destroy_app.c \
		src/window/create_window.c \
		src/array_manipulation/split.c \
		src/array_manipulation/array_manipulation.c \
		src/splash_screen/create_splash_screen.c    \
        src/splash_screen/splash_screen.c    \
        src/splash_screen/update_splash_screen.c    \
        src/splash_screen/clean_splash_screen.c \
        src/sounds/musics/startup_sound.c \

OBJ	=	$(SRC:.c=.o)

CC	=	gcc
CFLAGS	=
FLAGS	= -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio
LIB	=	-L./lib -lmy_string -lmy_printf -lmy_stdlib
EXE	=	my_rpg

all:	$(EXE)

$(EXE):
		@make -C ./lib
		$(CC) -o $(EXE) $(SRC) $(CFLAGS) $(FLAGS) $(LIB) -g3

clean:
		@make -C ./lib clean
		@make -C ./tests clean
		@rm -rf vgcore*
		@rm -rf *.gcda
		@rm -rf *.gcno

fclean:	clean
		@make -C ./lib fclean
		@make -C ./tests fclean
		@rm -rf $(EXE)

valgrind:
			@make -C ./lib
			$(CC) -o $(EXE) $(SRC) $(CFLAGS) $(FLAGS) $(LIB) -g3

re:	fclean all

unit_tests:
			@make -C ./tests

tests_run:	unit_tests
			./tests/binary_test
