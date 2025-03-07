/*
** EPITECH PROJECT, 2025
** bootstrap_sudo
** File description:
** my_sudo
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/my.h"
#include "../include/my_exec.h"
#include "../include/usage.h"
#include "../include/argparser.h"
#include "../include/parser.h"
#include "../include/my_passwd.h"
#include "../include/my_group.h"
#include "../include/utils.h"
#include "../include/my_sudo.h"

static int basic_arg_fails(arg_chain_t *args)
{
    int s_flag = args_flag_check(args, 's');
    int u_flag = args_flag_check(args, 'u');
    int g_flag = args_flag_check(args, 'g');
    int strs_nf = arg_strs_noflag_check(args);
    char *u_ptr = arg_strflag_getstr(args, 'u');
    char *g_ptr = arg_strflag_getstr(args, 'g');

    if (args == NULL)
        return TRUE;
    if ((u_flag == TRUE) && ((u_ptr != NULL) == FALSE))
        return TRUE;
    if ((g_flag == TRUE) && ((g_ptr != NULL) == FALSE))
        return TRUE;
    if ((strs_nf == s_flag))
        return TRUE;
    return FALSE;
}

arg_chain_t *sudo_bootup_args(int argc, char **argv,
    prechk_exit_stat_t *exit_mode)
{
    arg_chain_t *args = NULL;
    int h_flag = 0;

    if (argc <= 0 || argv == NULL || exit_mode == NULL)
        return NULL;
    args = args_getfromtab(argc, argv);
    h_flag = args_flag_check(args, 'h');
    if (h_flag == TRUE) {
        usage_show("./src/usage.txt");
        free_arg_chain(args);
        *exit_mode = SUDO_EX_H_FLAG;
        return NULL;
    }
    if (argc < 2 || basic_arg_fails(args) == TRUE) {
        usage_show("./src/usage_lim.txt");
        free_arg_chain(args);
        *exit_mode = SUDO_EX_ILL_ARGS;
        return NULL;
    }
    return args;
}

int bootstrap_sudo(arg_chain_t *args)
{
    int sudo_exit = FUNC_FAILED;
    char *user = arg_strflag_getstr(args, 'u');
    char *group = arg_strflag_getstr(args, 'g');
    passwd_t *issuer = NULL;
    passwd_t *pwds = NULL;
    group_t *grp = NULL;
    my_sudo_data_t sudo_data = {NULL, getuid(), NULL, -1,
        NULL, FALSE, NULL, -1};

    sudo_data.user = user == NULL ? "root" : user;
    sudo_data.group = group == NULL ? sudo_data.user : group;
    if (sudo_obtain_data(&sudo_data, &issuer, &pwds, &grp) == FUNC_FAILED)
        return FUNC_FAILED;
    sudo_exit = sudo(&sudo_data, args);
    free_passwd(pwds);
    free_passwd(issuer);
    free_group(grp);
    return sudo_exit;
}
