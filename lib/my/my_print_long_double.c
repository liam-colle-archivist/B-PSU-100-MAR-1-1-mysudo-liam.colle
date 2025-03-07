/*
** EPITECH PROJECT, 2024
** my_print_long_double
** File description:
** my_print_long_double.c
*/

#include "my.h"

int my_count_pre_zeros_double(long double n, int precision)
{
    int count = 0;

    for (int i = 0; (int) (n * 10) == 0 && i < precision; i++) {
        count++;
        n *= 10;
    }
    return count;
}

int my_print_long_double(long double n, int precision)
{
    long double n_float_only = n - (long) n;
    double prec = my_power_double_rec(10.0, precision);
    int chr_count = 0;
    int pre_zero_count = my_count_pre_zeros_double(n, precision);

    chr_count += my_put_long_retchrn((long) n);
    chr_count += my_putchar_wlength('.');
    if (n_float_only != 0) {
        if (n > 0.0 && n < 1.0)
            chr_count += my_print_zeros(pre_zero_count);
        chr_count += my_put_long_retchrn(n_float_only * prec);
    }
    return chr_count;
}
