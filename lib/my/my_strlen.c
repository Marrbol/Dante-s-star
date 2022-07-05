/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** task 3 day 4
*/

int my_strlen(char const *str)
{
    int number = 0;

    while (str[number] != '\0') {
        number += 1;
    }
    return number;
}
