/*
** EPITECH PROJECT, 2025
** authentication
** File description:
** my_sudo
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <crypt.h>
#include "../../include/my_sudo.h"
#include "../../include/my_shadow.h"
#include "../../include/parser.h"
#include "../../include/utils.h"
#include "../../include/my.h"


static char *sudo_getpass_settings(char *pass, int len)
{
    int dollar_n = 0;
    char *pass_config = NULL;

    if (pass == NULL || len <= 0)
        return NULL;
    pass_config = malloc(sizeof(char) * len);
    if (pass_config == NULL)
        return NULL;
    memset(pass_config, '\0', len);
    for (int i = 0; pass[i] != '\0' && dollar_n <= 3; i++) {
        if (pass[i] == '$')
            dollar_n++;
        pass_config[i] = pass[i];
    }
    return pass_config;
}

static int sudo_initiate_passcmp(shadow_t *shadow, bool_t *result,
    char *pass_buff)
{
    char *pass_conf = NULL;
    char *crypt_pass = NULL;

    if (shadow == NULL || pass_buff == NULL)
        return FUNC_FAILED;
    pass_conf = sudo_getpass_settings(shadow->pwdp, my_strlen(shadow->pwdp));
    if (pass_conf == NULL)
        return FUNC_FAILED;
    crypt_pass = crypt(pass_buff, pass_conf);
    free(pass_conf);
    if (crypt_pass == NULL)
        return FUNC_FAILED;
    *result = my_strcmp(crypt_pass, shadow->pwdp) == CMP_EXACT;
    return FUNC_SUCCESS;
}

static int handle_passcmp_results(shadow_t *shadow,
    bool_t result, shadow_authm_t auth_mode)
{
    if (auth_mode == SHADOW_AUTHUNKN)
        return FUNC_FAILED;
    switch (auth_mode) {
        case SHADOW_NOAUTH:
            return FUNC_FAILED;
        case SHADOW_NOPASSAUTH:
            if (my_strcmp(shadow->namp, "root") == CMP_EXACT)
                return FUNC_SUCCESS;
            return FUNC_FAILED;
        case SHADOW_NOPASSREQ:
            return FUNC_SUCCESS;
        case SHADOW_PASSAUTH:
            if (result == TRUE)
                return FUNC_SUCCESS;
            return FUNC_FAILED;
        default:
            return FUNC_FAILED;
    }
}

static int do_auth(my_sudo_data_t *sudo_data,
    shadow_t *shadow, shadow_authm_t mode)
{
    char pass_buff[SUDO_MAX_PASSWORD_LEN];
    bool_t result = FALSE;

    if (sudo_data == NULL)
        return FUNC_FAILED;
    if (sudo_data->issuer == NULL)
        return FUNC_FAILED;
    if (is_mode_bypassing(sudo_data->issuer, mode) == TRUE)
        return FUNC_SUCCESS;
    if (sudo_get_pass(sudo_data, pass_buff) == FUNC_FAILED)
        return FUNC_FAILED;
    if (sudo_initiate_passcmp(shadow, &result, pass_buff) == FUNC_FAILED)
        return FUNC_FAILED;
    return handle_passcmp_results(shadow, result, mode);
}

int sudo_authentify(my_sudo_data_t *sudo_data)
{
    shadow_t *shadow = get_shadow(sudo_data == NULL ?
        NULL : sudo_data->issuer, shadow_user);
    shadow_authm_t mode = shadow == NULL ? SHADOW_AUTHUNKN
        : shadow_auth_mode(shadow->pwdp);

    if (shadow == NULL || sudo_data == NULL) {
        if (shadow == NULL)
            perror("sudo: shadow");
        return FUNC_FAILED;
    }
    if (shadow->pwdp == NULL || is_mode_failure(sudo_data->issuer, mode))
        return FUNC_FAILED;
    for (int tries = 0; tries < SUDO_MAX_AUTH_TRIES; tries++) {
        if (do_auth(sudo_data, shadow, mode) == FUNC_SUCCESS)
            return FUNC_SUCCESS;
        sleep(SUDO_FAIL_AUTH_DELAY);
    }
    printf("sudo: %d incorrect password attempts\n", SUDO_MAX_AUTH_TRIES);
    return FUNC_FAILED;
}
