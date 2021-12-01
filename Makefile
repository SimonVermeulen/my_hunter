##
## EPITECH PROJECT, 2021
## BistroMatic
## File description:
## Makefile
##

SRC	=	to_display_list/utils_for_elements.c	\
		to_display_list/create_elements.c		\
		to_display_list/delete_elements.c		\
		utils_for_animated_elements.c			\
		game_struct.c							\
		my_hunter.c								\
		main_loop.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter

all:	$(NAME)

$(NAME):
	$(MAKE) -C ./lib/my/
	gcc -o $(NAME) $(SRC) -L./lib/my -lmy -g3 -lcsfml-graphics -lcsfml-system

clear:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME) $(OBJ)

re: fclean all
