/*
** EPITECH PROJECT, 2021
** fs_open_file.c
** File description:
** step 1 I
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int my_putstr(char const *str);

int my_open(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    if (fd < 0)
        return 84;
    return fd;
}
