/*
** EPITECH PROJECT, 2024
** hexadecimal_ll
** File description:
** my_printf
*/

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "../my.h"
#include "my_printf.h"

int hexadecimal_ll_min(long decimal)
{
    if (decimal == 0)
        return my_putchar_wlength('0');
    return hexadecimal_ll_min_worker(decimal, 0);
}

int hexadecimal_ll_min_worker(long decimal, int chr_count)
{
    char *str = "0123456789abcdef";
    long result = 0;

    if (decimal < 0) {
        chr_count += my_putchar_wlength('-');
        decimal = -decimal;
    }
    if (decimal >= 1) {
        chr_count += hexadecimal_ll_min_worker(decimal / 16, chr_count);
        chr_count += my_putchar_wlength(str[decimal % 16]);
        decimal = result;
    }
    return chr_count;
}

int hexadecimal_ll(long decimal)
{
    if (decimal == 0)
        return my_putchar_wlength('0');
    return hexadecimal_ll_worker(decimal, 0);
}

int hexadecimal_ll_worker(long decimal, int chr_count)
{
    char *str = "0123456789ABCDEF";
    long result = 0;

    if (decimal < 0) {
        chr_count += my_putchar_wlength('-');
        decimal = -decimal;
    }
    if (decimal >= 1) {
        chr_count += hexadecimal_ll_worker(decimal / 16, chr_count);
        chr_count += my_putchar_wlength(str[decimal % 16]);
        decimal = result;
    }
    return chr_count;
}
