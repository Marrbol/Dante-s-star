/*
** EPITECH PROJECT, 2022
** my_str_to_array.c
** File description:
** change a char * to char ** with a separator
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int my_strlen(char const *str);

static int count_delim(char const *str, char delim)
{
    int counter_delim = 1;

    if (!str || str[0] == '\0')
        return 0;
    for (int counter = 0; str[counter] != '\0'; counter++) {
        if (str[counter] == delim)
            counter_delim++;
    }
    return counter_delim;
}

static int len_before_delim(char const *str, char delim, int x)
{
    int lenght = 0;

    for (; str[x] != delim; x++, lenght++) {
        if (str[x] == '\0')
            return lenght;
    }
    return lenght;
}

static char **filling(char const *str, char **map, char delim)
{
    int idxChar = 0;
    int idxWord = 0;
    int wordSize = len_before_delim(str, delim, idxChar);

    map[0] = malloc(sizeof(char) * (wordSize + 1));
    map[0][wordSize] = '\0';
    for (int x = 0; x < my_strlen(str) && str[x] != '\0'; x++) {
        if (str[x] == delim) {
            idxWord++;
            wordSize = len_before_delim(str, delim, (x + 1));
            map[idxWord] = malloc(sizeof(char) * (wordSize + 1));
            map[idxWord][wordSize] = '\0';
            idxChar = 0;
            continue;
        }
        map[idxWord][idxChar] = str[x];
        idxChar++;
    }
    map[idxWord][wordSize] = '\0';
    return map;
}

char **str_to_array(char const *str, char delim)
{
    int nmb_delim = count_delim(str, delim);
    char **map = malloc(sizeof(char *) * (nmb_delim + 1));

    map[nmb_delim] = NULL;
    if (nmb_delim > 0)
        map = filling(str, map, delim);
    return map;
}
