/*
** EPITECH PROJECT, 2024
** my_print_float
** File description:
** my_print_float.c
*/

#include "my.h"

int my_print_float(float n)
{
    float n_float_only = n - (int) n;
    int chr_count = 0;

    chr_count += my_put_nbr_retchrn((int) n);
    chr_count += my_putchar_wlength('.');
    if (n_float_only != 0) {
        if (n_float_only * 100.0 < 10)
            chr_count += my_putchar_wlength('0');
        chr_count += my_put_nbr_retchrn(n_float_only * 100.0);
    } else
        chr_count += my_putstr("00");
    return chr_count;
}
