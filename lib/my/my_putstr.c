/*
** EPITECH PROJECT, 2021
** my_putstr.c
** File description:
** print str
*/

#include <unistd.h>

void my_putchar(char c);
int my_strlen(char const *str);

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
    return (0);
}
