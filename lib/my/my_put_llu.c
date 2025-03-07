/*
** EPITECH PROJECT, 2024
** my_put_llu
** File description:
** libmy
*/

#include "my.h"

void my_put_llu_worker(unsigned long long nb)
{
    if (nb > 9)
        my_put_long_long_worker(nb / 10);
    my_putchar('0' + (nb % 10));
}

long my_put_llu(unsigned long long nb)
{
    my_put_long_worker(nb);
    my_putchar('\n');
    return nb;
}
