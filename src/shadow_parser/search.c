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

bool_t shadow_user(shadow_t *shdw, void *user)
{
    if (shdw == NULL || user == NULL)
        return FALSE;
    if (shdw->namp == NULL)
        return FALSE;
    if (my_strcmp(shdw->namp, user) == CMP_EXACT)
        return TRUE;
    return FALSE;
}
