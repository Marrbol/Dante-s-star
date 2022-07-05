/*
** EPITECH PROJECT, 2021
** fs_print_first_line.c
** File description:
** get the size of the fisrt line
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

void my_putchar(char c);

int my_strlen_first_line(char const *str)
{
    int counter = 0;
    int counter2 = 0;

    for (; str[counter] != '\n'; counter++);
    counter++;
    counter2 = counter;
    for (; str[counter] != '\n'; counter++) {
    }
    counter = counter - counter2;
    return counter;
}
