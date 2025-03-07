/*
** EPITECH PROJECT, 2024
** my_strcpy
** File description:
** Day 6, Task 2
*/

#include <stdio.h>
#include "my.h"

char *my_strncpy(char *dest, const char *src, int n)
{
    int i = 0;

    if (dest == NULL || src == NULL || n <= 0)
        return NULL;
    for (i = 0; src[i] != '\0' && i < n; i++)
        dest[i] = src[i];
    if (src[i] == '\0')
        dest[i] = '\0';
    return dest;
}
