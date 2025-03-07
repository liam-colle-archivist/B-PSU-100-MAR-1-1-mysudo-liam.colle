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
#include "../../include/my_shadow.h"
#include "../../include/statutils.h"
#include "../../include/utils.h"

static shadow_t *copy_shadow(shadow_t *shadow)
{
    shadow_t *new_shadow = NULL;

    if (shadow == NULL)
        return NULL;
    new_shadow = malloc(sizeof(shadow_t));
    if (new_shadow == NULL)
        return NULL;
    new_shadow->namp = my_strdup(shadow->namp);
    new_shadow->pwdp = my_strdup(shadow->pwdp);
    new_shadow->lstchg = 0;
    new_shadow->min = 0;
    new_shadow->max = 0;
    new_shadow->warn = 0;
    new_shadow->inact = 0;
    new_shadow->expire = 0;
    new_shadow->flag = 0;
    return new_shadow;
}

static char *get_shadow_buffer(FILE *file, int size)
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

static int get_line_data(char *buffer, shadow_t *shdw)
{
    char *temp_buffer = buffer;
    char *shadow_data[9];

    if (buffer == NULL || shdw == NULL)
        return FUNC_FAILED;
    temp_buffer = strtok(temp_buffer, ":\n");
    for (int i = 0; i < 9; i++) {
        shadow_data[i] = temp_buffer == NULL ? NULL : my_strdup(temp_buffer);
        temp_buffer = strtok(NULL, ":\n");
    }
    *shdw = (shadow_t) {shadow_data[0], shadow_data[1],
        shadow_data[2] == NULL ? FUNC_FAILED : atol(shadow_data[2]),
        shadow_data[3] == NULL ? FUNC_FAILED : atol(shadow_data[3]),
        shadow_data[4] == NULL ? FUNC_FAILED : atol(shadow_data[4]),
        shadow_data[5] == NULL ? FUNC_FAILED : atol(shadow_data[5]),
        shadow_data[6] == NULL ? FUNC_FAILED : atol(shadow_data[6]),
        shadow_data[7] == NULL ? FUNC_FAILED : atol(shadow_data[7]),
        shadow_data[8] == NULL ? FUNC_FAILED : atol(shadow_data[8])};
    return FUNC_SUCCESS;
}

static int check_for_occurence(char *buffer, void *ref, shadow_t *shdw,
    bool_t (*cmp_f)(shadow_t *, void *))
{
    if (buffer == NULL || ref == NULL || shdw == NULL) {
        if (shdw != NULL)
            clear_shadow(shdw);
        return FUNC_FAILED;
    }
    if (cmp_f(shdw, ref) == TRUE) {
        free(buffer);
        return FUNC_SUCCESS;
    }
    clear_shadow(shdw);
    return FUNC_SEMFAIL;
}

shadow_t *get_shadow(void *ref, bool_t (*cmp_f)(shadow_t *, void *))
{
    FILE *file = fopen(SHADOW_FILE, "r");
    int size = stat_get_size(SHADOW_FILE);
    shadow_t shdw = {NULL, NULL, -1, -1, -1, -1, -1, -1, -1};
    char *buffer = get_shadow_buffer(file, size);

    if (ref == NULL || size == FUNC_FAILED || buffer == NULL) {
        free(buffer);
        return NULL;
    }
    while (fgets(buffer, size, file) != NULL) {
        if (get_line_data(buffer, &shdw) == FUNC_FAILED)
            continue;
        if (check_for_occurence(buffer, ref, &shdw, cmp_f) == FUNC_SUCCESS) {
            fclose(file);
            return copy_shadow(&shdw);
        }
    }
    fclose(file);
    free(buffer);
    return NULL;
}
