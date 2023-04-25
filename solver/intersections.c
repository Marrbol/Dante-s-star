/*
** EPITECH PROJECT, 2022
** intersections.c
** File description:
** take care of thee intersections in the map
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "../lib/my.h"
#include "list.h"

intersection_t *init_struct(void)
{
    intersection_t *intersection = malloc(sizeof(intersection_t));
    intersection->next = NULL;
    intersection->back = NULL;
    intersection->intersection = 'n';
    intersection->x = 0;
    intersection->y = 0;
    intersection->nbr_intersect = 0;
    intersection->first = true;
    return intersection;
}

void new_intersection(intersection_t *head, int x, int y, char direction)
{
    intersection_t *intersection = head;
    intersection_t *new_intersection = malloc(sizeof(intersection_t));

    intersection->nbr_intersect++;
    for (; intersection->next != NULL; intersection = intersection->next);
    new_intersection->next = NULL;
    new_intersection->back = intersection;
    intersection->next = new_intersection;
    new_intersection->intersection = direction;
    new_intersection->x = x;
    new_intersection->first = false;
    new_intersection->y = y;
}

bool go_to_intersection(intersection_t *intersection, obj_t *obj)
{
    intersection_t *list = intersection->next;

    if ((obj->y == intersection->y && obj->x == intersection->x)) {
        obj->y = list->y;
        obj->x = list->x;
        if (list->next != NULL) {
            intersection->nbr_intersect--;
            list->back->next = list->next;
            list->next->back = list->back;
            return true;
        }
    }
    return false;
}
