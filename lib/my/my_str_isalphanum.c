/*
** EPITECH PROJECT, 2024
** my_str_isalphanum
** File description:
** Day 6, Task 12
*/

#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include "utils.h"

int is_alphanum(char chr)
{
    if ((chr >= 'A') && (chr <= 'Z'))
        return TRUE;
    if ((chr >= 'a') && (chr <= 'z'))
        return TRUE;
    if ((chr >= '0') && (chr <= '9'))
        return TRUE;
    return FALSE;
}

int my_str_isalphanum(const char *str)
{
    if (str == NULL)
        return FALSE;
    for (int i = 0; str[i] != '\0'; i++)
        if (is_alphanum(str[i]) == FALSE)
            return FALSE;
    return TRUE;
}
