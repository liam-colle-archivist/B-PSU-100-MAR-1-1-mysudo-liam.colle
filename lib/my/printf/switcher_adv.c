/*
** EPITECH PROJECT, 2024
** switcher (Advanced)
** File description:
** my_printf
*/

#include "my_printf.h"
#include "switcher.h"

int my_switch_is_numeral(char *str, va_list args, int *i, int *c_count)
{
    if (check_numeric(str[*i + 1])) {
        *i += 1;
        return my_printf_printarg_1(str, args, i, c_count);
    }
    return 0;
}

int my_switch_is_numeral_hashtag(char *str, va_list args, int *i)
{
    if (check_numeric(str[*i + 1])) {
        *i += 1;
        return my_hash_switcher(str, args, i);
    }
    *i += 1;
    return 0;
}
