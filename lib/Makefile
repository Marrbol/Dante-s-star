##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile lib
##

SRC	=	my/my_getnbr.c	\
		my/my_open.c	\
		my/my_printf.c	\
		my/my_putchar.c	\
		my/my_put_nbr.c	\
		my/my_putstr.c	\
		my/my_read.c	\
		my/my_strlen.c	\
		my/disp_stdarg.c	\
		my/my_strlen_fisrt_line.c	\
		my/print_2d_func.c	\
		my/my_strcmp.c	\
		my/my_str_to_array.c	\
		my/get_nbr_line.c

OBJ	=	$(SRC:.c=.o)

CFLAGS =	-Wall -Wextra

TESTS_FLAG = --coverage -lcriterion

NAME = libmy.a

all: $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../

clean:
	rm -f my/*.o
	rm -f *.o

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re:	fclean all

debug:	CFLAGS+= -g
debug:	all
