/*
** EPITECH PROJECT, 2021
** print_2d_func.c
** File description:
** print 2d func
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int my_strlen(char const *str);
int my_printf(char *s, ...);

void print_2d_func(char **str)
{
    int counter = 0;
    for (; str[counter + 1] != NULL; counter++)
        my_printf("%s\n", str[counter]);
    my_printf("%s", str[counter]);
}

void print_2d_int_func(int **str, size_t xmax, size_t ymax)
{
    for (size_t counter2 = 0; counter2 < ymax; counter2++) {
        for (size_t counter = 0; counter < xmax; counter++)
            my_printf("%d", str[counter2][counter]);
        my_printf("\n");
    }
}
