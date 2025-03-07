/*
** EPITECH PROJECT, 2024
** my_printf_long
** File description:
** my_printf
*/

#include <stdarg.h>
#include "../my.h"
#include "my_printf.h"

int my_printf_short(char *str, va_list args, int *i)
{
    switch (str[*i + 2]) {
        case 'i':
        case 'd':
            *i += 2;
            return my_put_short_retchrn((short) va_arg(args, int));
        case 'u':
            *i += 2;
            return my_put_short_u_retchrn((unsigned short) va_arg(args, int));
        case 'C':
        case 'c':
            *i += 2;
            return my_putchar_wlength(va_arg(args, __WINT_TYPE__));
        default:
            *i += 1;
            return 0;
    }
}
