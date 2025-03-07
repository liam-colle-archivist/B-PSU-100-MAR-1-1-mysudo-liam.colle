/*
** EPITECH PROJECT, 2025
** my_sudo
** File description:
** my_sudo
*/

#include "argparser.h"
#include "my_passwd.h"
#include "my_shadow.h"
#include "my_group.h"

#ifndef MY_SUDO
    #define MY_SUDO

    #define SUDO_FAIL_AUTH_DELAY 3
    #define SUDO_MAX_AUTH_TRIES 3
    #define SUDO_MAX_PASSWORD_LEN 1024

typedef enum {
    SUDO_EX_UNKNOWN = -1,
    SUDO_EX_OK,
    SUDO_EX_H_FLAG,
    SUDO_EX_ILL_ARGS,
} prechk_exit_stat_t;

typedef struct {
    char *issuer;
    int issuer_id;
    char *user;
    int user_id;
    char *default_shell;
    bool_t shell_mode;
    char *group;
    int group_id;
} my_sudo_data_t;

int bootstrap_sudo(arg_chain_t *args);
arg_chain_t *sudo_bootup_args(int argc, char **argv,
    prechk_exit_stat_t *exit_mode);
int sudo(my_sudo_data_t *sudo_data, arg_chain_t *args);
int sudo_authentify(my_sudo_data_t *sudo_data);
int sudo_obtain_data(my_sudo_data_t *sudo_data,
    passwd_t **issuer, passwd_t **pwds, group_t **grp);
int sudo_get_pass(my_sudo_data_t *sudo_data, char *buffer);
bool_t is_mode_bypassing(char *issuer, shadow_authm_t mode);
bool_t is_mode_failure(char *issuer, shadow_authm_t mode);

#endif
