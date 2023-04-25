/*
** EPITECH PROJECT, 2022
** solver.c
** File description:
** the solver of a maze
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "../lib/my.h"
#include "list.h"

void my_free(char *buffer, char **map, obj_t *obj, intersection_t *head)
{
    free(buffer);
    for (int counter = 0; map[counter] != NULL; counter++) {
        free(map[counter]);
        free(obj->matrix[counter]);
    }
    while (head->next->next != NULL) {
        head = head->next;
        free(head->back);
    }
    free(head);
    free(map);
    free(obj->matrix);
    free(obj);
}

int put_in(char **map, int counter2, int counter)
{
    if (map[counter2][counter] == '*')
        return 1;
    else
        return 0;
    return -1;
}

int **make_an_int_array(char **map, int size)
{
    int **matrix = malloc(sizeof(int *) * (size + 1));
    int size_line = my_strlen(map[0]);

    for (int counter2 = 0; map[counter2] != NULL; counter2++) {
        matrix[counter2] = malloc(sizeof(int) * (size_line + 1));
        matrix[counter2][size_line] = -1;
        for (int counter = 0; map[counter2][counter] != '\0'; counter++) {
            matrix[counter2][counter] = put_in(map, counter2, counter);
        }
    }
    matrix[size - 1][size_line] = -1;
    matrix[size] = NULL;
    return matrix;
}

int number_of_line(char **map)
{
    int number_of_line = 0;

    for (; map[number_of_line] != NULL; number_of_line++);
    return number_of_line;
}

int main(int ac, char **av)
{
    if (ac != 2 || av[1][0] == '\0')
        return 84;
    char *buffer = NULL;
    int number_line = 0;
    intersection_t *intersection = init_struct();
    obj_t *obj = malloc(sizeof(obj_t));

    buffer = my_read(buffer, av[1]);
    error(buffer);
    obj->map = str_to_array(buffer, '\n');
    number_line = number_of_line(obj->map);
    insolvable_map(obj, number_line);
    obj->matrix = make_an_int_array(obj->map, number_line);
    unknown_methode(intersection, obj);
    find_the_way(obj);
    print_2d_func(obj->map);
    my_free(buffer, obj->map, obj, intersection);
    return 0;
}
