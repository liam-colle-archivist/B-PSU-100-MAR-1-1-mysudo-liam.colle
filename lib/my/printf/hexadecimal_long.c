/*
** EPITECH PROJECT, 2024
** hexadecimal_long
** File description:
** my_printf
*/

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "../my.h"
#include "my_printf.h"

int hexadecimal_long(long decimal)
{
    if (decimal == 0)
        return my_putchar_wlength('0');
    return hexadecimal_long_worker(decimal, 0);
}

int hexadecimal_long_worker(long decimal, int chr_count)
{
    char *str = "0123456789ABCDEF";
    long result = 0;

    if (decimal < 0) {
        chr_count += my_putchar_wlength('-');
        decimal = -decimal;
    }
    if (decimal >= 1) {
        chr_count += hexadecimal_long_worker(decimal / 16, chr_count);
        chr_count += my_putchar_wlength(str[decimal % 16]);
        decimal = result;
    }
    return chr_count;
}

int hexadecimal_min_long(long decimal)
{
    if (decimal == 0)
        return my_putchar_wlength('0');
    return hexadecimal_min_long_worker(decimal, 0);
}

int hexadecimal_min_long_worker(long decimal, int chr_count)
{
    char *str = "0123456789abcdef";
    long result = 0;

    if (decimal < 0) {
        chr_count += my_putchar_wlength('-');
        decimal = -decimal;
    }
    if (decimal >= 1) {
        chr_count += hexadecimal_min_long_worker(decimal / 16, chr_count);
        chr_count += my_putchar_wlength(str[decimal % 16]);
        decimal = result;
    }
    return chr_count;
}
