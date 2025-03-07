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
#include "../../include/my_shadow.h"
#include "../../include/statutils.h"
#include "../../include/utils.h"

bool_t group_user(group_t *grp, void *user)
{
    if (grp == NULL || user == NULL)
        return FALSE;
    if (grp->name == NULL)
        return FALSE;
    if (my_strcmp(grp->name, user) == CMP_EXACT)
        return TRUE;
    return FALSE;
}

bool_t group_gid(group_t *grp, void *gid_p)
{
    int *gid = NULL;

    if (grp == NULL || gid_p == NULL)
        return FALSE;
    gid = (int *) gid_p;
    if (gid == NULL)
        return FALSE;
    if (grp->gid == *gid)
        return TRUE;
    return FALSE;
}
