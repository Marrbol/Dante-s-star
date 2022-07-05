/*
** EPITECH PROJECT, 2021
** str cmmp
** File description:
** on compare des str et on return un nombre
*/

#include <unistd.h>
#include <stdio.h>

int my_strcmp(char const *s1, char const *s2)
{
    int count = 0 ;
    int i = 0;

    while (s1[i] != '\0' || s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            count = count + (s1[i] - s2[i]);
        }
        i++ ;
    }
    return count;
}
