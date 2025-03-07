/*
** EPITECH PROJECT, 2024
** my_get_nbr_decimals
** File description:
** libmy
*/

#include "my.h"

int my_get_nbr_decimals(long nb, int count)
{
    if (nb < 0) {
        nb = nb * -1;
        count++;
    }
    if (nb > 9)
        return my_get_nbr_decimals(nb / 10, count + 1);
    return count;
}

int my_get_nbr_decimals_ull(unsigned long long nb, int count)
{
    if (nb > 9)
        return my_get_nbr_decimals_ull(nb / 10, count + 1);
    return count;
}

int my_get_nbr_decimals_ll(long long nb, int count)
{
    if (nb < 0) {
        nb = nb * -1;
        count++;
    }
    if (nb > 9)
        return my_get_nbr_decimals_ll(nb / 10, count + 1);
    return count;
}

int my_get_nbr_decimals_s(short nb, int count)
{
    if (nb < 0) {
        nb = nb * -1;
        count++;
    }
    if (nb > 9)
        return my_get_nbr_decimals_s(nb / 10, count + 1);
    return count;
}
