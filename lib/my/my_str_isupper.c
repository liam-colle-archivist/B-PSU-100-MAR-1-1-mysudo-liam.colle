/*
** EPITECH PROJECT, 2024
** my_str_isupper
** File description:
** Day 6, Task 15
*/

#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include "utils.h"

int my_str_isupper(const char *str)
{
    if (str == NULL)
        return FALSE;
    for (int i = 0; str[i] != '\0'; i++)
        if ((str[i] < 'A') || (str[i] > 'Z'))
            return FALSE;
    return TRUE;
}
