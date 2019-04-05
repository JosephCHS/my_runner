##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Made by Joseph C.
##

SRC	=	src/my_runner.c			\
		src/run_global.c		\
		src/run_launcher.c		\
		src/run_menu.c			\
		src/run_help.c			\
		src/run_check_error.c		\
		src/run_init_array.c		\
		src/run_game.c			\
		src/run_destroy.c		\
		src/run_move_sprite.c		\
		src/run_load_clock_music.c	\
		src/run_ennemy.c		\
		src/run_set_struct.c		\
		src/run_which_p_phase.c		\
		src/run_jump.c			\
		src/run_life.c			\
		src/run_score.c			\
		src/run_map.c			\
		src/run_text.c			\
		src/my_putstr.c			\
		src/my_strcmp.c			\
		src/my_put_nbr.c		\
		src/my_put_error_str.c		\

HDR	=	-I ./include

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra $(HDR)

NAME	=	my_runner

LDFLAGS =	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

CC	=	gcc

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(SRC) $(LDFLAGS) $(HDR)

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
