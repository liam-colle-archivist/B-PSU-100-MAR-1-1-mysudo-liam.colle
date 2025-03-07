/*
** EPITECH PROJECT, 2025
** sudo
** File description:
** my_sudo
*/

#include <stdio.h>
#include <unistd.h>
#include "../../include/my_sudo.h"
#include "../../include/my_passwd.h"
#include "../../include/parser.h"
#include "../../include/argparser.h"
#include "../../include/utils.h"
#include "../../include/my_exec.h"
#include "../../include/my.h"

static int assign_permissions(my_sudo_data_t *sudo_data)
{
    if (sudo_data == NULL)
        return FUNC_FAILED;
    if (setgid(sudo_data->group_id) == FUNC_FAILED) {
        perror("sudo: setgid");
        return FUNC_FAILED;
    }
    if (setuid(sudo_data->user_id) == FUNC_FAILED) {
        perror("sudo: setuid");
        return FUNC_FAILED;
    }
    return FUNC_SUCCESS;
}

static int handle_error(passwd_t *issuer, passwd_t *pwds, group_t *grp)
{
    if (issuer == NULL || pwds == NULL || grp == NULL) {
        if (issuer == NULL)
            fprintf(stderr, "sudo: Issuer not found\n");
        if (pwds == NULL)
            fprintf(stderr, "sudo: User not found\n");
        if (grp == NULL)
            fprintf(stderr, "sudo: Group not found\n");
        free_passwd(issuer);
        free_passwd(pwds);
        free_group(grp);
        return FUNC_FAILED;
    }
    return FUNC_SUCCESS;
}

int sudo_obtain_data(my_sudo_data_t *sudo_data,
    passwd_t **issuer, passwd_t **pwds, group_t **grp)
{
    if (sudo_data == NULL || issuer == NULL || grp == NULL || pwds == NULL)
        return FUNC_FAILED;
    *pwds = get_passwd(sudo_data->user, passwd_user);
    *grp = get_group(sudo_data->group, group_user);
    *issuer = get_passwd(&sudo_data->issuer_id, passwd_uid);
    if (handle_error(*issuer, *pwds, *grp) == FUNC_FAILED)
        return FUNC_FAILED;
    sudo_data->issuer = (*issuer)->user;
    sudo_data->user = (*pwds)->user;
    sudo_data->user_id = (*pwds)->uid;
    sudo_data->default_shell = (*pwds)->default_shell;
    sudo_data->group = (*grp)->name;
    sudo_data->group_id = (*grp)->gid;
    return FUNC_SUCCESS;
}

int sudo(my_sudo_data_t *sudo_data, arg_chain_t *args)
{
    char **program_args = NULL;
    char *shell_args[2] = {sudo_data->default_shell, NULL};

    if (sudo_data == NULL || args == NULL)
        return FUNC_FAILED;
    program_args = arg_getstrs_noflag(args);
    if (program_args == NULL)
        return FUNC_FAILED;
    sudo_data->shell_mode = args_flag_check(args, 's');
    if (sudo_authentify(sudo_data) == FUNC_FAILED) {
        my_tabfree((void **) program_args);
        return FUNC_FAILED;
    }
    if (assign_permissions(sudo_data) == FUNC_FAILED) {
        my_tabfree((void **) program_args);
        return FUNC_FAILED;
    }
    return sudo_data->shell_mode == FALSE ? my_exec(program_args[0],
        program_args) : my_exec(sudo_data->default_shell, shell_args);
}
