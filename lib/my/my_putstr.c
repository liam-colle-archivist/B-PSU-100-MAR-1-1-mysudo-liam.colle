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

int my_putstr(const char *str)
{
    int len = FUNC_FAILED;

    if (str == NULL)
        return FUNC_FAILED;
    len = my_strlen(str);
    if (len == FUNC_FAILED)
        return FUNC_FAILED;
    if (write(STDOUT, str, sizeof(char) * len) == FUNC_FAILED)
        return FUNC_FAILED;
    return len;
}

int my_putstr_fd(const char *str, int fd)
{
    int len = FUNC_FAILED;

    if (str == NULL || fd < 0)
        return FUNC_FAILED;
    len = my_strlen(str);
    if (len == FUNC_FAILED)
        return FUNC_FAILED;
    if (write(fd, str, sizeof(char) * len) == FUNC_FAILED)
        return FUNC_FAILED;
    return len;
}
