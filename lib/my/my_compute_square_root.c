/*
** EPITECH PROJECT, 2024
** my_compute_square_root
** File description:
** day 5, task 5
** my_compute_square_root.c
*/

#include <limits.h>
#include "my.h"
#include "utils.h"

static int find_square_root(int nb, int i)
{
    int pow = my_compute_power_rec(i, 2);

    if (i == nb)
        return 0;
    if (pow == nb)
        return i;
    return find_square_root(nb, i + 1);
}

int my_compute_square_root(int nb)
{
    if (nb > INT_MAX || nb <= 0)
        return 0;
    return find_square_root(nb, 0);
}
