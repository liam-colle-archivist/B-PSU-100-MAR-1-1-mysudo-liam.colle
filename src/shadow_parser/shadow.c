/*
** EPITECH PROJECT, 2025
** shadow
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

shadow_t *create_shadow(void)
{
    shadow_t *new_shadow = NULL;

    new_shadow = malloc(sizeof(shadow_t));
    if (new_shadow == NULL)
        return NULL;
    new_shadow->namp = NULL;
    new_shadow->pwdp = NULL;
    new_shadow->lstchg = 0;
    new_shadow->min = 0;
    new_shadow->max = 0;
    new_shadow->inact = 0;
    new_shadow->expire = 0;
    new_shadow->flag = 0;
    return new_shadow;
}

void clear_shadow(shadow_t *shadow)
{
    if (shadow == NULL)
        return;
    if (shadow->namp != NULL)
        free(shadow->namp);
    if (shadow->pwdp != NULL)
        free(shadow->pwdp);
    shadow->lstchg = 0;
    shadow->min = 0;
    shadow->max = 0;
    shadow->warn = 0;
    shadow->inact = 0;
    shadow->expire = 0;
    shadow->flag = 0;
}

void free_shadow(shadow_t *shadow)
{
    if (shadow == NULL)
        return;
    if (shadow->namp != NULL)
        free(shadow->namp);
    if (shadow->pwdp != NULL)
        free(shadow->pwdp);
    free(shadow);
}
