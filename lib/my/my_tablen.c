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

int my_tablen(const void **tab)
{
    int i = 0;

    if (tab == NULL)
        return FUNC_FAILED;
    for (i = 0; tab[i] != NULL; i++);
    return i;
}
