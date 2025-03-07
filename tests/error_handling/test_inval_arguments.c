/*
** EPITECH PROJECT, 2025
** test_inval_arguments
** File description:
** my_sudo
*/

#include <stdio.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../../include/my.h"
#include "../../include/my_sudo.h"
#include "../../include/utils.h"

Test(test_inval_arguments, test_args_1, .init = cr_redirect_stdout)
{
    char *argv[] = {"my_sudo", NULL};
    int argc = my_tablen((const void **) argv);
    char *target_buffer = "usage: ./my_sudo -h\nusage: ./my_sudo [-ugEs] [command [args ...]]\n";
    prechk_exit_stat_t exit_mode = SUDO_EX_UNKNOWN;
    arg_chain_t *args = sudo_bootup_args(argc, argv, &exit_mode);

    cr_assert_eq(args == NULL, true, "Sudo arguments tests incorrect! (Returned PTR: %p)", args);
    bootstrap_sudo(args);
    cr_assert_stdout_eq_str(target_buffer, "");
}

Test(test_inval_arguments, test_args_2, .init = cr_redirect_stdout)
{
    char *argv[] = {"my_sudo", "-u", NULL};
    int argc = my_tablen((const void **) argv);
    char *target_buffer = "usage: ./my_sudo -h\nusage: ./my_sudo [-ugEs] [command [args ...]]\n";
    prechk_exit_stat_t exit_mode = SUDO_EX_UNKNOWN;
    arg_chain_t *args = sudo_bootup_args(argc, argv, &exit_mode);

    cr_assert_eq(args == NULL, true, "Sudo arguments tests incorrect! (Returned PTR: %p)", args);
    bootstrap_sudo(args);
    cr_assert_stdout_eq_str(target_buffer, "");
}

Test(test_inval_arguments, test_args_3, .init = cr_redirect_stdout)
{
    char *argv[] = {"my_sudo", "-g", NULL};
    int argc = my_tablen((const void **) argv);
    char *target_buffer = "usage: ./my_sudo -h\nusage: ./my_sudo [-ugEs] [command [args ...]]\n";
    prechk_exit_stat_t exit_mode = SUDO_EX_UNKNOWN;
    arg_chain_t *args = sudo_bootup_args(argc, argv, &exit_mode);

    cr_assert_eq(args == NULL, true, "Sudo arguments tests incorrect! (Returned PTR: %p)", args);
    bootstrap_sudo(args);
    cr_assert_stdout_eq_str(target_buffer, "");
}

Test(test_inval_arguments, test_args_4, .init = cr_redirect_stdout)
{
    char *argv[] = {"my_sudo", "-u", "root", "-g", NULL};
    int argc = my_tablen((const void **) argv);
    char *target_buffer = "usage: ./my_sudo -h\nusage: ./my_sudo [-ugEs] [command [args ...]]\n";
    prechk_exit_stat_t exit_mode = SUDO_EX_UNKNOWN;
    arg_chain_t *args = sudo_bootup_args(argc, argv, &exit_mode);

    cr_assert_eq(args == NULL, true, "Sudo arguments tests incorrect! (Returned PTR: %p)", args);
    bootstrap_sudo(args);
    cr_assert_stdout_eq_str(target_buffer, "");
}

Test(test_inval_arguments, test_args_5, .init = cr_redirect_stdout)
{
    char *argv[] = {"my_sudo", "-g", "root", "-u", NULL};
    int argc = my_tablen((const void **) argv);
    char *target_buffer = "usage: ./my_sudo -h\nusage: ./my_sudo [-ugEs] [command [args ...]]\n";
    prechk_exit_stat_t exit_mode = SUDO_EX_UNKNOWN;
    arg_chain_t *args = sudo_bootup_args(argc, argv, &exit_mode);

    cr_assert_eq(args == NULL, true, "Sudo arguments tests incorrect! (Returned PTR: %p)", args);
    bootstrap_sudo(args);
    cr_assert_stdout_eq_str(target_buffer, "");
}

