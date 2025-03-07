/*
** EPITECH PROJECT, 2025
** search
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

bool_t passwd_user(passwd_t *pwds, void *user)
{
    if (pwds == NULL || user == NULL)
        return FALSE;
    if (pwds->user == NULL)
        return FALSE;
    if (my_strcmp(pwds->user, user) == CMP_EXACT)
        return TRUE;
    return FALSE;
}

bool_t passwd_uid(passwd_t *pwds, void *uid_p)
{
    int *uid = NULL;

    if (pwds == NULL || uid_p == NULL)
        return FALSE;
    uid = (int *) uid_p;
    if (uid == NULL)
        return FALSE;
    if (pwds->uid == *uid)
        return TRUE;
    return FALSE;
}
