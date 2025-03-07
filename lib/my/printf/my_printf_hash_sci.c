/*
** EPITECH PROJECT, 2024
** my_printf_hashsci
** File description:
** my_printf
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my_printf.h"
#include "../my.h"

int my_printf_hash_sci_global(double nb, char *str, int *i)
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
        chr_count += my_printf_sci(nb, precision, FORCE_DOT);
    else
        chr_count += my_printf_sci_maj(nb, precision, FORCE_DOT);
    return chr_count;
}
