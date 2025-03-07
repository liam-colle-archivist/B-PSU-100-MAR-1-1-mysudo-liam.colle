/*
** EPITECH PROJECT, 2024
** my_printf_ptrdiff
** File description:
** my_printf
*/

#include <stdarg.h>
#include "../my.h"
#include "my_printf.h"

int my_printf_ptrdiff(char *str, va_list args, int *i)
{
    switch (str[*i + 2]) {
        case 'i':
        case 'd':
            *i += 2;
            return my_put_long_retchrn(va_arg(args, __PTRDIFF_TYPE__));
        case 'C':
        case 'c':
            *i += 2;
            return my_putchar_wlength(va_arg(args, __PTRDIFF_TYPE__));
        case 'o':
            *i += 2;
            return octal(va_arg(args, __PTRDIFF_TYPE__));
        default:
            return my_printf_long_2(str, args, i);
    }
}

int my_printf_ptrdiff_1(char *str, va_list args, int *i)
{
    switch (str[*i + 2]) {
        case 'x':
            *i += 2;
            return hexadecimal_min_long(va_arg(args, __PTRDIFF_TYPE__));
        case 'X':
            *i += 2;
            return hexadecimal_long(va_arg(args, __PTRDIFF_TYPE__));
        default:
            *i += 1;
            return 0;
    }
}
