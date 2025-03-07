/*
** EPITECH PROJECT, 2024
** arg_checker
** File description:
** argparser
*/

#include <stdio.h>
#include "utils.h"
#include "argparser.h"

int args_flag_check(arg_chain_t *chain, char flag)
{
    if (chain == NULL)
        return FUNC_FAILED;
    for (; chain != NULL; chain = chain->next)
        if (chain->flag == flag)
            return TRUE;
    return FALSE;
}

bool_t arg_strs_noflag_check(arg_chain_t *chain)
{
    arg_chain_t *prev_chain = (chain != NULL) ? chain : NULL;

    if (chain == NULL)
        return FALSE;
    for (; chain != NULL; chain = chain->next) {
        if (chain->type == STRING_ARG_TYPE
            && prev_chain->type != FLAG_ARG_TYPE)
                return TRUE;
        prev_chain = chain;
    }
    return FALSE;
}
