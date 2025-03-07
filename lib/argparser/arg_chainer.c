/*
** EPITECH PROJECT, 2024
** arg_chainer
** File description:
** my_ls
*/

#include <stdio.h>
#include <stdlib.h>
#include "argparser.h"
#include "utils.h"

arg_chain_t *chain_new_arguments(arg_chain_t **first_chain,
    arg_chain_t **prev_arg, char *arg)
{
    int i = 0;

    for (i = 1; arg[i] != '\0'; i++) {
        *prev_arg = chain_new_argument(prev_arg, arg[i], NULL);
        if (*first_chain == NULL)
            *first_chain = *prev_arg;
    }
    if (i <= 1)
        return NULL;
    return *prev_arg;
}

arg_chain_t *chain_new_argument(arg_chain_t **prev_arg,
    char flag, char *arg)
{
    arg_chain_t *new_arg = malloc(sizeof(arg_chain_t));

    if (flag == '\0' && arg == NULL)
        new_arg->type = UNKNOWN_ARG_TYPE;
    if (flag == '\0' && arg != NULL)
        new_arg->type = STRING_ARG_TYPE;
    if (flag != '\0' && arg == NULL)
        new_arg->type = FLAG_ARG_TYPE;
    new_arg->flag = flag;
    if (arg != NULL)
        new_arg->argument = argparser_strdup(arg);
    else
        new_arg->argument = NULL;
    if (*(prev_arg) == NULL)
        *(prev_arg) = new_arg;
    else
        (*prev_arg)->next = new_arg;
    return new_arg;
}

arg_chain_t *arg_get_end(arg_chain_t *chain)
{
    arg_chain_t *curr_chain = chain;

    while (curr_chain->next != NULL) {
        curr_chain = curr_chain->next;
    }
    return curr_chain;
}

void free_arg_chain(arg_chain_t *start)
{
    arg_chain_t *previous_chain = start;
    arg_chain_t *curr_chain = start;

    while (curr_chain != NULL) {
        free(curr_chain->argument);
        previous_chain = curr_chain;
        curr_chain = curr_chain->next;
        free(previous_chain);
    }
}
