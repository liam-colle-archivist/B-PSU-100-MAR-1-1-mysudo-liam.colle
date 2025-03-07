/*
** EPITECH PROJECT, 2024
** my_str_isprintable
** File description:
** Day 6, Task 15
*/

#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include "utils.h"

int is_printable(char chr)
{
    if (chr < 32 || chr > 126)
        return FALSE;
    return TRUE;
}

int is_printable_nospace(char chr)
{
    if (!(chr < 32 || chr > 126) && chr != ' ')
        return TRUE;
    return FALSE;
}

int my_str_isprintable(const char *str)
{
    if (str == NULL)
        return FALSE;
    for (int i = 0; str[i] != '\0'; i++)
        if (is_printable(str[i]))
            return FALSE;
    return TRUE;
}
