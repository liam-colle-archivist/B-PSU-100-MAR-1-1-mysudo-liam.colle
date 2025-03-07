/*
** EPITECH PROJECT, 2024
** my_strcdup
** File description:
** libmy
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

char *my_strcdup(const char *src_1, const char *src_2)
{
    int index = 0;
    int len_1 = my_strlen(src_1);
    int len_2 = my_strlen(src_2);
    char *dest = malloc(sizeof(char) * (len_1 + len_2 + 1));

    if (dest == NULL)
        return NULL;
    for (int i = 0; i < len_1; i++) {
        dest[index] = src_1[i];
        index++;
    }
    for (int i = 0; i < len_2; i++) {
        dest[index] = src_2[i];
        index++;
    }
    dest[index] = '\0';
    return dest;
}
