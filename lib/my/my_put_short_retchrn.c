/*
** EPITECH PROJECT, 2024
** my_put_nbr_retchrn
** File description:
** my_printf
*/

#include "my.h"

int my_put_short_retchrn(short nb)
{
    int chr_len = my_get_nbr_decimals_s(nb, 1);

    my_put_short_worker(nb);
    return chr_len;
}

int my_put_short_u_retchrn(unsigned short nb)
{
    int chr_len = my_get_nbr_decimals_s(nb, 1);

    my_put_short_u_worker(nb);
    return chr_len;
}
