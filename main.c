/*
** EPITECH PROJECT, 2025
** main
** File description:
** Secured (BST)
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "include/my.h"
#include "include/my_exec.h"
#include "include/usage.h"
#include "include/argparser.h"
#include "include/parser.h"
#include "include/my_passwd.h"
#include "include/my_group.h"
#include "include/utils.h"
#include "include/my_sudo.h"

int main(int argc, char **argv)
{
    prechk_exit_stat_t exit_mode = SUDO_EX_UNKNOWN;
    arg_chain_t *args = sudo_bootup_args(argc, argv, &exit_mode);

    if (args == NULL) {
        if (exit_mode == SUDO_EX_H_FLAG)
            return EXIT_SUCCESS;
        return EXIT_FAILURE_84;
    }
    if (bootstrap_sudo(args) != FUNC_SUCCESS) {
        free_arg_chain(args);
        return EXIT_FAILURE_84;
    }
    free_arg_chain(args);
    return EXIT_SUCCESS;
}
