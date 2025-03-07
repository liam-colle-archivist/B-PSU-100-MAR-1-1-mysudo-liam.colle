/*
** EPITECH PROJECT, 2024
** my_printf_gtruncate
** File description:
** my_printf
*/

#include <stdarg.h>
#include "my_printf.h"
#include "../my.h"

double my_gtruncate_round_up(double num, int precision)
{
    int prec_dec = my_compute_power_rec(10, precision);
    double num_prsd_double = (num - (int) num) * prec_dec;
    long long num_parsed = (long long) num_prsd_double;
    double result = 0;

    if ((num_prsd_double - (int) num_prsd_double) < 0.5) {
        result = num_parsed / (double) prec_dec;
        result += (int) num;
    } else {
        result = (num_parsed + 1) / (double) prec_dec;
        result += (int) num;
    }
    return result;
}

int my_print_gtrucate(double num, int precision, char chr)
{
    double result = my_gtruncate_round_up(num, precision);
    int dec_decimals = my_get_nbr_decimals((int) num, 0);
    int float_zero_decimals = my_count_pre_zeros(num, precision);

    if (dec_decimals > 6 || float_zero_decimals > 3 || result == 0) {
        if (chr == 'G')
            return my_printf_sci_maj(result, precision, NO_DOT);
        return my_printf_sci(result, precision, NO_DOT);
    }
    return my_print_double(result, precision, NO_DOT);
}

int my_printf_gtrucate(char *str, va_list args, int *i)
{
    int precision = 6;
    int precision_mode_zeros = check_precision_mode(str, *i);
    int precision_length = check_precision_length(str, *i);
    int chr_count = 0;

    if (precision_mode_zeros && precision_length > 1)
        precision = precision_length;
    else
        precision = check_precision(str, *i);
    chr_count += my_print_gtrucate(va_arg(args, double), precision, str[*i]);
    return chr_count;
}
