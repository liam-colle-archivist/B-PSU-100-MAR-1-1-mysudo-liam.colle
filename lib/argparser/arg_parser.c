/*
** EPITECH PROJECT, 2024
** arg_parser
** File description:
** my_ls
*/

#include <stdio.h>
#include <stdlib.h>
#include "argparser.h"
#include "utils.h"

arg_chain_t *parse_s_arg_sparg(arg_chain_t **first_chain,
    arg_chain_t *curr_chain, char *arg_str)
{
    curr_chain = chain_new_arguments(first_chain, &curr_chain, arg_str);
    curr_chain->next = NULL;
    return curr_chain;
}

arg_chain_t *parse_m_arg_sparg(arg_chain_t **first_chain,
    arg_chain_t *curr_chain, char *arg_str)
{
    if (*first_chain == NULL)
        curr_chain = chain_new_argument(first_chain, arg_str[1], NULL);
    else
        curr_chain = chain_new_argument(&curr_chain, arg_str[1], NULL);
    curr_chain->next = NULL;
    return curr_chain;
}

arg_chain_t *parse_ff_arg_sparg(arg_chain_t **first_chain,
    arg_chain_t *curr_chain, char *arg_str)
{
    if (*first_chain == NULL)
        curr_chain = chain_new_argument(first_chain, '\0', arg_str);
    else
        curr_chain = chain_new_argument(&curr_chain, '\0', arg_str);
    curr_chain->next = NULL;
    return curr_chain;
}

arg_chain_t *args_getfromtab(int argc, char **argv)
{
    arg_chain_t *first_chain = NULL;
    arg_chain_t *new_chain = NULL;
    int arg_len = 0;

    if (argc == 0 || argv == NULL)
        return NULL;
    for (int i = 1; argv[i] != NULL; i++) {
        arg_len = argparser_strlen(argv[i]);
        if (argv[i][0] == '-' && arg_len == 2) {
            new_chain = parse_m_arg_sparg(&first_chain, new_chain, argv[i]);
            continue;
        }
        if (argv[i][0] == '-' && arg_len > 2) {
            new_chain = parse_s_arg_sparg(&first_chain, new_chain, argv[i]);
            continue;
        }
        new_chain = parse_ff_arg_sparg(&first_chain, new_chain, argv[i]);
    }
    return first_chain;
}
