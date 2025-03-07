/*
** EPITECH PROJECT, 2024
** my_str_to_word_array
** File description:
** libmy
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "utils.h"

static int check_lr_cases(char const *str, int count_lr, int index)
{
    if (count_lr == TRUE && str[index] == '\n')
        return TRUE;
    if (is_printable_nospace(str[index]) == TRUE &&
        count_lr == TRUE && str[index + 1] == '\n')
        return TRUE;
    if (str[index] == '\n' &&
        count_lr == TRUE && str[index + 1] == '\0')
        return TRUE;
    return FALSE;
}

static int count_spaces(char const *str, int count_lr)
{
    int spaces = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (check_lr_cases(str, count_lr, i) == TRUE
            || (is_printable_nospace(str[i]) == TRUE && str[i + 1] == '\0')) {
            spaces++;
            continue;
        }
        if (is_printable_nospace(str[i]) == TRUE)
            continue;
        if (is_printable_nospace(str[i]) == FALSE && str[i + 1] == ' ')
            continue;
        if (is_printable_nospace(str[i]) == FALSE && str[i + 1] == '\0')
            continue;
        spaces++;
    }
    return spaces;
}

static char *write_new_element(char const *str, int *i, int count_lr)
{
    int len = 0;
    int start = *i;
    char *sub_dest = 0;

    if (count_lr == TRUE && str[*i] == '\n')
        len++;
    else {
        for (; is_printable_nospace(str[*i]) == TRUE; *i += 1)
            len++;
        if ((count_lr == TRUE && str[*i] == '\0'))
            *i -= 1;
        if (count_lr == TRUE && str[*i] == '\n')
            *i -= 1;
    }
    sub_dest = malloc(sizeof(char) * (len + 1));
    for (int j = 0; j < len; j++)
        sub_dest[j] = str[start + j];
    sub_dest[len] = '\0';
    return sub_dest;
}

static void fill_destination(char **dest, int start, int size)
{
    if (dest == NULL || size <= 0)
        return;
    for (int i = start; i < size; i++) {
        dest[i] = malloc(sizeof(char *));
        if (dest[i] == NULL)
            continue;
        dest[i][0] = '\0';
    }
}

static char **process_str_towa(char const *str, int count_lr)
{
    int spaces = count_spaces(str, count_lr);
    int word = 0;
    int i = 0;
    char **dest = malloc(sizeof(char *) * (spaces + 1));

    if (dest == NULL)
        return NULL;
    for (; str[i] != '\0' && word < spaces + 1; i++) {
        if (is_printable_nospace(str[i]) == TRUE ||
            (count_lr == TRUE && str[i] == '\n')) {
            dest[word] = write_new_element(str, &i, count_lr);
            word++;
            continue;
        }
        if (is_printable_nospace(str[i + 1]) == FALSE || str[i + 1] == '\0')
            continue;
    }
    fill_destination(dest, word, spaces);
    dest[spaces] = NULL;
    return dest;
}

char **my_str_to_word_array(char const *str, int count_lr)
{
    char **dest = NULL;

    if (str == NULL || (count_lr < FALSE || count_lr > TRUE))
        return NULL;
    if (str[0] == '\0') {
        dest = malloc(sizeof(char *));
        dest[0] = NULL;
        return NULL;
    }
    return process_str_towa(str, count_lr);
}
