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

static int compare_str(char *str, const char *to_find, int i)
{
    if (str == NULL)
        return FUNC_FAILED;
    for (int j = 0; to_find[j] != '\0'; j++) {
        if (str[i + j] == '\0')
            return FUNC_FAILED;
        if (str[i + j] != to_find[j])
            return FUNC_FAILED;
    }
    return i;
}

char *my_strstr(char *str, const char *to_find)
{
    int compare_res = FUNC_FAILED;

    if (str == NULL)
        return NULL;
    if (to_find[0] == '\0')
        return str;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == to_find[0])
            compare_res = compare_str(str, to_find, i);
        if (compare_res > FUNC_FAILED)
            return &str[i];
    }
    return NULL;
}
