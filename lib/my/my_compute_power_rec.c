/*
** EPITECH PROJECT, 2024
** my_compute_factorial_rec
** File description:
** day 5, task 4
** my_compute_factorial_rec.c
*/

#include <stdio.h>
#include <limits.h>
#include "my.h"
#include "utils.h"

int my_compute_power_rec(int nb, int p)
{
    if (p == 0)
        return TRUE;
    if (p < 0)
        return FALSE;
    if (nb > INT_MAX)
        return FALSE;
    return nb * my_compute_power_rec(nb, p - 1);
}
