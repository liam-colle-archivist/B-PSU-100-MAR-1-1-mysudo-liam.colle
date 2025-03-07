/*
** EPITECH PROJECT, 2025
** my_exec
** File description:
** my_sudo
*/

#include "../../include/my.h"
#include "../../include/utils.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int my_exec(char *program, char **arguments)
{
    int exec_return = FUNC_SUCCESS;

    if (program == NULL || arguments == NULL)
        return FUNC_FAILED;
    exec_return = execvp(program, arguments);
    if (exec_return != FUNC_SUCCESS)
        perror("sudo");
    return exec_return;
}
