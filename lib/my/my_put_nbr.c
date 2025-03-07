/*
** EPITECH PROJECT, 2024
** my_put_nbr
** File description:
** day 3, task 7
** my_put_nbr.c
*/

#include "my.h"

void my_put_nbr_worker(long nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb > 9)
        my_put_nbr_worker(nb / 10);
    my_putchar('0' + (nb % 10));
}

int my_put_nbr(int nb)
{
    my_put_nbr_worker(nb);
    my_putchar('\n');
    return nb;
}

void my_put_nbr_worker_lr(long nb)
{
    if (nb < 0) {
        my_putchar('-');
        my_putchar('\n');
        nb = nb * -1;
    }
    if (nb > 9)
        my_put_nbr_worker_lr(nb / 10);
    my_putchar('0' + (nb % 10));
    my_putchar('\n');
}

int my_put_nbr_lr(int nb)
{
    my_put_nbr_worker_lr(nb);
    return nb;
}
