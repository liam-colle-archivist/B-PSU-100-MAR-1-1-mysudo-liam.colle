/*
** EPITECH PROJECT, 2025
** parser (passwd)
** File description:
** my_sudo
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../include/parser.h"
#include "../../include/my.h"
#include "../../include/my_group.h"
#include "../../include/statutils.h"
#include "../../include/utils.h"

static group_t *copy_group(group_t *group)
{
    group_t *new_group = NULL;

    if (group == NULL)
        return NULL;
    new_group = malloc(sizeof(group_t));
    if (new_group == NULL)
        return NULL;
    new_group->name = my_strdup(group->name);
    new_group->pwdp = my_strdup(group->pwdp);
    new_group->gid = group->gid;
    new_group->users = my_strdup(group->users);
    clear_group(group);
    return new_group;
}

static char *get_group_buffer(FILE *file, int size)
{
    char *buffer = NULL;

    if (file == NULL || size == FUNC_FAILED)
        return NULL;
    buffer = malloc(sizeof(char) * size);
    if (buffer == NULL) {
        fclose(file);
        return NULL;
    }
    memset(buffer, '\0', size);
    return buffer;
}

static int get_line_data(char *buffer, group_t *grp)
{
    char *temp_buffer = buffer;
    char *group_data[4];

    if (buffer == NULL || grp == NULL)
        return FUNC_FAILED;
    temp_buffer = strtok(temp_buffer, ":\n");
    for (int i = 0; i < 4; i++) {
        group_data[i] = temp_buffer == NULL ? NULL : my_strdup(temp_buffer);
        temp_buffer = strtok(NULL, ":\n");
    }
    *grp = (group_t) {group_data[0], group_data[1],
        group_data[2] == NULL ? FUNC_FAILED : atoi(group_data[2]),
        group_data[3]};
    free(group_data[2]);
    return FUNC_SUCCESS;
}

static int check_for_occurence(char *buffer, void *ref, group_t *grp,
    bool_t (*cmp_f)(group_t *, void *))
{
    if (buffer == NULL || ref == NULL || grp == NULL) {
        if (grp != NULL)
            clear_group(grp);
        return FUNC_FAILED;
    }
    if (cmp_f(grp, ref) == TRUE) {
        free(buffer);
        return FUNC_SUCCESS;
    }
    clear_group(grp);
    return FUNC_SEMFAIL;
}

group_t *get_group(void *ref, bool_t (*cmp_f)(group_t *, void *))
{
    FILE *file = fopen(GROUP_FILE, "r");
    int size = stat_get_size(GROUP_FILE);
    group_t grp = {NULL, NULL, -1, NULL};
    char *buffer = get_group_buffer(file, size);

    if (ref == NULL || size == FUNC_FAILED || buffer == NULL) {
        free(buffer);
        return NULL;
    }
    while (fgets(buffer, size, file) != NULL) {
        if (get_line_data(buffer, &grp) == FUNC_FAILED)
            continue;
        if (check_for_occurence(buffer, ref, &grp, cmp_f) == FUNC_SUCCESS) {
            fclose(file);
            return copy_group(&grp);
        }
    }
    fclose(file);
    free(buffer);
    return NULL;
}