Test(test_inval_arguments, test_args_6, .init = cr_redirect_stdout)
{
    char *argv[] = {"my_sudo", "-g", "-u", NULL};
    int argc = my_tablen((const void **) argv);
    char *target_buffer = "usage: ./my_sudo -h\nusage: ./my_sudo [-ugEs] [command [args ...]]\n";
    prechk_exit_stat_t exit_mode = SUDO_EX_UNKNOWN;
    arg_chain_t *args = sudo_bootup_args(argc, argv, &exit_mode);

    cr_assert_eq(args == NULL, true, "Sudo arguments tests incorrect! (Returned PTR: %p)", args);
    bootstrap_sudo(args);
    cr_assert_stdout_eq_str(target_buffer, "");
}

Test(test_inval_arguments, test_args_7, .init = cr_redirect_stdout)
{
    char *argv[] = {"my_sudo", "-u", "-g", NULL};
    int argc = my_tablen((const void **) argv);
    char *target_buffer = "usage: ./my_sudo -h\nusage: ./my_sudo [-ugEs] [command [args ...]]\n";
    prechk_exit_stat_t exit_mode = SUDO_EX_UNKNOWN;
    arg_chain_t *args = sudo_bootup_args(argc, argv, &exit_mode);

    cr_assert_eq(args == NULL, true, "Sudo arguments tests incorrect! (Returned PTR: %p)", args);
    bootstrap_sudo(args);
    cr_assert_stdout_eq_str(target_buffer, "");
}

Test(test_inval_arguments, test_args_8, .init = cr_redirect_stdout)
{
    char *argv[] = {"my_sudo", "-u", "-g", "-u", "-g", NULL};
    int argc = my_tablen((const void **) argv);
    char *target_buffer = "usage: ./my_sudo -h\nusage: ./my_sudo [-ugEs] [command [args ...]]\n";
    prechk_exit_stat_t exit_mode = SUDO_EX_UNKNOWN;
    arg_chain_t *args = sudo_bootup_args(argc, argv, &exit_mode);

    cr_assert_eq(args == NULL, true, "Sudo arguments tests incorrect! (Returned PTR: %p)", args);
    bootstrap_sudo(args);
    cr_assert_stdout_eq_str(target_buffer, "");
}

Test(test_inval_arguments, test_args_9, .init = cr_redirect_stdout)
{
    char *argv[] = {"my_sudo", "-g", "-u", "-g", "-u", NULL};
    int argc = my_tablen((const void **) argv);
    char *target_buffer = "usage: ./my_sudo -h\nusage: ./my_sudo [-ugEs] [command [args ...]]\n";
    prechk_exit_stat_t exit_mode = SUDO_EX_UNKNOWN;
    arg_chain_t *args = sudo_bootup_args(argc, argv, &exit_mode);

    cr_assert_eq(args == NULL, true, "Sudo arguments tests incorrect! (Returned PTR: %p)", args);
    bootstrap_sudo(args);
    cr_assert_stdout_eq_str(target_buffer, "");
}

Test(test_inval_arguments, test_args_10, .init = cr_redirect_stdout)
{
    char *argv[] = {"my_sudo", "-u", "-s", NULL};
    int argc = my_tablen((const void **) argv);
    char *target_buffer = "usage: ./my_sudo -h\nusage: ./my_sudo [-ugEs] [command [args ...]]\n";
    prechk_exit_stat_t exit_mode = SUDO_EX_UNKNOWN;
    arg_chain_t *args = sudo_bootup_args(argc, argv, &exit_mode);

    cr_assert_eq(args == NULL, true, "Sudo arguments tests incorrect! (Returned PTR: %p)", args);
    bootstrap_sudo(args);
    cr_assert_stdout_eq_str(target_buffer, "");
}

Test(test_inval_arguments, test_args_11, .init = cr_redirect_stdout)
{
    char *argv[] = {"my_sudo", "-g", "-s", NULL};
    int argc = my_tablen((const void **) argv);
    char *target_buffer = "usage: ./my_sudo -h\nusage: ./my_sudo [-ugEs] [command [args ...]]\n";
    prechk_exit_stat_t exit_mode = SUDO_EX_UNKNOWN;
    arg_chain_t *args = sudo_bootup_args(argc, argv, &exit_mode);

    cr_assert_eq(args == NULL, true, "Sudo arguments tests incorrect! (Returned PTR: %p)", args);
    bootstrap_sudo(args);
    cr_assert_stdout_eq_str(target_buffer, "");
}

