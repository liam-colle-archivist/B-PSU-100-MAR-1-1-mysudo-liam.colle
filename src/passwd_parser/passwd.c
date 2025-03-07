/*
** EPITECH PROJECT, 2025
** passwd
** File description:
** my_sudo
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../include/parser.h"
#include "../../include/my.h"
#include "../../include/my_passwd.h"
#include "../../include/statutils.h"
#include "../../include/utils.h"

passwd_t *create_passwd(void)
{
    passwd_t *new_passwd = NULL;

    new_passwd = malloc(sizeof(passwd_t));
    if (new_passwd == NULL)
        return NULL;
    new_passwd->user = NULL;
    new_passwd->password = NULL;
    new_passwd->uid = DEFAULT_GUID;
    new_passwd->gid = DEFAULT_GUID;
    new_passwd->description = NULL;
    new_passwd->home = NULL;
    new_passwd->default_shell = NULL;
    return new_passwd;
}

void clear_passwd(passwd_t *passwd)
{
    if (passwd == NULL)
        return;
    if (passwd->user != NULL)
        free(passwd->user);
    if (passwd->password != NULL)
        free(passwd->password);
    if (passwd->description != NULL)
        free(passwd->description);
    if (passwd->home != NULL)
        free(passwd->home);
    if (passwd->default_shell != NULL)
        free(passwd->default_shell);
    passwd->uid = 0;
    passwd->gid = 0;
}

void free_passwd(passwd_t *passwd)
{
    if (passwd == NULL)
        return;
    if (passwd->user != NULL)
        free(passwd->user);
    if (passwd->password != NULL)
        free(passwd->password);
    if (passwd->description != NULL)
        free(passwd->description);
    if (passwd->home != NULL)
        free(passwd->home);
    if (passwd->default_shell != NULL)
        free(passwd->default_shell);
    free(passwd);
}
