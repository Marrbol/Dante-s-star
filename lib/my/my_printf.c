/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** recode the printf function
*/

#include <stdarg.h>
#include <stdio.h>

int my_put_nbr(int nb);
int my_strlen(char const *str);
void my_putchar(char c);
int my_putstr(char const *str);
void disp_stdarg(char *s, ...);

int binaire(int number)
{
    int rest = 0;

    if (number >= 2) {
        rest = number % 2;
        number = number / 2;
        binaire(number);
    } else if (number > 0) {
        rest = number % 2;
        number = number / 2;
    }
    my_putchar(rest + '0');
    return (number);
}

void disp_the_s_flag(char *str)
{
    int counter = 0;

    while (str[counter] != '\0') {
        if (str[counter] < 33 || str[counter] == 127) {
            my_putchar(92);
            counter++;
        } else {
            my_putchar(str[counter]);
            counter++;
        }
    }
}

void disp_stdarg2(char *s, va_list list, int counter)
{
    int number = 0;

    if (s[counter] == '%' && s[counter + 1] == 'b') {
        number = va_arg(list, int);
        my_putchar(binaire(number));
    }
    if (s[counter] == '%' && s[counter + 1] == 'S') {
        disp_the_s_flag(va_arg(list, char *));
    }
}

int my_printf(char *s, ...)
{
    va_list list;
    int counter = 0;

    va_start(list, s);
    while (s[counter] != '\0') {
        if (s[counter] == '%') {
            disp_stdarg(s, list, counter);
            disp_stdarg2(s, list, counter);
            counter = counter + 2;;
        } else {
            my_putchar(s[counter]);
            counter++;
        }
    }
    va_end(list);
    return 0;
}
