/*
** EPITECH PROJECT, 2024
** usage
** File description:
** libusage
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include "usage.h"
#include "utils.h"

static int read_usage(FILE *file, char **stream, int size)
{
    if (file == NULL || size == FUNC_FAILED || stream == NULL)
        return FUNC_FAILED;
    *stream = malloc(sizeof(char) * size);
    if (*stream == NULL)
        return FUNC_FAILED;
    if (fread(*stream, sizeof(char), size + 1, file) <= 0)
        return FUNC_FAILED;
    return FUNC_SUCCESS;
}

static int get_filesize(char *path)
{
    struct stat st_props;

    if (path == NULL)
        return FUNC_FAILED;
    if (stat(path, &st_props) == FUNC_FAILED)
        return FUNC_FAILED;
    return st_props.st_size;
}

int usage_show(char *path)
{
    FILE *file = fopen(path, "r");
    int size = get_filesize(path);
    char *stream = NULL;

    if (file == NULL)
        return FUNC_FAILED;
    if (size == FUNC_FAILED)
        return FUNC_FAILED;
    if (read_usage(file, &stream, size) == FUNC_FAILED) {
        fclose(file);
        return FUNC_FAILED;
    }
    write(STDOUT, stream, size);
    free(stream);
    if (fclose(file) == FUNC_FAILED)
        return FUNC_FAILED;
    return FUNC_SUCCESS;
}
