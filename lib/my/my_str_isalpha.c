/*
** EPITECH PROJECT, 2024
** my_str_isalpha
** File description:
** Day 6, Task 12
*/

#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include "utils.h"

int is_alpha(char chr)
{
    if ((chr >= 'A') && (chr <= 'Z'))
        return TRUE;
    if ((chr >= 'a') && (chr <= 'z'))
        return TRUE;
    return FALSE;
}

int my_str_isalpha(const char *str)
{
    if (str == NULL)
        return FALSE;
    for (int i = 0; str[i] != '\0'; i++)
        if (is_alpha(str[i]) == FALSE)
            return FALSE;
    return TRUE;
}
