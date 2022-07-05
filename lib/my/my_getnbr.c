/*
** EPITECH PROJECT, 2021
** my_getnbr.c
** File description:
** day04 task05
*/

#include <stdio.h>

int my_getnbr(char const *str)
{
    int m = 0;
    int i = 0;

    while (str[m] != '\0') {
        if (str[m] <= '9' && str[m] >= '0') {
            i = i * 10  + (str[m] - 48);
        }
        m++;
    }
    m = 0;
    while (str[m] != '\0') {
        if (str[m] == '-') {
            i = i * -1;
        }
        m++;
    }
    return (i);
}
