/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** pas besoin je pense que ta compris
*/

#ifndef MY_H_
    #define MY_H_
    #include <stdarg.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>
    #include <time.h>
    #include <stdbool.h>

typedef struct up_down_s {
    int value;
    bool up;
} up_down_t;

typedef struct map_s {
    char **lab;
    size_t width;
    size_t height;
    size_t i;
    size_t j;
    int value;
} map_t;

char **make_gird(int x, int y);
void replace_zero(map_t *map);
void print_lab(int **lab, int x, int y);
int count_wall(map_t *map);
int count_number(map_t *map);
void break_wall(map_t *map);
void random_stop(map_t *map, int stop, int *counter);
void can_i_change(int **lab, int i , int j, map_t *map);
void change_numbers(map_t *map, size_t x, size_t y);

#endif/* MY_H_*/