Test(test_inval_arguments, test_args_12, .init = cr_redirect_stdout)
{
    char *argv[] = {"my_sudo", "-u", "root", "-g", "-s", NULL};
    int argc = my_tablen((const void **) argv);
    char *target_buffer = "usage: ./my_sudo -h\nusage: ./my_sudo [-ugEs] [command [args ...]]\n";
    prechk_exit_stat_t exit_mode = SUDO_EX_UNKNOWN;
    arg_chain_t *args = sudo_bootup_args(argc, argv, &exit_mode);

    cr_assert_eq(args == NULL, true, "Sudo arguments tests incorrect! (Returned PTR: %p)", args);
    bootstrap_sudo(args);
    cr_assert_stdout_eq_str(target_buffer, "");
}

Test(test_inval_arguments, test_args_13, .init = cr_redirect_stdout)
{
    char *argv[] = {"my_sudo", "-g", "root", "-u", "-s", NULL};
    int argc = my_tablen((const void **) argv);
    char *target_buffer = "usage: ./my_sudo -h\nusage: ./my_sudo [-ugEs] [command [args ...]]\n";
    prechk_exit_stat_t exit_mode = SUDO_EX_UNKNOWN;
    arg_chain_t *args = sudo_bootup_args(argc, argv, &exit_mode);

    cr_assert_eq(args == NULL, true, "Sudo arguments tests incorrect! (Returned PTR: %p)", args);
    bootstrap_sudo(args);
    cr_assert_stdout_eq_str(target_buffer, "");
}

Test(test_inval_arguments, test_args_14, .init = cr_redirect_stdout)
{
    char *argv[] = {"my_sudo", "-g", "-u", "-s", NULL};
    int argc = my_tablen((const void **) argv);
    char *target_buffer = "usage: ./my_sudo -h\nusage: ./my_sudo [-ugEs] [command [args ...]]\n";
    prechk_exit_stat_t exit_mode = SUDO_EX_UNKNOWN;
    arg_chain_t *args = sudo_bootup_args(argc, argv, &exit_mode);

    cr_assert_eq(args == NULL, true, "Sudo arguments tests incorrect! (Returned PTR: %p)", args);
    bootstrap_sudo(args);
    cr_assert_stdout_eq_str(target_buffer, "");
}

Test(test_inval_arguments, test_args_15, .init = cr_redirect_stdout)
{
    char *argv[] = {"my_sudo", "-u", "-g", "-s", NULL};
    int argc = my_tablen((const void **) argv);
    char *target_buffer = "usage: ./my_sudo -h\nusage: ./my_sudo [-ugEs] [command [args ...]]\n";
    prechk_exit_stat_t exit_mode = SUDO_EX_UNKNOWN;
    arg_chain_t *args = sudo_bootup_args(argc, argv, &exit_mode);

    cr_assert_eq(args == NULL, true, "Sudo arguments tests incorrect! (Returned PTR: %p)", args);
    bootstrap_sudo(args);
    cr_assert_stdout_eq_str(target_buffer, "");
}

Test(test_inval_arguments, test_args_16, .init = cr_redirect_stdout)
{
    char *argv[] = {"my_sudo", "-u", "-g", "-u", "-g", "-s", NULL};
    int argc = my_tablen((const void **) argv);
    char *target_buffer = "usage: ./my_sudo -h\nusage: ./my_sudo [-ugEs] [command [args ...]]\n";
    prechk_exit_stat_t exit_mode = SUDO_EX_UNKNOWN;
    arg_chain_t *args = sudo_bootup_args(argc, argv, &exit_mode);

    cr_assert_eq(args == NULL, true, "Sudo arguments tests incorrect! (Returned PTR: %p)", args);
    bootstrap_sudo(args);
    cr_assert_stdout_eq_str(target_buffer, "");
}

Test(test_inval_arguments, test_args_17, .init = cr_redirect_stdout)
{
    char *argv[] = {"my_sudo", "-g", "-u", "-g", "-u", "-s", NULL};
    int argc = my_tablen((const void **) argv);
    char *target_buffer = "usage: ./my_sudo -h\nusage: ./my_sudo [-ugEs] [command [args ...]]\n";
    prechk_exit_stat_t exit_mode = SUDO_EX_UNKNOWN;
    arg_chain_t *args = sudo_bootup_args(argc, argv, &exit_mode);

    cr_assert_eq(args == NULL, true, "Sudo arguments tests incorrect! (Returned PTR: %p)", args);
    bootstrap_sudo(args);
    cr_assert_stdout_eq_str(target_buffer, "");
}
