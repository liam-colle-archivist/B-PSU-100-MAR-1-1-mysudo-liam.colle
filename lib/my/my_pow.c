/*
** EPITECH PROJECT, 2024
** my_pow
** File description:
** libmy
*/

#include "utils.h"

long my_pow(int a, int n)
{
    long power = a;

    if (n == 0)
        return TRUE;
    if (n < 0)
        return FALSE;
    for (int i = 1; i < n; i++)
        power = power * a;
    return power;
}
