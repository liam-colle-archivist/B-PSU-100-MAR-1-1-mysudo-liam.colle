/*
** EPITECH PROJECT, 2024
** switcher (Header)
** File description:
** my_printf
*/

#include <stdarg.h>

#ifndef MY_PRINTF_SWITCHER_H
    #define MY_PRINTF_SWITCHER_H
int my_printf_printarg_1(char *str, va_list args, int *i, int *chr_count);
int my_printf_printarg_2(char *str, va_list args, int *i, int *chr_count);
int my_printf_printarg_3(char *str, va_list args, int *i, int *chr_count);
int my_printf_printarg_4(char *str, va_list args, int *i, int *chr_count);
int my_switch_is_numeral(char *str, va_list args, int *i, int *c_count);
int my_switch_is_numeral_hashtag(char *str, va_list args, int *i);
#endif
