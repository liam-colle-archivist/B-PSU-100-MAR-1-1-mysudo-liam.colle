/*
** EPITECH PROJECT, 2024
** my_strcpy
** File description:
** Day 6, Task 1
*/

#include <stdio.h>
#include "my.h"
#include "utils.h"

char *my_strcpy(char *dest, const char *src)
{
    int i = 0;

    if (dest == NULL || src == NULL)
        return NULL;
    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}
