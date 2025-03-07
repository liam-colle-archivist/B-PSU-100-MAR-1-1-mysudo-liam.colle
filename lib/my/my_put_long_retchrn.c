/*
** EPITECH PROJECT, 2024
** my_put_nbr_retchrn
** File description:
** my_printf
*/

#include "my.h"

int my_put_long_retchrn(long nb)
{
    int chr_len = my_get_nbr_decimals(nb, 1);

    my_put_long_worker(nb);
    return chr_len;
}
