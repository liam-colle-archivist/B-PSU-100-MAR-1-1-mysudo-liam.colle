/*
** EPITECH PROJECT, 2025
** authentication_mode
** File description:
** my_sudo
*/

#include <stdio.h>
#include "../../include/my_shadow.h"
#include "../../include/utils.h"
#include "../../include/my.h"

shadow_authm_t shadow_auth_mode(char *conf_buff)
{
    if (conf_buff == NULL || my_strcmp(conf_buff, "!*") == CMP_EXACT)
        return SHADOW_AUTHUNKN;
    if (my_strcmp(conf_buff, "!") == CMP_EXACT)
        return SHADOW_NOPASSAUTH;
    if (my_strcmp(conf_buff, "!!") == CMP_EXACT)
        return SHADOW_NOPASSREQ;
    if (my_strcmp(conf_buff, "*") == CMP_EXACT)
        return SHADOW_NOAUTH;
    return SHADOW_PASSAUTH;
}

bool_t is_mode_bypassing(char *issuer, shadow_authm_t mode)
{
    if (issuer == NULL || mode == SHADOW_AUTHUNKN)
        return FALSE;
    if (my_strcmp(issuer, "root") == CMP_EXACT)
        return TRUE;
    return FALSE;
}

bool_t is_mode_failure(char *issuer, shadow_authm_t mode)
{
    if (mode == SHADOW_AUTHUNKN)
        return TRUE;
    if (my_strcmp(issuer, "root") != CMP_EXACT && mode == SHADOW_NOPASSAUTH)
        return TRUE;
    if (mode == SHADOW_NOAUTH)
        return TRUE;
    return FALSE;
}
