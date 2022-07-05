/*
** EPITECH PROJECT, 2021
** disp_stdarg.c
** File description:
** print the arguments in funtion of their types
*/

#include <stdarg.h>
#include <stdio.h>

int my_put_nbr(int nb);
int my_strlen(char const *str);
void my_putchar(char c);
int my_putstr(char const *str);

void disp_stdarg(char *s, va_list list, int counter)
{
    if (s[counter] == '%' && s[counter + 1] == 'd')
        my_put_nbr(va_arg(list, int));
    if (s[counter] == '%' && s[counter + 1] == 's')
        my_putstr(va_arg(list, char *));
    if (s[counter] == '%' && s[counter + 1] == 'c')
        my_putchar(va_arg(list, int));
}
