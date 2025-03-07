/*
** EPITECH PROJECT, 2024
** switcher
** File description:
** my_printf
*/

#include <stdarg.h>
#include "switcher.h"
#include "my_printf.h"
#include "../my.h"

int my_printf_printarg_1(char *str, va_list args, int *i, int *chr_count)
{
    switch (str[*i + 1]) {
        case 'd':
        case 'i':
            *i += 1;
            return my_put_nbr_retchrn(va_arg(args, int));
        case 'C':
        case 'c':
            *i += 1;
            return my_putchar_wlength(va_arg(args, int));
        case 's':
            *i += 1;
            return my_printf_str(str, args, i);
        case '%':
            *i += 1;
            return my_putchar_wlength('%');
        case 'l':
            return my_printf_long(str, args, i);
        default:
            return my_printf_printarg_2(str, args, i, chr_count);
    }
}

int my_printf_printarg_2(char *str, va_list args, int *i, int *chr_count)
{
    switch (str[*i + 1]) {
        case 'e':
        case 'E':
            *i += 1;
            return my_printf_sci_global(va_arg(args, double), str, i);
        case 'g':
        case 'G':
            *i += 1;
            return my_printf_gtrucate(str, args, i);
        case 'f':
            *i += 1;
            return my_printf_double(str, args, i);
        case 'h':
            return my_printf_short(str, args, i);
        default:
            return my_printf_printarg_3(str, args, i, chr_count);
    }
}

int my_printf_printarg_3(char *str, va_list args, int *i, int *chr_count)
{
    switch (str[*i + 1]) {
        case 'o':
            *i += 1;
            return octal(va_arg(args, int));
        case 'u':
            *i += 1;
            return my_put_nbr_un_retchrn(va_arg(args, unsigned int));
        case 'x':
            *i += 1;
            return hexadecimalmin(va_arg(args, int));
        case 'X':
            *i += 1;
            return hexadecimal(va_arg(args, int));
        case '#':
            *i += 1;
            return my_hash_switcher(str, args, i);
        default:
            return my_printf_printarg_4(str, args, i, chr_count);
    }
}

int my_printf_printarg_4(char *str, va_list args, int *i, int *chr_count)
{
    switch (str[*i + 1]) {
        case 'p':
            *i += 1;
            my_putstr("0x");
            return hexadecimal_ulong(va_arg(args, unsigned long)) + 2;
        case 't':
            return my_printf_ptrdiff(str, args, i);
        case 'z':
            return my_printf_sizet(str, args, i);
        case 'n':
            *i += 1;
            return my_put_nbr_retchrn(*chr_count);
        case '.':
            *i += 1;
            return my_printf_printarg_1(str, args, i, chr_count);
        default:
            return my_switch_is_numeral(str, args, i, chr_count);
    }
}
