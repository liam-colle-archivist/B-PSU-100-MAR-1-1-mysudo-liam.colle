/*
** EPITECH PROJECT, 2024
** my_printf_sci
** File description:
** my_printf
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my_printf.h"
#include "../my.h"

int my_printf_sci_global(double nb, char *str, int *i)
{
    int precision = 6;
    int precision_mode_zeros = check_precision_mode(str, *i);
    int precision_length = check_precision_length(str, *i);
    int chr_count = 0;

    if (precision_mode_zeros && precision_length > 1)
        precision = precision_length;
    else
        precision = check_precision(str, *i);
    if (str[*i] == 'e')
        chr_count += my_printf_sci(nb, precision, NO_DOT);
    else
        chr_count += my_printf_sci_maj(nb, precision, NO_DOT);
    return chr_count;
}

int my_printf_sci(double nb, int precision, int force_dot)
{
    int i = 0;
    int chr_count = 0;
    int side = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    side = my_printf_sci_worker(&nb, &i);
    chr_count += my_print_double(nb, precision, force_dot);
    chr_count += my_putchar_wlength('e');
    chr_count += my_putchar_wlength(side);
    chr_count += my_printf_sci_i_worker(&i);
    chr_count += my_put_nbr_retchrn(i);
    return chr_count;
}

int my_printf_sci_maj(double nb, int precision, int force_dot)
{
    int i = 0;
    int chr_count = 0;
    int side = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    side = my_printf_sci_worker(&nb, &i);
    chr_count += my_print_double(nb, precision, force_dot);
    chr_count += my_putchar_wlength('E');
    chr_count += my_putchar_wlength(side);
    chr_count += my_printf_sci_i_worker(&i);
    chr_count += my_put_nbr_retchrn(i);
    return chr_count;
}

char my_printf_sci_worker(double *nb, int *i)
{
    char side = '+';

    if (*nb == 0)
        return side;
    if (*nb >= 1)
        for (; *nb > 10; *nb = *nb / 10)
            *i += 1;
    else {
        side = '-';
        for (; *nb < 1; *nb = *nb * 10)
            *i += 1;
    }
    return side;
}

int my_printf_sci_i_worker(int *i)
{
    if (*i < 10) {
        my_putchar('0');
        return 1;
    }
    return 0;
}
