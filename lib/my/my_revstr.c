/*
** EPITECH PROJECT, 2024
** my_revstr
** File description:
** Day 6, Task 3
*/

#include <stdio.h>
#include "my.h"

char *my_revstr(char *str)
{
    int len = 0;
    char swap = 0;

    if (str == NULL)
        return NULL;
    len = my_strlen(str);
    for (int i = 0; i <= ((len - 1) / 2); i++) {
        swap = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = swap;
    }
    return str;
}
