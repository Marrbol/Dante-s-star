/*
** EPITECH PROJECT, 2021
** fs_understand_return_of_read.c
** File description:
** read a file
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int my_putstr(char const *str);
int my_printf(char *s, ...);

int my_open(char const *filepath);

char *my_read(char *buffer, char *filepath)
{
    int fd = my_open(filepath);
    struct stat statbuf;
    stat(filepath, &statbuf);
    buffer = malloc(sizeof(char) * (statbuf.st_size + 1));
    int size = read(fd, buffer, statbuf.st_size);

    if (size == -1 || fd == 84 || size == 0)
        return NULL;
    else if (size < statbuf.st_size)
        return NULL;
    buffer[statbuf.st_size] = '\0';
    close(fd);
    return buffer;
}
