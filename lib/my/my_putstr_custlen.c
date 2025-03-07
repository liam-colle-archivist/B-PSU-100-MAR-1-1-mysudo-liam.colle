/*
** EPITECH PROJECT, 2024
** my_putstr
** File description:
** day 4, task 2
** my_putstr.c
*/

#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include "utils.h"

static int print_w_max(const char *str, int len, int max)
{
    if (len < max) {
        if (write(STDOUT, str, sizeof(char) * len) == FUNC_FAILED)
            return FUNC_FAILED;
        return len;
    } else
        if (write(STDOUT, str, sizeof(char) * max) == FUNC_FAILED)
            return FUNC_FAILED;
    return max;
}

int my_putstr_custlen(const char *str, int max)
{
    int len = FUNC_FAILED;

    if (str == NULL)
        return FUNC_FAILED;
    len = my_strlen(str);
    if (len == FUNC_FAILED)
        return FUNC_FAILED;
    if (max == -1) {
        if (write(STDOUT, str, sizeof(char) * len) == FUNC_FAILED)
            return FUNC_FAILED;
    } else
        return print_w_max(str, len, max);
    return len;
}
