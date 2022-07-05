/*
** EPITECH PROJECT, 2022
** list.h
** File description:
** make chained list for the intersections
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdbool.h>
#include "generator.h"

#ifndef LIST_H_
    #define LIST_H_

typedef struct intersection_s {
    size_t x;
    size_t y;
    char intersection;
    bool first;
    int nbr_intersect;
    struct intersection_s *next;
    struct intersection_s *back;
} intersection_t;

intersection_t *init_struct(void);
void error(char *buffer);
int down_solver(intersection_t *intersection, map_t *map);
int up_solver(intersection_t *intersection, map_t *map);
int left_solver(intersection_t *intersection, map_t *map);
int right_solver(intersection_t *intersection, map_t *map);
int **unknown_methode(intersection_t *intersection, int **matrix, char **map);
void new_intersection(intersection_t *head, int x, int y, char direction);
int back_to_the_future(intersection_t *intersection, int **matrix);
int go_to_intersection(intersection_t *intersection, size_t *y, size_t *x);

#endif
