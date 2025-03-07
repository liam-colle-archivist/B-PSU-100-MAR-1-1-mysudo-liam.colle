/*
** EPITECH PROJECT, 2024
** arg_get
** File description:
** argparser
*/

#include <stdio.h>
#include <stdlib.h>
#include "argparser.h"
#include "utils.h"

char *arg_strflag_getstr(arg_chain_t *chain, char flag)
{
    if (chain == NULL)
        return NULL;
    for (; chain != NULL; chain = chain->next)
        if (chain->flag == flag)
            break;
    if (chain == NULL)
        return NULL;
    if (chain->next == NULL)
        return NULL;
    if (chain->next->type == STRING_ARG_TYPE)
        return chain->next->argument;
    return NULL;
}

char *arg_getstr(arg_chain_t *chain)
{
    if (chain == NULL)
        return NULL;
    for (; chain != NULL; chain = chain->next)
        if (chain->type == STRING_ARG_TYPE)
            return chain->argument;
    return NULL;
}

static int getstrs_len(arg_chain_t *chain)
{
    int len = 0;
    arg_chain_t *prev_chain = (chain != NULL) ? chain : NULL;

    if (chain == NULL)
        return FUNC_FAILED;
    for (; chain != NULL; chain = chain->next) {
        if (chain->type == STRING_ARG_TYPE
            && prev_chain->type != FLAG_ARG_TYPE)
            len++;
        prev_chain = chain;
    }
    return len;
}

static char **getstrs_tab(arg_chain_t *chain)
{
    int len = 0;
    char **strings = NULL;

    if (chain == NULL)
        return NULL;
    len = getstrs_len(chain);
    if (len == FUNC_FAILED)
        return NULL;
    strings = malloc(sizeof(char *) * (len + 1));
    if (strings == NULL)
        return NULL;
    strings[len] = NULL;
    return strings;
}

char **arg_getstrs_noflag(arg_chain_t *chain)
{
    char **strings = NULL;
    arg_chain_t *prev_chain = (chain != NULL) ? chain : NULL;
    int index = 0;

    if (chain == NULL)
        return NULL;
    strings = getstrs_tab(chain);
    if (strings == NULL)
        return NULL;
    for (; chain != NULL; chain = chain->next) {
        if (chain->type == STRING_ARG_TYPE
            && prev_chain->type != FLAG_ARG_TYPE) {
                strings[index] = argparser_strdup(chain->argument);
                index++;
            }
        prev_chain = chain;
    }
    return strings;
}
