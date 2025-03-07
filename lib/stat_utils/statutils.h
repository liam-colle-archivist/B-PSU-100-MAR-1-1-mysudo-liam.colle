/*
** EPITECH PROJECT, 2024
** statutils (Header)
** File description:
** libstatutils
*/

#include <sys/stat.h>

#ifndef STAT_UTILS_H
    #define STAT_UTILS_H

#endif

#ifndef STAT_UTILS_GET_H
    #define STAT_UTILS_GET_H

struct stat *stat_get(char const *file_path);
int matches_file_type(char const *file_path, int type);

#endif

#ifndef STAT_UTILS_FT_H
    #define STAT_UTILS_FT_H

enum stat_file_types {
    STAT_FT_UNKNOWN,
    STAT_FT_FILE,
    STAT_FT_FOLDER,
    STAT_FT_SYMLINK,
    STAT_FT_FIFO_PIPE,
    STAT_FT_BLOCK_DEV,
    STAT_FT_CHAR_DEV,
    STAT_FT_DEV,
    STAT_FT_SOCKET
};

int stat_obtain_file_type(__mode_t mode);
char *stat_obtain_file_type_str(__mode_t mode);
char stat_obtain_file_type_char(__mode_t mode);

#endif

#ifndef STAT_UTILS_GETSIZE_H
    #define STAT_UTILS_GETSIZE_H

long stat_get_size(char *path);

#endif

#ifndef STAT_UTILS_GETTYPE_H
    #define STAT_UTILS_GETTYPE_H

int stat_get_type(char *path);

#endif

#ifndef STAT_UTILS_GETMODE_H
    #define STAT_UTILS_GETMODE_H

unsigned int stat_get_mode(char *path);

#endif
