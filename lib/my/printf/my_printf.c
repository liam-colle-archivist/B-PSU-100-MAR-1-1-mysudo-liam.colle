/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** my_printf
*/

#include <stdarg.h>
#include "switcher.h"
#include "../my.h"

int my_printf(char *str, ...)
{
    va_list args;
    int len = my_strlen(str);
    int chr_count = 0;

    if (len <= 0)
        return 0;
    va_start(args, str);
    for (int i = 0; i <= len && str[i] != '\0'; i++) {
        if (str[i] == '%' && str[i + 1] != '\0')
            chr_count += my_printf_printarg_1(str, args, &i, &chr_count);
        else
            chr_count += my_putchar_wlength(str[i]);
    }
    va_end(args);
    return chr_count;
}
