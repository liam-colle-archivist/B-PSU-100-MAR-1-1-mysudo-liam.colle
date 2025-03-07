/*
** EPITECH PROJECT, 2025
** test_arguments
** File description:
** my_sudo
*/

#include <stdio.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../../include/my.h"
#include "../../include/my_sudo.h"
#include "../../include/utils.h"

Test(test_arguments, test_args_1)
{
    char *argv[] = {"my_sudo", "whoami", NULL};
    int argc = my_tablen((const void **) argv);
    prechk_exit_stat_t exit_mode = SUDO_EX_UNKNOWN;
    arg_chain_t *args = sudo_bootup_args(argc, argv, &exit_mode);

    cr_assert_eq(args != NULL, true, "Sudo arguments tests incorrect! (Returned PTR: %p)", args);
    bootstrap_sudo(args);
}

Test(test_arguments, test_args_2)
{
    char *argv[] = {"my_sudo", "-u", "root", "whoami", NULL};
    int argc = my_tablen((const void **) argv);
    prechk_exit_stat_t exit_mode = SUDO_EX_UNKNOWN;
    arg_chain_t *args = sudo_bootup_args(argc, argv, &exit_mode);

    cr_assert_eq(args != NULL, true, "Sudo arguments tests incorrect! (Returned PTR: %p)", args);
    bootstrap_sudo(args);
}

Test(test_arguments, test_args_3)
{
    char *argv[] = {"my_sudo", "-g", "root", "whoami", NULL};
    int argc = my_tablen((const void **) argv);
    prechk_exit_stat_t exit_mode = SUDO_EX_UNKNOWN;
    arg_chain_t *args = sudo_bootup_args(argc, argv, &exit_mode);

    cr_assert_eq(args != NULL, true, "Sudo arguments tests incorrect! (Returned PTR: %p)", args);
    bootstrap_sudo(args);
}

Test(test_arguments, test_args_4)
{
    char *argv[] = {"my_sudo", "-u", "root", "-g", "root", "whoami", NULL};
    int argc = my_tablen((const void **) argv);
    prechk_exit_stat_t exit_mode = SUDO_EX_UNKNOWN;
    arg_chain_t *args = sudo_bootup_args(argc, argv, &exit_mode);

    cr_assert_eq(args != NULL, true, "Sudo arguments tests incorrect! (Returned PTR: %p)", args);
    bootstrap_sudo(args);
}

Test(test_arguments, test_args_5)
{
    char *argv[] = {"my_sudo", "-g", "root", "-u", "root", "whoami", NULL};
    int argc = my_tablen((const void **) argv);
    prechk_exit_stat_t exit_mode = SUDO_EX_UNKNOWN;
    arg_chain_t *args = sudo_bootup_args(argc, argv, &exit_mode);

    cr_assert_eq(args != NULL, true, "Sudo arguments tests incorrect! (Returned PTR: %p)", args);
    bootstrap_sudo(args);
}

Test(test_arguments, test_args_6)
{
    char *argv[] = {"my_sudo", "-u", "bin", "-g", "root", "whoami", NULL};
    int argc = my_tablen((const void **) argv);
    prechk_exit_stat_t exit_mode = SUDO_EX_UNKNOWN;
    arg_chain_t *args = sudo_bootup_args(argc, argv, &exit_mode);

    cr_assert_eq(args != NULL, true, "Sudo arguments tests incorrect! (Returned PTR: %p)", args);
    bootstrap_sudo(args);
}

Test(test_arguments, test_args_7)
{
    char *argv[] = {"my_sudo", "-g", "root", "-u", "bin", "whoami", NULL};
    int argc = my_tablen((const void **) argv);
    prechk_exit_stat_t exit_mode = SUDO_EX_UNKNOWN;
    arg_chain_t *args = sudo_bootup_args(argc, argv, &exit_mode);

    cr_assert_eq(args != NULL, true, "Sudo arguments tests incorrect! (Returned PTR: %p)", args);
    bootstrap_sudo(args);
}

Test(test_arguments, test_args_8)
{
    char *argv[] = {"my_sudo", "-u", "bin", "-g", "root", "whoami", NULL};
    int argc = my_tablen((const void **) argv);
    prechk_exit_stat_t exit_mode = SUDO_EX_UNKNOWN;
    arg_chain_t *args = sudo_bootup_args(argc, argv, &exit_mode);

    cr_assert_eq(args != NULL, true, "Sudo arguments tests incorrect! (Returned PTR: %p)", args);
    bootstrap_sudo(args);
}

Test(test_arguments, test_args_9)
{
    char *argv[] = {"my_sudo", "-g", "root", "-u", "bin", "whoami", NULL};
    int argc = my_tablen((const void **) argv);
    prechk_exit_stat_t exit_mode = SUDO_EX_UNKNOWN;
    arg_chain_t *args = sudo_bootup_args(argc, argv, &exit_mode);

    cr_assert_eq(args != NULL, true, "Sudo arguments tests incorrect! (Returned PTR: %p)", args);
    bootstrap_sudo(args);
}
