/*
** EPITECH PROJECT, 2024
** my_putchar
** File description:
** day 4, task 0
** my_putchar.c
*/

#include <unistd.h>
#include "utils.h"

int my_putchar(char character)
{
    write(STDOUT, &character, sizeof(character));
    return character;
}

int my_putchar_fd(char character, int fd)
{
    write(fd, &character, sizeof(character));
    return character;
}
