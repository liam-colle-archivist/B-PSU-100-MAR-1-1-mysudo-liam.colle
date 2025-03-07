/*
** EPITECH PROJECT, 2024
** my_strlowcase
** File description:
** Day 6, Task 9
*/

#include <stdio.h>
#include <unistd.h>
#include "my.h"

char *my_strlowcase(char *str)
{
    if (str == NULL)
        return NULL;
    for (int i = 0; str[i] != '\0'; i++)
        if ((str[i] >= 'A') && (str[i] <= 'Z'))
            str[i] = str[i] + 32;
    return str;
}
