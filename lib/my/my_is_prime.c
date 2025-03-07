/*
** EPITECH PROJECT, 2024
** my_is_prime
** File description:
** day 5, task 6
** my_is_prime.c
*/

#include "my.h"
#include "utils.h"

int find_prime(int nb, int i)
{
    if (nb < 2)
        return FALSE;
    if (nb % i == 0)
        return FALSE;
    if (i * i > nb)
        return TRUE;
    return find_prime(nb, i + 1);
}

int my_is_prime(int nb)
{
    return find_prime(nb, 2);
}
