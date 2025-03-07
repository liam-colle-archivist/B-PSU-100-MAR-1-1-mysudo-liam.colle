/*
** EPITECH PROJECT, 2024
** my_get_nbr_decimals
** File description:
** libmy
*/

#include "my.h"

int my_get_nbr_decimals_u(unsigned int nb, int count)
{
    if (nb > 9)
        return my_get_nbr_decimals_u(nb / 10, count + 1);
    return count;
}

int my_get_nbr_decimals_uns(unsigned short nb, int count)
{
    if (nb > 9)
        return my_get_nbr_decimals_uns(nb / 10, count + 1);
    return count;
}
