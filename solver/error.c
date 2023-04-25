/*
** EPITECH PROJECT, 2022
** error.c
** File description:
** take care of the error
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "../lib/my.h"
#include "list.h"

void error(char *buffer)
{
    if (buffer == NULL)
        exit(84);
    for (int counter = 0; buffer[counter] != '\0'; counter++) {
        if (buffer[counter] != 'X' && buffer[counter] != '*'
        && buffer[counter] != '\n')
            exit(84);
    }
}
