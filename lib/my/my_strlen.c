/*
** EPITECH PROJECT, 2024
** my_strlen
** File description:
** day 4, task 3
** my_strlen.c
*/

#include <stdio.h>
#include "my.h"
#include "utils.h"

int my_strlen(const char *str)
{
    int i = 0;

    if (str == NULL)
        return FUNC_FAILED;
    for (i = 0; str[i] != '\0'; i++);
    return i;
}
