/*
** EPITECH PROJECT, 2022
** generator
** File description:
** create_lab
*/

#include <stdlib.h>
#include <stdio.h>

char **make_gird(int x, int y)
{
    char **lab = malloc(sizeof(char *) * (y + 1));

    for (int i = 0; i != y; i++)
        lab[i] = malloc(sizeof(char) * (x + 1));
    lab[y] = NULL;
    for (int i = 0; lab[i] != NULL; i++)
        for (int j = 0; j < x; j++) {
            lab[i][j] = 'X';
            lab[i][j + 1] = '\0';
        }
    return lab;
}
