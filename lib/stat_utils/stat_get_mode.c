/*
** EPITECH PROJECT, 2024
** stat_get_size
** File description:
** libmyradar
*/

#include <stdio.h>
#include <sys/stat.h>
#include "statutils.h"
#include "utils.h"

unsigned int stat_get_mode(char *path)
{
    struct stat st_props;

    if (path == NULL)
        return FUNC_FAILED;
    if (stat(path, &st_props) == FUNC_FAILED)
        return FUNC_FAILED;
    return st_props.st_mode;
}
