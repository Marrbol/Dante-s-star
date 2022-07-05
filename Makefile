##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

all:
	make -C lib/
	make -C generator/
	make -C solver/

clean:
	make -C lib/ clean
	make -C generator/ clean
	make -C solver/ clean

fclean:
	make -C lib/ fclean
	make -C generator/ fclean
	make -C solver/ fclean

re: fclean all
