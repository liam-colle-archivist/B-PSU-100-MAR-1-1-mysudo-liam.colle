/*
** EPITECH PROJECT, 2024
** my_strmatch
** File description:
** Day 6, Task 5
*/

#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include "utils.h"

int my_strmatch(const char *s1, const char *s2)
{
    int len_s1 = FUNC_FAILED;
    int len_s2 = FUNC_FAILED;

    if (s1 == NULL || s2 == NULL)
        return FUNC_FAILED;
    len_s1 = my_strlen(s1);
    len_s2 = my_strlen(s2);
    if (len_s1 < 0 || len_s2 < 0)
        return FUNC_FAILED;
    if (len_s1 != len_s2)
        return FUNC_FAILED;
    for (int i = 0; s1[i] != '\0'; i++)
        if (s1[i] != s2[i])
            return FALSE;
    return TRUE;
}
