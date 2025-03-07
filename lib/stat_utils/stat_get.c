/*
** EPITECH PROJECT, 2024
** stat_get
** File description:
** libstatutils
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "statutils.h"
#include "utils.h"

struct stat *stat_get(char const *file_path)
{
    struct stat *st_props = NULL;

    if (file_path == NULL)
        return NULL;
    st_props = malloc(sizeof(struct stat));
    if (stat(file_path, st_props) == FUNC_FAILED) {
        free(st_props);
        return NULL;
    }
    return st_props;
}

int matches_file_type(char const *file_path, int type)
{
    int file_type = 0;
    struct stat st_props;

    if (file_path == NULL)
        return FUNC_FAILED;
    if (stat(file_path, &st_props) == FUNC_FAILED) {
        return FUNC_FAILED;
    }
    file_type = stat_obtain_file_type(st_props.st_mode);
    if (file_type != type)
        return FALSE;
    return TRUE;
}
