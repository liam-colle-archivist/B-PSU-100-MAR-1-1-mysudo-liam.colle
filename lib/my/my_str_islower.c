/*
** EPITECH PROJECT, 2024
** my_str_islower
** File description:
** Day 6, Task 14
*/

#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include "utils.h"

int my_str_islower(const char *str)
{
    if (str == NULL)
        return FALSE;
    for (int i = 0; str[i] != '\0'; i++)
        if ((str[i] < 'a') || (str[i] > 'z'))
            return FALSE;
    return TRUE;
}
