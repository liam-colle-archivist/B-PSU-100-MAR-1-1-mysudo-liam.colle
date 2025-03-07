/*
** EPITECH PROJECT, 2024
** stat_get_type
** File description:
** libstatutils
*/

#include <stdio.h>
#include <sys/stat.h>
#include "statutils.h"
#include "utils.h"

int stat_obtain_file_type(__mode_t mode)
{
    switch (mode &__S_IFMT) {
        case __S_IFBLK:
            return STAT_FT_BLOCK_DEV;
        case __S_IFCHR:
            return STAT_FT_CHAR_DEV;
        case __S_IFDIR:
            return STAT_FT_FOLDER;
        case __S_IFIFO:
            return STAT_FT_FIFO_PIPE;
        case __S_IFLNK:
            return STAT_FT_SYMLINK;
        case __S_IFREG:
            return STAT_FT_FILE;
        case __S_IFSOCK:
            return STAT_FT_SOCKET;
        default:
            return STAT_FT_UNKNOWN;
    }
}

char *stat_obtain_file_type_str(__mode_t mode)
{
    int type = stat_obtain_file_type(mode);

    switch (type) {
        case STAT_FT_BLOCK_DEV:
            return "Block Device";
        case STAT_FT_CHAR_DEV:
            return "Character Device";
        case STAT_FT_FOLDER:
            return "Directory";
        case STAT_FT_FIFO_PIPE:
            return "FIFO / Pipe";
        case STAT_FT_SYMLINK:
            return "Symbolic Link";
        case STAT_FT_FILE:
            return "Regular File";
        case STAT_FT_SOCKET:
            return "Socket";
        default:
            return "Unknown";
    }
}

char stat_obtain_file_type_char(__mode_t mode)
{
    int type = stat_obtain_file_type(mode);

    switch (type) {
        case STAT_FT_BLOCK_DEV:
            return 'b';
        case STAT_FT_CHAR_DEV:
            return 'c';
        case STAT_FT_FOLDER:
            return 'd';
        case STAT_FT_FIFO_PIPE:
            return 'p';
        case STAT_FT_SYMLINK:
            return 'l';
        case STAT_FT_FILE:
            return '-';
        case STAT_FT_SOCKET:
            return 's';
        default:
            return '?';
    }
}

int stat_get_type(char *path)
{
    struct stat st_props;

    if (path == NULL)
        return FUNC_FAILED;
    if (stat(path, &st_props) == FUNC_FAILED)
        return FUNC_FAILED;
    return stat_obtain_file_type(st_props.st_mode);
}
