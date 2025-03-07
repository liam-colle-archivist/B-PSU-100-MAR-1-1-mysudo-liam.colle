/*
** EPITECH PROJECT, 2024
** my_print_double
** File description:
** my_print_double.c
*/

#include "my.h"

int my_count_pre_zeros(double n, int precision)
{
    int count = 0;

    for (int i = 0; (int) (n * 10) == 0 && i < precision; i++) {
        count++;
        n *= 10;
    }
    return count;
}

int my_print_zeros(int zeros)
{
    int chr_count = 0;

    for (int i = 0; i < zeros; i++)
        chr_count += my_putchar_wlength('0');
    return chr_count;
}

int my_print_double(double n, int precision, int force_dot)
{
    double n_float_only = n - (int) n;
    double prec = my_power_double_rec(10.0, precision);
    int chr_count = 0;
    int pre_zero_count = my_count_pre_zeros(n, precision);

    chr_count += my_put_nbr_retchrn((int) n);
    if (precision > 0 || force_dot)
        chr_count += my_putchar_wlength('.');
    if (n > 0.0 && n < 1.0)
        chr_count += my_print_zeros(pre_zero_count);
    if (precision > 0) {
        if (n == 0)
            chr_count += my_print_zeros(precision - 1);
        chr_count += my_put_nbr_retchrn(n_float_only * prec);
    }
    return chr_count;
}
