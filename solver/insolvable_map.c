/*
** EPITECH PROJECT, 2022
** insolvable_mpa.c
** File description:
** find if th emap is insolvable
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "../lib/my.h"
#include "list.h"

void insolvable_map(obj_t *obj, int number_line)
{
    if (obj->map[number_line - 2][my_strlen(obj->map[0]) - 1] == 'X' &&
    obj->map[number_line - 1][my_strlen(obj->map[0]) - 2] == 'X') {
        printf("no solution found");
        exit(0);
    }
    if (obj->map[number_line - 1][my_strlen(obj->map[0]) - 1] == 'X') {
        printf("no solution found");
        exit(0);
    }
    if (obj->map[0][0] == 'X') {
        printf("no solution found");
        exit(0);
    }
}
