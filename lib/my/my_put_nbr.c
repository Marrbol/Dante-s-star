/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** task1 day7
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 0 && nb <= 9) {
        my_putchar(nb + 48);
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_putchar(nb % 10 + 48);
    }
    return (0);
}
