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

typedef struct obj_s {
    int **matrix;
    size_t x;
    size_t y;
    char **map;
} obj_t;

intersection_t *init_struct(void);
void error(char *buffer);
void go_down(intersection_t *intersection, obj_t *obj);
void go_up(intersection_t *intersection, obj_t *obj);
void go_left(intersection_t *intersection, obj_t *obj);
void go_right(intersection_t *intersection, obj_t *obj);
void unknown_methode(intersection_t *intersection, obj_t *obj);
void new_intersection(intersection_t *head, int x, int y, char direction);
bool back_to_the_future(intersection_t *intersection, obj_t *obj);
bool go_to_intersection(intersection_t *intersection, obj_t *obj);
int right_direction(intersection_t *intersection, int **matrix, size_t *y,
                    size_t *x);
int left_direction(intersection_t *intersection, int **matrix, size_t *y,
                    size_t *x);
int up_direction(intersection_t *intersection, int **matrix, size_t *y,
                    size_t *x);
int down_direction(intersection_t *intersection, int **matrix, size_t *y,
                    size_t *x);
void find_the_way(obj_t *obj);
void insolvable_map(obj_t *obj, int number_line);

#endif
