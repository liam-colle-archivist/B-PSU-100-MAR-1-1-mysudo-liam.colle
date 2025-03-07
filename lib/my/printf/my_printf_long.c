/*
** EPITECH PROJECT, 2024
** my_printf_long
** File description:
** my_printf
*/

#include <stdarg.h>
#include "../my.h"
#include "my_printf.h"

int my_print_long_long(char *str, va_list args, int *i)
{
    switch (str[*i + 2]) {
        case 'i':
        case 'd':
            *i += 2;
            return my_put_long_long_rc(va_arg(args, long long));
        case 'f':
            *i += 2;
            return my_printf_long_double(str, args, i);
        case 'o':
            *i += 2;
            return octal_ll(va_arg(args, long long));
        case 'u':
            *i += 2;
            return my_put_llu_rc(va_arg(args, unsigned long long));
        default:
            return my_print_long_long_2(str, args, i);
    }
}

int my_print_long_long_2(char *str, va_list args, int *i)
{
    switch (str[*i + 2]) {
        case 'x':
            *i += 2;
            return hexadecimal_ll_min(va_arg(args, long long));
        case 'X':
            *i += 2;
            return hexadecimal_ll(va_arg(args, long long));
        default:
            *i += 1;
            return my_put_long_long_rc(va_arg(args, long long));
    }
}

int my_printf_long(char *str, va_list args, int *i)
{
    switch (str[*i + 2]) {
        case 'l':
            *i += 1;
            return my_print_long_long(str, args, i);
        case 'i':
        case 'd':
            *i += 2;
            return my_put_long_retchrn(va_arg(args, long));
        case 'C':
        case 'c':
            *i += 2;
            return my_putchar_wlength(va_arg(args, __WINT_TYPE__));
        case 'f':
            *i += 2;
            return my_printf_long_double(str, args, i);
        default:
            return my_printf_long_2(str, args, i);
    }
}

int my_printf_long_2(char *str, va_list args, int *i)
{
    switch (str[*i + 2]) {
        case 'o':
            *i += 2;
            return octal_long(va_arg(args, long));
        case 'x':
            *i += 2;
            return hexadecimal_min_long(va_arg(args, long));
        case 'X':
            *i += 2;
            return hexadecimal_long(va_arg(args, long));
        default:
            *i += 1;
            return 0;
    }
}
