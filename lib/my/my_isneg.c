/*
** EPITECH PROJECT, 2024
** my_isneg
** File description:
** day 3, task 4
** my_isneg.c
*/

#include "my.h"
#include "utils.h"

int my_isneg(int nb)
{
    if (nb < 0)
        my_putstr("N\n");
    else
        my_putstr("P\n");
    return FUNC_SUCCESS;
}
