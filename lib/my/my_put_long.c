/*
** EPITECH PROJECT, 2024
** my_put_long_nbr
** File description:
** day 3, task 7
** my_put_nbr.c
*/

#include "my.h"

void my_put_long_worker(long nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb > 9)
        my_put_long_worker(nb / 10);
    my_putchar('0' + (nb % 10));
}

long my_put_long(long nb)
{
    my_put_long_worker(nb);
    my_putchar('\n');
    return nb;
}
