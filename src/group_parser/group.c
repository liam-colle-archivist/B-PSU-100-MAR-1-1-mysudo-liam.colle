/*
** EPITECH PROJECT, 2025
** group
** File description:
** my_sudo
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../include/parser.h"
#include "../../include/my.h"
#include "../../include/my_group.h"
#include "../../include/statutils.h"
#include "../../include/utils.h"

group_t *create_group(void)
{
    group_t *new_group = NULL;

    new_group = malloc(sizeof(group_t));
    if (new_group == NULL)
        return NULL;
    new_group->name = NULL;
    new_group->pwdp = NULL;
    new_group->gid = 0;
    new_group->users = NULL;
    return new_group;
}

void clear_group(group_t *group)
{
    if (group == NULL)
        return;
    if (group->name != NULL)
        free(group->name);
    if (group->pwdp != NULL)
        free(group->pwdp);
    if (group->users != NULL)
        free(group->users);
    group->gid = 0;
}

void free_group(group_t *group)
{
    if (group == NULL)
        return;
    if (group->name != NULL)
        free(group->name);
    if (group->pwdp != NULL)
        free(group->pwdp);
    if (group->users != NULL)
        free(group->users);
    free(group);
}
