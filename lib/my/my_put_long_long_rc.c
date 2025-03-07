/*
** EPITECH PROJECT, 2024
** my_put_nbr_retchrn
** File description:
** my_printf
*/

#include "my.h"

int my_put_long_long_rc(long long nb)
{
    int chr_len = my_get_nbr_decimals_ll(nb, 1);

    my_put_long_long_worker(nb);
    return chr_len;
}

int my_put_llu_rc(unsigned long long nb)
{
    int chr_len = my_get_nbr_decimals_ll(nb, 1);

    my_put_long_long_worker(nb);
    return chr_len;
}
