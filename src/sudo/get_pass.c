/*
** EPITECH PROJECT, 2025
** get_pass
** File description:
** my_sudo
*/

#include <stdio.h>
#include <string.h>
#include <termios.h>
#include "../../include/my_sudo.h"
#include "../../include/my_shadow.h"
#include "../../include/parser.h"
#include "../../include/utils.h"
#include "../../include/my.h"

static int get_pass_invi(char *buffer)
{
    char *newline = NULL;
    struct termios old_settings;
    struct termios new_settings;

    tcgetattr(STDIN, &old_settings);
    new_settings = old_settings;
    new_settings.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN, TCSANOW, &new_settings);
    if (fgets(buffer, SUDO_MAX_PASSWORD_LEN, stdin) == NULL)
        return FUNC_FAILED;
    newline = strchr(buffer, '\n');
    if (newline != NULL)
        *newline = '\0';
    tcsetattr(STDIN, TCSANOW, &old_settings);
    return FUNC_SUCCESS;
}

int sudo_get_pass(my_sudo_data_t *sudo_data, char *buffer)
{
    printf("[sudo]: password for %s: ", sudo_data->issuer);
    if (get_pass_invi(buffer) == FUNC_FAILED)
        return FUNC_FAILED;
    putchar('\n');
    return FUNC_SUCCESS;
}
