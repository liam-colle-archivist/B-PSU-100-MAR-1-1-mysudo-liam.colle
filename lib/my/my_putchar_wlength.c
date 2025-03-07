/*
** EPITECH PROJECT, 2024
** my_putchar_wlength
** File description:
** my_printf
*/

#include "my.h"

int my_putchar_wlength(char character)
{
    my_putchar(character);
    return 1;
}

int my_putchar_wlength_fd(char character, int fd)
{
    my_putchar_fd(character, fd);
    return 1;
}
