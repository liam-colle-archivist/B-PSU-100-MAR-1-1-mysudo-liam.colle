/*
** EPITECH PROJECT, 2024
** hash_switcher
** File description:
** my_printf
*/

#include <stdarg.h>
#include "my_printf.h"
#include "switcher.h"
#include "../my.h"

int my_hash_switcher(char *str, va_list args, int *i)
{
    switch (str[*i + 1]) {
        case 'o':
            *i += 1;
            return octal(va_arg(args, int));
        case 'x':
            *i += 1;
            my_putstr("0x");
            return hexadecimalmin(va_arg(args, int)) + 2;
        case 'X':
            *i += 1;
            my_putstr("0X");
            return hexadecimal(va_arg(args, int)) + 2;
        case 'E':
        case 'e':
            *i += 1;
            return my_printf_hash_sci_global(va_arg(args, double), str, i);
        default:
            return my_hash_switcher_2(str, args, i);
    }
}

int my_hash_switcher_2(char *str, va_list args, int *i)
{
    switch (str[*i + 1]) {
        case 'g':
        case 'G':
            *i += 1;
            return my_printf_hash_gtrucate(str, args, i);
        case 'f':
            *i += 1;
            return my_printf_hash_double(str, args, i);
        case '.':
            *i += 1;
            return my_hash_switcher(str, args, i);
        default:
            return my_switch_is_numeral_hashtag(str, args, i);
    }
}
