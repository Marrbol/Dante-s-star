/*
** EPITECH PROJECT, 2022
** B-CPE-200-REN-2-1-dante-mael.gouyet
** File description:
** main
*/

#include <generator.h>
#include <string.h>
#include <stdbool.h>

void create_random_part(char **map, size_t i , size_t j)
{
    int random = (rand() % 2);

    map[i][j] = '*';
    if (random == 0)
        map[i - 1][j] = '*';
    else
        map[i][j - 1] = '*';
}

void make_maze(char **map, map_t *lab)
{
    for (size_t i = 2; i < lab->height; i += 2)
        for (size_t j = 2; j < lab->width; j += 2)
            create_random_part(map, i, j);
    map[lab->height -1][lab->width - 1] = '*';
    if (lab->height % 2 == 0)
        map[lab->height - 1][lab->width - 2] = '*';
}

void create_lines(char **map)
{
    for (size_t i = 0; map[i] != NULL; i++)
        map[i][0] = '*';
    for (size_t j = 0; map[0][j] != '\0'; j++)
        map[0][j] = '*';
}

void make_it_imperfect(char *line, map_t *map)
{
    for (size_t i = 0; i < map->width; i++)
        line[i] = '*';
    line[1] = 'X';
}

int main(__attribute__((unused))int ac, char **av)
{
    map_t *map = malloc(sizeof(map_t));
    bool is_perfect = false;

    if (ac < 3 || ac > 4)
        return 84;
    else if (ac == 4 && strcmp("perfect", av[3]) == 0)
        is_perfect = true;
    srand(time(NULL));
    map->width = atoi(av[1]);
    map->height = atoi(av[2]);
    map->lab = make_gird(map->width, map->height);
    create_lines(map->lab);
    make_maze(map->lab, map);
    if (!is_perfect)
        make_it_imperfect(map->lab[map->height - 2], map);
    for (size_t i = 0; i < map->height - 1; i++)
        printf("%s\n", map->lab[i]);
    printf("%s", map->lab[map->height - 1]);
}
