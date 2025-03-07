/*
** EPITECH PROJECT, 2024
** my_put_nbr_retchrn
** File description:
** my_printf
*/

#include "my.h"

int my_put_nbr_retchrn(int nb)
{
    int chr_len = my_get_nbr_decimals(nb, 1);

    my_put_nbr_worker(nb);
    return chr_len;
}

int my_put_nbr_un_retchrn(unsigned int nb)
{
    int chr_len = my_get_nbr_decimals_uns(nb, 1);

    my_put_nbr_unsn_worker(nb);
    return chr_len;
}
