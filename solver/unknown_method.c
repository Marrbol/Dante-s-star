/*
** EPITECH PROJECT, 2022
** kruska_method.c
** File description:
** use an unknown method
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "../lib/my.h"
#include "list.h"

static int find_way_down_and_up(obj_t *obj)
{
    if (obj->matrix[obj->y + 1] != NULL && obj->matrix[obj->y + 1][obj->x] !=
    -1 && obj->matrix[obj->y + 1][obj->x] == obj->matrix[obj->y][obj->x] - 1) {
        obj->y = obj->y + 1;
        obj->map[obj->y][obj->x] = 'o';
        return 1;
    }
    if (obj->matrix[obj->y - 1][obj->x] != -1 &&
    obj->matrix[obj->y - 1][obj->x] == obj->matrix[obj->y][obj->x] - 1) {
        obj->y = obj->y - 1;
        obj->map[obj->y][obj->x] = 'o';
        return 1;
    }
    return 0;
}

void find_the_way(obj_t *obj)
{
    for (obj->y = 0, obj->x = 0; obj->matrix[obj->y][obj->x] != 1;) {
        obj->map[obj->y][obj->x] = 'o';
        if (obj->matrix[obj->y][obj->x + 1] != -1 &&
            obj->matrix[obj->y][obj->x + 1] ==
            obj->matrix[obj->y][obj->x] - 1) {
            obj->x = obj->x + 1;
            obj->map[obj->y][obj->x] = 'o';
            continue;
        }
        if (find_way_down_and_up(obj) == 1)
            continue;
        if (obj->x > 0 && obj->matrix[obj->y][obj->x - 1] != -1 &&
            obj->matrix[obj->y][obj->x - 1] ==
            obj->matrix[obj->y][obj->x] - 1) {
            obj->x = obj->x - 1;
            obj->map[obj->y][obj->x] = 'o';
            continue;
        }
    }
}

static bool go_right_and_down(intersection_t *intersection, obj_t *obj)
{
    if (obj->matrix[obj->y][obj->x + 1] != -1 &&
        obj->matrix[obj->y][obj->x + 1] == 1 &&
        (obj->y != intersection->y && obj->x != intersection->x - 1)) {
        go_right(intersection, obj);
        return true;
    }
    if (obj->matrix[obj->y + 1] != NULL &&
        obj->matrix[obj->y + 1][obj->x] == 1 && (obj->y != intersection->y - 1
        && obj->x != intersection->x)) {
        go_down(intersection, obj);
        return true;
    }
    return false;
}

static void resolve(intersection_t *intersection, obj_t *obj)
{
    while (obj->y != 0 || obj->x != 0) {
        if (obj->y > 0 && obj->matrix[obj->y - 1][obj->x] == 1) {
            go_up(intersection, obj);
            continue;
        }
        if (obj->x > 0 && obj->matrix[obj->y][obj->x - 1] != -1 &&
            obj->matrix[obj->y][obj->x - 1] == 1) {
            go_left(intersection, obj);
            continue;
        }
        if (go_right_and_down(intersection, obj) == true)
            continue;
        if (back_to_the_future(intersection, obj) == false) {
            printf("no solution found");
            exit(0);
        }
    }
}

void unknown_methode(intersection_t *intersection, obj_t *obj)
{
    size_t counter = 0;
    size_t counter2 = 0;

    for (; obj->map[counter2] != NULL; counter2++)
        for (; obj->map[counter2][counter] != '\0'; counter++);
    obj->x = counter - 1;
    obj->y = counter2 - 1;
    intersection->x = counter - 1;
    intersection->y = counter2 - 1;
    resolve(intersection, obj);
}
