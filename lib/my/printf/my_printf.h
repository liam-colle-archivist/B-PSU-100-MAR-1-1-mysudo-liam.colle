/*
** EPITECH PROJECT, 2024
** my_printf (Header)
** File description:
** my_printf
*/

#include <stdarg.h>

#ifndef MY_PRINTF_H
    #define MY_PRINTF_H

/*
** Prints a string `str` with potential variadic arguments `...`
** to "Standard Output" / STDOUT
**
** @note This is a `Number Compare Function`
** @param nb `int`
** @param ... `any`
** @return `int`
*/
int my_printf(char *str, ...);

#endif

#ifndef MY_PRINTF_HLP_H
    #define MY_PRINTF_HLP_H

enum DotForcing {
    NO_DOT,
    FORCE_DOT
};

int my_printf_double(char *str, va_list args, int *i);
int check_precision_length(char *str, int i);
int check_precision(char *str, int i);
int check_numeric(char chr);
int my_printf_long(char *str, va_list args, int *i);
int my_print_long_long(char *str, va_list args, int *i);
int my_print_float(float n);
int my_print_double(double n, int precision, int force_dot);
int octal_worker(int decimal, int chr_count);
int octal(int decimal);
int my_printf_long_double(char *str, va_list args, int *i);
int hexadecimal(int decimal);
int hexadecimalmin(int decimal);
int hexadecimal_worker(int decimal, int chr_count);
int hexadecimalmin_worker(int decimal, int chr_count);
int my_printf_sci(double nb, int precision, int force_dot);
int my_printf_sci_maj(double nb, int precision, int force_dot);
char my_printf_sci_worker(double *nb, int *i);
int my_printf_sci_i_worker(int *i);
int my_hash_switcher(char *str, va_list args, int *i);
int my_hash_switcher_2(char *str, va_list args, int *i);
int hexadecimal_ulong(unsigned long decimal);
int hexadecimal_ulong_worker(unsigned long decimal, int chr_count);
int my_printf_gtrucate(char *str, va_list args, int *i);
int my_print_gtrucate(double num, int precision, char chr);
int my_printf_short(char *str, va_list args, int *i);
int check_precision_mode(char *str, int i);
double my_gtruncate_round_up(double num, int precision);
int my_printf_sci_global(double nb, char *str, int *i);
int my_printf_sizet(char *str, va_list args, int *i);
int my_printf_sizet_2(char *str, va_list args, int *i);
int my_printf_long_2(char *str, va_list args, int *i);
int octal_long(long decimal);
int octal_long_worker(long decimal, int chr_count);
int octal_ll(long long decimal);
int octal_ll_worker(long long decimal, int chr_count);
int hexadecimal_long(long decimal);
int hexadecimal_long_worker(long decimal, int chr_count);
int hexadecimal_ll(long decimal);
int hexadecimal_ll_worker(long decimal, int chr_count);
int hexadecimal_min_long(long decimal);
int hexadecimal_min_long_worker(long decimal, int chr_count);
int hexadecimal_ll_min(long decimal);
int hexadecimal_ll_min_worker(long decimal, int chr_count);
int my_print_long_long_2(char *str, va_list args, int *i);
int my_printf_hash_sci_global(double nb, char *str, int *i);
int my_print_hash_gtrucate(double num, int precision, char chr);
int my_printf_hash_gtrucate(char *str, va_list args, int *i);
int my_printf_hash_double(char *str, va_list args, int *i);
int my_printf_str(char *str, va_list args, int *i);
int check_precision_str(char *str, int i);
int check_n_flag_start(char chr);
int my_printf_ptrdiff(char *str, va_list args, int *i);
int my_printf_ptrdiff_1(char *str, va_list args, int *i);

#endif
