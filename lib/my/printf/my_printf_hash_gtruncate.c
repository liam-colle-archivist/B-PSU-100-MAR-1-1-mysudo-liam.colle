/*
** EPITECH PROJECT, 2024
** my_printf_hash_gtruncate
** File description:
** my_printf
*/

#include <stdarg.h>
#include "my_printf.h"
#include "../my.h"

int my_print_hash_gtrucate(double num, int precision, char chr)
{
    double result = my_gtruncate_round_up(num, precision);
    int dec_decimals = my_get_nbr_decimals((int) num, 0);
    int float_zero_decimals = my_count_pre_zeros(num, precision);

    if (dec_decimals > 6 || float_zero_decimals > 3 || result == 0) {
        if (chr == 'G')
            return my_printf_sci_maj(result, precision, FORCE_DOT);
        return my_printf_sci(result, precision, FORCE_DOT);
    }
    return my_print_double(result, precision, FORCE_DOT);
}

int my_printf_hash_gtrucate(char *str, va_list args, int *i)
{
    int precision = 6;
    int precision_mode_zeros = check_precision_mode(str, *i);
    int precision_length = check_precision_length(str, *i);
    int chr_count = 0;

    if (precision_mode_zeros && precision_length > 1)
        precision = precision_length;
    else
        precision = check_precision(str, *i);
    chr_count += my_print_hash_gtrucate(va_arg(args, double), precision,
        str[*i]);
    if (precision != 6)
        *i += check_precision_length(str, *i) - 1;
    if (precision_mode_zeros)
        *i -= check_precision_length(str, *i) - 1;
    return chr_count;
}
