/*
** EPITECH PROJECT, 2024
** my_strlen
** File description:
** day 4, task 3
** my_strlen.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "utils.h"

int my_tabfree(void **tab)
{
    if (tab == NULL)
        return FUNC_FAILED;
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
    return FUNC_SUCCESS;
}
