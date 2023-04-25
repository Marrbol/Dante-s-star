##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC	=	solver.c	\
		unknown_method.c	\
		intersections.c	\
		direction.c	\
		error.c	\
		back_to_the_future.c	\
		insolvable_map.c

OBJ	=	$(SRC:.c=.o)

NAME	= solver

LIB	= -L../ -lmy

CFLAGS	=	-Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LIB)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f vgcore.*

debug: CFLAGS += -g
debug: re

re:	fclean all
