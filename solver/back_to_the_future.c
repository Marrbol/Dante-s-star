/*
** EPITECH PROJECT, 2022
** back_to_the_future.c
** File description:
** go back to a place i had to been
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "../lib/my.h"
#include "list.h"

static bool verif_left_and_right(obj_t *obj)
{
    if (obj->x > 0 && obj->matrix[obj->y][obj->x - 1] != -1 &&
        obj->matrix[obj->y][obj->x - 1] == obj->matrix[obj->y][obj->x] - 1) {
        obj->x = obj->x - 1;
        return true;
    }
    if (obj->matrix[obj->y][obj->x + 1] != -1 &&
        obj->matrix[obj->y][obj->x + 1] == obj->matrix[obj->y][obj->x] - 1) {
        obj->x = obj->x + 1;
        return true;
    }
    return false;
}

bool back_to_the_future(intersection_t *intersection, obj_t *obj)
{
    bool verif = false;

    verif = verif_left_and_right(obj);
    if (obj->matrix[obj->y + 1] != NULL && obj->matrix[obj->y + 1][obj->x] !=
        -1 && obj->matrix[obj->y + 1][obj->x]
        == obj->matrix[obj->y][obj->x] - 1) {
        obj->y = obj->y + 1;
        verif = true;
    }
    if (obj->y > 0 && obj->matrix[obj->y - 1][obj->x] != -1 &&
        obj->matrix[obj->y - 1][obj->x] == obj->matrix[obj->y][obj->x] - 1) {
        obj->y = obj->y - 1;
        verif = true;
    }
    if (verif == false)
        verif = go_to_intersection(intersection, obj);
    return verif;
}
