/*
** EPITECH PROJECT, 2024
** my_sort_int_array
** File description:
** day 4, task 6
** my_sort_int_array.c
*/

#include <limits.h>
#include <stdio.h>
#include "my.h"
#include "utils.h"

int find_index_min(int *array, int size, int offset)
{
    int index_min = 0;
    int min = INT_MAX;

    if (array == NULL)
        return FUNC_FAILED;
    for (int i = offset; i < size; i++) {
        if (array[i] < min) {
            index_min = i;
            min = array[i];
        }
    }
    return index_min;
}

void my_sort_int_array(int *array, int size)
{
    int index_min = 0;
    int swap = 0;

    if (array == NULL || size == 0)
        return;
    for (int i = 0; i < size; i++) {
        index_min = find_index_min(array, size, i);
        swap = array[index_min];
        array[index_min] = array[i];
        array[i] = swap;
    }
}
