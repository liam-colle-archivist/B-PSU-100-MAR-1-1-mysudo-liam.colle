/*
** EPITECH PROJECT, 2024
** my_printf_double
** File description:
** my_printf
*/

#include <stdarg.h>
#include "my_printf.h"
#include "../my.h"

int my_printf_long_double(char *str, va_list args, int *i)
{
    int precision = 6;
    int precision_mode_zeros = check_precision_mode(str, *i);
    int chr_count = 0;

    if (precision_mode_zeros)
        precision = check_precision_length(str, *i);
    else
        precision = check_precision(str, *i);
    chr_count += my_print_long_double(va_arg(args, long double), precision);
    return chr_count;
}
