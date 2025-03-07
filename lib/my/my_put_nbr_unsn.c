/*
** EPITECH PROJECT, 2024
** my_put_nbr
** File description:
** day 3, task 7
** my_put_nbr.c
*/

#include "my.h"

void my_put_nbr_unsn_worker(unsigned int nb)
{
    if (nb > 9)
        my_put_nbr_unsn_worker(nb / 10);
    my_putchar('0' + (nb % 10));
}

unsigned int my_put_nbr_unsn(unsigned int nb)
{
    my_put_nbr_unsn_worker(nb);
    my_putchar('\n');
    return nb;
}
