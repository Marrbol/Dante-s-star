##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC			=	sources/main.c		\
				sources/create_lab.c\

CFLAGS	=	  -Wall -Wextra -I ./include -I ../lib/include

LIB	= -L ../lib -lmy

OBJ = $(SRC:.c=.o)

NAMELIB = libmy.a

BINAME = generator

$(NAMELIB): $(OBJ)
			gcc $(OBJ) -o $(BINAME) $(CFLAGS) $(LIB)

all: $(NAMELIB)
	make -C ../lib/

clean:
	rm -f $(OBJ)
	make -C ../lib/ clean

fclean: clean
	rm -f $(BINAME)
	rm -f vgcore.*
	rm -f *~

re: fclean all

debug: CFLAGS += -g
debug: re
