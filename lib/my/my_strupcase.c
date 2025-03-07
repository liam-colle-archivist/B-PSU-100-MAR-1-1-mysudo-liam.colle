/*
** EPITECH PROJECT, 2024
** my_strupcase
** File description:
** Day 6, Task 8
*/

#include <stdio.h>
#include <unistd.h>
#include "my.h"

char *my_strupcase(char *str)
{
    if (str == NULL)
        return NULL;
    for (int i = 0; str[i] != '\0'; i++)
        if ((str[i] >= 'a') && (str[i] <= 'z'))
            str[i] = str[i] - 32;
    return str;
}
