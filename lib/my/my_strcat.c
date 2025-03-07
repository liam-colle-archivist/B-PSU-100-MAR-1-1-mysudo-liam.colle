/*
** EPITECH PROJECT, 2024
** my_strcat
** File description:
** Day 7, Task 2
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

char *my_strcat(char *dest, const char *src)
{
    int i = 0;
    int j = 0;

    if (dest == NULL || src == NULL)
        return NULL;
    for (i = 0; dest[i] != '\0'; i++);
    for (j = 0; src[j] != '\0'; j++)
        dest[i + j] = src[j];
    return dest;
}
