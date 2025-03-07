/*
** EPITECH PROJECT, 2024
** my_strstr
** File description:
** Day 6, Task 5
*/

#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include "utils.h"

int my_strncmp(const char *s1, const char *s2, int n)
{
    int compare_res = 0;

    if (s1 == NULL || s2 == NULL || n <= 0)
        return FUNC_FAILED;
    for (int i = 0; (s1[i] != '\0') && i < n; i++)
        if (s1[i] != s2[i]) {
            compare_res = s1[i] - s2[i];
            break;
        }
    return compare_res;
}
