/*
** EPITECH PROJECT, 2024
** ArgParser
** File description:
** ArgParser (Header)
*/

#include "utils.h"

#ifndef ARGPARSER_H
    #define ARGPARSER_H

    #define ARG_END(chain)  (arg_get_end(chain))

#endif

#ifndef ARGPARSER_CHAIN_H
    #define ARGPARSER_CHAIN_H

typedef enum {
    UNKNOWN_ARG_TYPE,
    STRING_ARG_TYPE,
    FLAG_ARG_TYPE,
    NOSTRFLAG_ARG_TYPE
} arg_chain_types_t;

typedef struct arg_chain {
    arg_chain_types_t type;
    char flag;
    char *argument;
    struct arg_chain *next;
} arg_chain_t;

arg_chain_t *chain_new_arguments(arg_chain_t **first_chain,
    arg_chain_t **prev_arg, char *arg);
arg_chain_t *chain_new_argument(arg_chain_t **prev_arg,
    char flag, char *arg);

#endif

#ifndef ARGPARSER_PARSER_H
    #define ARGPARSER_PARSER_H

arg_chain_t *parse_s_arg_sparg(arg_chain_t **first_chain,
    arg_chain_t *curr_chain, char *arg_str);
arg_chain_t *parse_m_arg_sparg(arg_chain_t **first_chain,
    arg_chain_t *curr_chain, char *arg_str);
arg_chain_t *parse_ff_arg_sparg(arg_chain_t **first_chain,
    arg_chain_t *curr_chain, char *arg_str);
void free_arg_chain(arg_chain_t *start);
arg_chain_t *arg_get_end(arg_chain_t *chain);
arg_chain_t *args_getfromtab(int argc, char **argv);

#endif

#ifndef ARGPARSER_DEPS_H
    #define ARGPARSER_DEPS_H

int argparser_strlen(const char *str);
char *argparser_strdup(const char *src);

#endif

#ifndef ARGPARSER_GET_H
    #define ARGPARSER_GET_H

char *arg_strflag_getstr(arg_chain_t *chain, char flag);
char *arg_getstr(arg_chain_t *chain);
char **arg_getstrs_noflag(arg_chain_t *chain);

#endif

#ifndef ARGPARSER_CHECK_H
    #define ARGPARSER_CHECK_H

int args_flag_check(arg_chain_t *chain, char flag);
bool_t arg_strs_noflag_check(arg_chain_t *chain);

#endif
