/*
** EPITECH PROJECT, 2024
** my_getnbr
** File description:
** day 4, task 5
** my_getnbr.c
*/

#include <stdio.h>
#include <limits.h>
#include "my.h"
#include "utils.h"

static int get_symbol(const char *str)
{
    int symbol = 1;

    if (str == NULL)
        return FUNC_FAILED;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '+')
            symbol = 1;
        if (str[i] == '-')
            symbol = -1;
    }
    return symbol;
}

static int is_valid(const char *str, int i)
{
    if (str == NULL)
        return FALSE;
    if ((str[i] == '-') || (str[i] == '+'))
        return 1;
    if ((str[i] >= '0') && (str[i] <= '9'))
        return TRUE;
    return FALSE;
}

static int calc_wo_overflow(const char *str, int i, int len, long *result)
{
    long future_res = 0;

    if (str == NULL)
        return TRUE;
    future_res = (str[i] - '0') * my_pow(10, len - i - 1);
    future_res += *result;
    if ((future_res - INT_MAX <= 0)) {
        *result += (str[i] - '0') * my_pow(10, len - i - 1);
        return FALSE;
    }
    return TRUE;
}

int my_getnbr(const char *str)
{
    long result = 0;
    int len = 0;
    int symbol = get_symbol(str);
    int fail = FALSE;

    if (str == NULL || symbol == FUNC_FAILED)
        return FUNC_FAILED;
    for (len = 0; str[len] != '\0'; len++)
        if (is_valid(str, len) == FALSE)
            break;
    for (int i = 0; i < len; i++) {
        if (is_valid(str, i) == FALSE)
            break;
        if ((str[i] >= '0') && (str[i] <= '9'))
            fail = calc_wo_overflow(str, i, len, &result);
        if (fail == TRUE)
            return 0;
    }
    return (int) result * symbol;
}
