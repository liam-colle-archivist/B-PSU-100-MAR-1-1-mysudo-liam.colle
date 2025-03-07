/*
** EPITECH PROJECT, 2024
** hexadecimal_ulong
** File description:
** my_printf
*/

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "../my.h"
#include "my_printf.h"

int hexadecimal_ulong(unsigned long decimal)
{
    if (decimal == 0)
        return my_putchar_wlength('0');
    return hexadecimal_ulong_worker(decimal, 0);
}

int hexadecimal_ulong_worker(unsigned long decimal, int chr_count)
{
    char *str = "0123456789abcdef";
    unsigned long result = 0;

    if (decimal >= 1) {
        chr_count += hexadecimal_ulong_worker(decimal / 16, chr_count);
        chr_count += my_putchar_wlength(str[decimal % 16]);
        decimal = result;
    }
    return chr_count;
}
