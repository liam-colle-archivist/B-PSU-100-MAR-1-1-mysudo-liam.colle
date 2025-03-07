/*
** EPITECH PROJECT, 2024
** my_check_precision
** File description:
** my_printf
*/

#include <stddef.h>
#include <stdlib.h>
#include "../my.h"

int check_numeric(char chr)
{
    if (chr >= '0' && chr <= '9')
        return 1;
    return 0;
}

int check_n_flag_start(char chr)
{
    if (chr != '%' && chr != '.')
        return 1;
    return 0;
}

int check_precision_length(char *str, int i)
{
    int p_len = 0;

    for (int j = i - 1; str[j] != '%' && str[j] != '.'; j--)
        if (check_numeric(str[j]))
            p_len++;
    return p_len;
}

int check_precision_mode(char *str, int i)
{
    int p_len = 0;

    for (int j = i - 1; str[j] != '%' && str[j] != '.'; j--) {
        if (str[j] == '0')
            p_len++;
        if (check_numeric(str[j]) && str[j] != '0')
            return 0;
    }
    return (p_len > 0) ? 1 : 0;
}

int check_precision(char *str, int i)
{
    char *num_str = NULL;
    int p_len = check_precision_length(str, i);
    int precision = 6;
    int k = p_len - 1;

    if (p_len <= 0)
        return precision;
    num_str = malloc(sizeof(char) * (p_len + 1));
    for (int j = i - 1; check_n_flag_start(str[j]) && k >= 0; j--)
        if (check_numeric(str[j])) {
            num_str[k] = str[j];
            k--;
        }
    num_str[p_len] = '\0';
    precision = my_getnbr(num_str);
    free(num_str);
    return precision;
}
