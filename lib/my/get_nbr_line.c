/*
** EPITECH PROJECT, 2022
** get_nbr_line
** File description:
** get yhe number of line in char **
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int get_nbr_line(char **str)
{
    int y = 0;
    int counter = 1;

    if (str[0] == NULL)
        return 0;
    for (; str[y] != NULL; y++, counter++);
    return counter;
}

int get_nbr_line_matrix(int **matrix)
{
    int y = 0;
    int counter = 1;

    if (matrix[0] == NULL)
        return 0;
    for (; matrix[y] != NULL; y++, counter++);
    return counter;
}
