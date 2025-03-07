/*
** EPITECH PROJECT, 2024
** my_printf_str
** File description:
** my_printf
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my_printf.h"
#include "../my.h"

int check_precision_str(char *str, int i)
{
    char *num_str = NULL;
    int p_len = check_precision_length(str, i);
    int precision = -1;
    int k = p_len - 1;

    if (p_len <= 0)
        return precision;
    num_str = malloc(sizeof(char) * (p_len + 1));
    for (int j = i - 1; check_n_flag_start(str[j]) && k >= 0; j--) {
        if (check_numeric(str[j])) {
            num_str[k] = str[j];
            k--;
        }
    }
    num_str[p_len] = '\0';
    precision = my_getnbr(num_str);
    free(num_str);
    return precision;
}

int my_printf_str(char *str, va_list args, int *i)
{
    int precision = -1;
    int precision_mode_zeros = check_precision_mode(str, *i);
    int precision_length = check_precision_length(str, *i);
    int chr_count = 0;

    if (precision_mode_zeros && precision_length > 1)
        precision = precision_length;
    else
        precision = check_precision_str(str, *i);
    chr_count += my_putstr_custlen(va_arg(args, char *), precision);
    return chr_count;
}
