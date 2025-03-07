/*
** EPITECH PROJECT, 2024
** hexadecimal
** File description:
** hexadecimal
*/

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "../my.h"
#include "my_printf.h"

int hexadecimal(int decimal)
{
    if (decimal == 0)
        return my_putchar_wlength('0');
    return hexadecimal_worker(decimal, 0);
}

int hexadecimal_worker(int decimal, int chr_count)
{
    char *str = "0123456789ABCDEF";
    int result = 0;

    if (decimal < 0) {
        chr_count += my_putchar_wlength('-');
        decimal = -decimal;
    }
    if (decimal >= 1) {
        chr_count += hexadecimal_worker(decimal / 16, chr_count);
        chr_count += my_putchar_wlength(str[decimal % 16]);
        decimal = result;
    }
    return chr_count;
}

int hexadecimalmin(int decimal)
{
    if (decimal == 0)
        return my_putchar_wlength('0');
    return hexadecimalmin_worker(decimal, 0);
}

int hexadecimalmin_worker(int decimal, int chr_count)
{
    char *str = "0123456789abcdef";
    int result = 0;

    if (decimal < 0) {
        chr_count += my_putchar_wlength('-');
        decimal = -decimal;
    }
    if (decimal >= 1) {
        chr_count += hexadecimalmin_worker(decimal / 16, chr_count);
        chr_count += my_putchar_wlength(str[decimal % 16]);
        decimal = result;
    }
    return chr_count;
}
