/*
** EPITECH PROJECT, 2022
** direction.c
** File description:
** go to the direction in the map
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "../lib/my.h"
#include "list.h"

void go_right(intersection_t *intersection, obj_t *obj)
{
    while (obj->matrix[obj->y][obj->x + 1] != -1 && obj->matrix[obj->y]
            [obj->x + 1] != 0 && obj->matrix[obj->y][obj->x + 1] == 1) {
        if (obj->matrix[obj->y + 1] == NULL &&
            obj->matrix[obj->y][obj->x + 2] == -1)
            break;
        obj->x = obj->x + 1;
        if (obj->matrix[obj->y + 1] != NULL &&
            obj->matrix[obj->y + 1][obj->x] == 1)
            new_intersection(intersection, obj->x, obj->y, 'd');
        if (obj->matrix[obj->y - 1][obj->x] == 1)
            new_intersection(intersection, obj->x, obj->y, 'u');
        obj->matrix[obj->y][obj->x] = obj->matrix[obj->y][obj->x - 1] + 1;
    }
}

void go_left(intersection_t *intersection, obj_t *obj)
{
    while (obj->x > 0 && obj->matrix[obj->y][obj->x - 1] != -1 &&
            obj->matrix [obj->y][obj->x - 1] != 0 &&
            obj->matrix[obj->y][obj->x - 1] == 1) {
        obj->x = obj->x - 1;
        obj->matrix[obj->y][obj->x] = obj->matrix[obj->y][obj->x + 1] + 1;
        if (obj->matrix[obj->y + 1] != NULL &&
            obj->matrix[obj->y + 1][obj->x] == 1)
            new_intersection(intersection, obj->x, obj->y, 'd');
        if (obj->y > 0 && obj->matrix[obj->y - 1][obj->x] == 1)
            new_intersection(intersection, obj->x, obj->y, 'u');
    }
}

void go_up(intersection_t *intersection, obj_t *obj)
{
    while (obj->y > 0 && obj->matrix[obj->y - 1][obj->x] != -1 &&
            obj->matrix[obj->y - 1][obj->x] != 0 &&
            obj->matrix[obj->y - 1][obj->x] == 1) {
        if (obj->x > 0 && obj->matrix[obj->y][obj->x - 1] == 1)
            new_intersection(intersection, obj->x, obj->y, 'l');
        if (obj->matrix[obj->y][obj->x + 1] == 1)
            new_intersection(intersection, obj->x, obj->y, 'r');
        obj->y = obj->y - 1;
        obj->matrix[obj->y][obj->x] = obj->matrix[obj->y + 1][obj->x] + 1;
    }
}

void go_down(intersection_t *intersection, obj_t *obj)
{
    while (obj->matrix[obj->y + 1] != NULL &&
            obj->matrix[obj->y + 1][obj->x] != 0 &&
            obj->matrix[obj->y + 1][obj->x] == 1) {
        if (obj->matrix[obj->y + 2] == NULL &&
            obj->matrix[obj->y][obj->x + 1] == -1)
            break;
        if (obj->x > 0 && obj->matrix[obj->y][obj->x - 1] == 1)
            new_intersection(intersection, obj->x, obj->y, 'l');
        if (obj->matrix[obj->y][obj->x + 1] == 1)
            new_intersection(intersection, obj->x, obj->y, 'r');
        obj->y = obj->y + 1;
        obj->matrix[obj->y][obj->x] = obj->matrix[obj->y - 1][obj->x] + 1;
    }
}
