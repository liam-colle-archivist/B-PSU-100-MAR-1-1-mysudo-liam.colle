/*
** EPITECH PROJECT, 2024
** my_int_to_str
** File description:
** libmy
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

static int get_decimals_num(int number)
{
    int decimals = 0;

    if (number == 0)
        return 1;
    if (number < 0)
        number *= -1;
    for (; number > 0; decimals++) {
        number /= 10;
    }
    return decimals;
}

static void convert_num_to_str(int number, char *ret_str, int i)
{
    if (number < 0)
        number *= -1;
    if (number > 9)
        convert_num_to_str(number / 10, ret_str, i + 1);
    ret_str[i] = '0' + (number % 10);
}

char *my_int_to_str(int number)
{
    int decimals = get_decimals_num(number);
    int num_neg = number < 0 ? 1 : 0;
    char *ret_str = malloc(sizeof(char) * (decimals + num_neg + 1));

    if (ret_str == NULL)
        return NULL;
    convert_num_to_str(number, ret_str, 0);
    if (number < 0)
        ret_str[decimals] = '-';
    ret_str[decimals + num_neg] = '\0';
    ret_str = my_revstr(ret_str);
    return ret_str;
}
