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
#include "../../include/my_passwd.h"
#include "../../include/statutils.h"
#include "../../include/utils.h"

static passwd_t *copy_passwd(passwd_t *passwd)
{
    passwd_t *new_passwd = NULL;

    if (passwd == NULL)
        return NULL;
    new_passwd = malloc(sizeof(passwd_t));
    if (new_passwd == NULL)
        return NULL;
    new_passwd->user = my_strdup(passwd->user);
    new_passwd->password = my_strdup(passwd->password);
    new_passwd->uid = passwd->uid;
    new_passwd->gid = passwd->gid;
    new_passwd->description = my_strdup(passwd->description);
    new_passwd->home = my_strdup(passwd->home);
    new_passwd->default_shell = my_strdup(passwd->default_shell);
    clear_passwd(passwd);
    return new_passwd;
}

static char *get_pwds_buffer(FILE *file, int size)
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

static int get_line_data(char *buffer, passwd_t *pwds)
{
    char *temp_buffer = buffer;
    char *passwd_data[7];

    if (buffer == NULL || pwds == NULL)
        return FUNC_FAILED;
    temp_buffer = strtok(temp_buffer, ":\n");
    for (int i = 0; i < 7; i++) {
        passwd_data[i] = temp_buffer == NULL ? NULL : my_strdup(temp_buffer);
        temp_buffer = strtok(NULL, ":\n");
    }
    *pwds = (passwd_t) {passwd_data[0], passwd_data[1],
        passwd_data[2] == NULL ? FUNC_FAILED : atoi(passwd_data[2]),
            passwd_data[3] == NULL ? FUNC_FAILED : atoi(passwd_data[3]),
                passwd_data[4], passwd_data[5], passwd_data[6]};
    free(passwd_data[2]);
    free(passwd_data[3]);
    return FUNC_SUCCESS;
}

static int check_for_occurence(char *buffer, void *ref, passwd_t *pwds,
    bool_t (*cmp_f)(passwd_t *, void *))
{
    if (buffer == NULL || ref == NULL || pwds == NULL) {
        if (pwds != NULL)
            clear_passwd(pwds);
        return FUNC_FAILED;
    }
    if (cmp_f(pwds, ref) == TRUE) {
        free(buffer);
        return FUNC_SUCCESS;
    }
    clear_passwd(pwds);
    return FUNC_SEMFAIL;
}

passwd_t *get_passwd(void *ref, bool_t (*cmp_f)(passwd_t *, void *))
{
    FILE *file = fopen(PASSWD_FILE, "r");
    int size = stat_get_size(PASSWD_FILE);
    passwd_t pwds = {NULL, NULL, -1, -1, NULL, NULL, NULL};
    char *buffer = get_pwds_buffer(file, size);

    if (ref == NULL || size == FUNC_FAILED || buffer == NULL) {
        free(buffer);
        return NULL;
    }
    while (fgets(buffer, size, file) != NULL) {
        if (get_line_data(buffer, &pwds) == FUNC_FAILED)
            continue;
        if (check_for_occurence(buffer, ref, &pwds, cmp_f) == FUNC_SUCCESS) {
            fclose(file);
            return copy_passwd(&pwds);
        }
    }
    fclose(file);
    free(buffer);
    return NULL;
}
