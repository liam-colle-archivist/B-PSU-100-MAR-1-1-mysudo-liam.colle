/*
** EPITECH PROJECT, 2024
** my_printf_sizet
** File description:
** my_printf
*/

#include <stdarg.h>
#include "../my.h"
#include "my_printf.h"

int my_printf_sizet(char *str, va_list args, int *i)
{
    switch (str[*i + 2]) {
        case 'i':
        case 'd':
            *i += 2;
            return my_put_long_retchrn(va_arg(args, __SIZE_TYPE__));
        case 'c':
        case 'C':
            *i += 2;
            return my_putchar_wlength(va_arg(args, __SIZE_TYPE__));
        case 'o':
            *i += 2;
            return octal(va_arg(args, __SIZE_TYPE__));
        case 'u':
            *i += 2;
            return my_put_nbr_retchrn((unsigned int) va_arg(args, int));
        default:
            return my_printf_sizet_2(str, args, i);
    }
}

int my_printf_sizet_2(char *str, va_list args, int *i)
{
    switch (str[*i + 2]) {
        case 'x':
            *i += 2;
            return hexadecimalmin(va_arg(args, __SIZE_TYPE__));
        case 'X':
            *i += 2;
            return hexadecimal(va_arg(args, __SIZE_TYPE__));
        default:
            return 0;
    }
}
