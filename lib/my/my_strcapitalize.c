/*
** EPITECH PROJECT, 2024
** my_strcapitalize
** File description:
** Day 6, Task 10
*/

#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include "utils.h"

static int can_be_capitalized(char character, int ready)
{
    if ((character >= 'a') && (character <= 'z'))
        if (ready == 1)
            return TRUE;
    return FALSE;
}

static int can_be_ready(char character)
{
    char *valid = "-+ ";
    int size = 3;

    for (int i = 0; i < size; i++)
        if (character == valid[i])
            return TRUE;
    return FALSE;
}

static int can_be_decapitalized(char character, int *ready)
{
    if ((character >= 'A') && (character <= 'Z')) {
        if (*ready == 0)
            return TRUE;
        *ready = TRUE;
    }
    if ((character >= '0') && (character <= '9'))
        *ready = FALSE;
    return FALSE;
}

char *my_strcapitalize(char *str)
{
    int ready = TRUE;

    if (str == NULL)
        return NULL;
    for (int i = 0; str[i] != '\0'; i++) {
        if (can_be_decapitalized(str[i], &ready)) {
            str[i] = str[i] + 32;
            ready = FALSE;
            continue;
        }
        if (can_be_capitalized(str[i], ready)) {
            str[i] = str[i] - 32;
            ready = FALSE;
        }
        if (can_be_ready(str[i]))
            ready = TRUE;
    }
    return str;
}
