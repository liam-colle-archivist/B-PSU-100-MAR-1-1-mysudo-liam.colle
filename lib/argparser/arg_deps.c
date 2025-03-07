/*
** EPITECH PROJECT, 2024
** arg_deps
** File description:
** argparser
*/

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int argparser_strlen(const char *str)
{
    int i = 0;

    if (str == NULL)
        return FUNC_FAILED;
    for (i = 0; str[i] != '\0'; i++);
    return i;
}

char *argparser_strdup(const char *src)
{
    int i = 0;
    int len = FUNC_FAILED;
    char *dest = NULL;

    if (src == NULL)
        return NULL;
    len = argparser_strlen(src);
    if (len == FUNC_FAILED)
        return NULL;
    dest = malloc(sizeof(char) * (len + 1));
    if (dest == NULL)
        return NULL;
    for (; i < len; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}
