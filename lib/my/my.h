/*
** EPITECH PROJECT, 2024
** my
** File description:
** Header File for project
*/

#ifndef MY_H
    #define MY_H

    #define CMP_EXACT 0

#endif

// String Compare Functions
#ifndef MY_STR_CMP_H
    #define MY_STR_CMP_H

/*
** Gets the number of strings
**
** @note This is a `String Compare Function`
** @param str `const char *`
** @return `int`
*/
int my_strlen(const char *str);

/*
** Check if the string is an alphabetic string
**
** @note This is a `String Compare Function`
** @param str `const char *`
** @return `int` (boolean-like)
*/
int my_str_isalpha(const char *str);

/*
** Check if the string is a numeric string
**
** @note This is a `String Compare Function`
** @param str `const char *`
** @return `int` (boolean-like)
*/
int my_str_isnum(const char *str);

/*
** Check if the string is a lower alphabetic string
**
** @note This is a `String Compare Function`
** @param str `const char *`
** @return `int` (boolean-like)
*/
int my_str_islower(const char *str);

/*
** Check if the string is an upper alphabetic string
**
** @note This is a `String Compare Function`
** @param str `const char *`
** @return `int` (boolean-like)
*/
int my_str_isupper(const char *str);

/*
** Check if the string is an alphanumeric string
**
** @note This is a `String Compare Function`
** @param str `const char *`
** @return `int` (boolean-like)
*/
int my_str_isalphanum(const char *str);

/*
** Check if the string is a printable string
**
** @note This is a `String Compare Function`
** @param str `const char *`
** @return `int` (boolean-like)
*/
int my_str_isprintable(const char *str);

/*
** Compares the string `s1` to `s2` and checks if they house any differences
**
** @note This is a `String Compare Function`
** @param s1 `const char *`
** @param s2 `const char *`
** @return `int`
*/
int my_strcmp(const char *s1, const char *s2);

/*
** Compares the string `s1` to `s2` and checks if they house any differences
**
** Does so until it reaches "`n`" index
** @note This is a `String Compare Function`
** @param s1 `const char *`
** @param s2 `const char *`
** @param n `int`
** @return `int`
*/
int my_strncmp(const char *s1, const char *s2, int n);

/*
** Template function
**
** @note Do not use
** @param s1 `const char *`
** @param s2 `const char *`
** @return `int`
*/
int my_showmem(const char *str, int size);

/*
** Template function
**
** @note Do not use
** @param s1 `const char *`
** @param s2 `const char *`
** @return `int`
*/
int my_showstr(const char *str);

/*
** Compares the string `s1` to `s2` and checks if they house any differences
**
** @note This is a `String Compare Function`
** @param s1 `const char *`
** @param s2 `const char *`
** @return `int` (boolean-like)
*/
int my_strmatch(const char *s1, const char *s2);

/*
** Check if the character is an alphabetic character
**
** @note This is a `String Compare Function`
** @param chr `const char`
** @return `int` (boolean-like)
*/
int is_alpha(char chr);

/*
** Check if the character is an alphanumeric character
**
** @note This is a `String Compare Function`
** @param chr `const char`
** @return `int` (boolean-like)
*/
int is_alphanum(char chr);

/*
** Check if the character is a printable character
**
** @note This is a `String Compare Function`
** @param chr `const char`
** @return `int` (boolean-like)
*/
int is_printable(char chr);

/*
** Check if the character is a printable character
** (Doesn't count spaces)
**
** @note This is a `String Compare Function`
** @param chr `const char`
** @return `int` (boolean-like)
*/
int is_printable_nospace(char chr);

#endif

// String Transform Functions
#ifndef MY_STR_TRS_H
    #define MY_STR_TRS_H

/*
** Copies string content from `src` to `dest`
**
** @note This is a `String Transform Function`
** @param dest `char *`
** @param src `const char *`
** @return `char *` (non-malloc)
*/
char *my_strcpy(char *dest, const char *src);

/*
** Copies string content from `src` to `dest`
**
** Does so until it reaches "`n`" index
** @note This is a `String Transform Function`
** @param dest `char *`
** @param src `const char *`
** @param n `int`
** @return `char *` (non-malloc)
*/
char *my_strncpy(char *dest, const char *src, int n);

/*
** Reverses the string `str`
**
** @note This is a `String Transform Function`
** @param str `char *`
** @return `char *` (non-malloc)
*/
char *my_revstr(char *str);

/*
** Locates in the string `str` the presence of `to_find`
** and returns the pointer to the start of `to_find` if it's located
**
** @note This is a `String Transform Function`
** @param str `char *`
** @param to_find `const char *`
** @return `char *` (non-malloc)
*/
char *my_strstr(char *str, const char *to_find);

/*
** Replaces all alphanumeric characters with their uppercase candidate
**
** @note This is a `String Transform Function`
** @param str `char *`
** @return `char *` (non-malloc)
*/
char *my_strupcase(char *str);

/*
** Replaces all alphanumeric characters with their lowercase candidate
**
** @note This is a `String Transform Function`
** @param str `char *`
** @return `char *` (non-malloc)
*/
char *my_strlowcase(char *str);

/*
** Replaces all alphanumeric at the start of a word
** with their uppercase candidate
**
** @note This is a `String Transform Function`
** @param str `char *`
** @return `char *` (non-malloc)
*/
char *my_strcapitalize(char *str);

/*
** Concatenates `dest` into `src`
**
** @note This is a `String Transform Function`
** @param dest `char *`
** @param src `const char *`
** @return `char *` (non-malloc)
*/
char *my_strcat(char *dest, const char *src);

/*
** Concatenates `dest` into `src` for `nb` characters
**
** @note This is a `String Transform Function`
** @param dest `char *`
** @param src `const char *`
** @param nb `int`
** @return `char *` (non-malloc)
*/
char *my_strncat(char *dest, const char *src, int nb);

/*
** Copies string content from `src` to a malloc'd string
**
** @note This is a `String Transform Function`
** @param src `const char *`
** @return `char *` (malloc'd)
*/
char *my_strdup(const char *src);

/*
** Concat's string content between `src_1` and `src_2`
** and sends them to a malloc'd string
**
** @note This is a `String Transform Function`
** @param src `const char *`
** @return `char *` (malloc'd)
*/
char *my_strcdup(const char *src_1, const char *src_2);

/*
** Converts the string `str` into a board of sub-strings
** each containing a word
**
** @note This is a `String Transform Function`
** @param str `const char *`
** @param count_lr `int` (boolean-like)
** @return `char **` (malloc'd)
*/
char **my_str_to_word_array(char const *str, int count_lr);

/*
** Converts an int to a malloc'd string
**
** @note This is a `String Transform Function`
** @param number `int`
** @return `char *` (malloc'd)
*/
char *my_int_to_str(int number);

#endif

// String Printing Functions
#ifndef MY_STR_PRT_H
    #define MY_STR_PRT_H

/*
** Prints a character `character` into "Standard Output" / STDOUT
**
** Returns the character code of the printed character
**
** @note This is a `String Printing Function`
** @param character `char`
** @return `int`
*/
int my_putchar(char character);

/*
** Prints a character `character` into file descriptor `fd`
**
** Returns the character code of the printed character
**
** @note This is a `String Printing Function`
** @param character `char`
** @param fd `int`
** @return `int`
*/
int my_putchar_fd(char character, int fd);

/*
** Prints a character into "Standard Output" / STDOUT
**
** Returns the number of printed characters
**
** @note This is a `String Printing Function`
** @param character `char`
** @return `int`
*/
int my_putchar_wlength(char character);

/*
** Prints a character `character` into file descriptor `fd`
**
** Returns the number of printed characters
** @note This is a `String Printing Function`
** @param character `char`
** @param fd `int`
** @return `int`
*/
int my_putchar_wlength_fd(char character, int fd);

/*
** Prints a string `str` into "Standard Output" / STDOUT
**
** Returns the number of printed characters
**
** @note This is a `String Printing Function`
** @param str `const char *`
** @return `int`
*/
int my_putstr(const char *str);

/*
** Prints a string `str` into "Standard Output" / STDOUT
**
** Only print `max` characters
**
** Returns the number of printed characters
**
** @note This is a `String Printing Function`
** @param str `const char *`
** @param max `int`
** @return `int`
*/
int my_putstr_custlen(const char *str, int max);

/*
** Prints a string `str` into file descriptor `fd`
**
** Returns the number of printed characters
**
** @note This is a `String Printing Function`
** @param str `const char *`
** @param fd `int`
** @return `int`
*/
int my_putstr_fd(const char *str, int fd);

#endif

// Number Printing Functions
#ifndef MY_NUM_PRT_H
    #define MY_NUM_PRT_H

/*
** Prints a number `nb` into "Standard Output" / STDOUT
**
** Returns the number printed
**
** @note This is a `Number Printing Function`
** @param nb `int`
** @return `int`
*/
int my_put_nbr(int nb);

/*
** Prints a number `nb` into "Standard Output" / STDOUT recursively
**
** @note This is a `Number Printing Function`
** @param nb `int`
** @return `NULL`
*/
void my_put_nbr_worker(long nb);

/*
** Prints a long number `nb` into "Standard Output" / STDOUT
**
** Returns the number of characters printed
**
** @note This is a `Number Printing Function`
** @param nb `long`
** @return `int`
*/
int my_put_long_retchrn(long nb);

/*
** Prints a number `nb` into "Standard Output" / STDOUT
**
** Returns the number of characters printed
**
** @note This is a `Number Printing Function`
** @param nb `int`
** @return `int`
*/
int my_put_nbr_retchrn(int nb);

/*
** Prints a long number `nb` into "Standard Output" / STDOUT
**
** Returns the number printed
**
** @note This is a `Number Printing Function`
** @param nb `long`
** @return `long`
*/
long my_put_long_long(long nb);

/*
** Prints a long number `nb` into "Standard Output" / STDOUT
**
** @note This is a `Number Printing Function`
** @param nb `long`
** @return `NULL`
*/
void my_put_long_long_worker(long nb);

/*
** Prints a long double number `nb` into "Standard Output" / STDOUT
**
** Prints with a certain precision
**
** @note This is a `Number Printing Function`
** @param nb `long double`
** @param int `precision`
** @return `NULL`
*/
int my_print_long_double(long double n, int precision);

/*
** Prints a short number `nb` into "Standard Output" / STDOUT recursively
**
** @note This is a `Number Printing Function`
** @param nb `short`
** @return `NULL`
*/
void my_put_short_worker(short nb);

/*
** Prints a short number `nb` into "Standard Output" / STDOUT
**
** Returns the number printed
**
** @note This is a `Number Printing Function`
** @param nb `short`
** @return `short`
*/
short my_put_short(short nb);

/*
** Prints a short number `nb` into "Standard Output" / STDOUT
**
** Returns the number of characters printed
**
** @note This is a `Number Printing Function`
** @param nb `short`
** @return `int`
*/
int my_put_short_retchrn(short nb);

/*
** Prints an unsigned short number `nb` into "Standard Output" / STDOUT
**
** Returns the number of characters printed
**
** @note This is a `Number Printing Function`
** @param nb `unsigned short`
** @return `int`
*/
int my_put_short_u_retchrn(unsigned short nb);

/*
** Prints an unsigned short number `nb` into "Standard Output" / STDOUT
** recursively
**
** Returns the number of characters printed
**
** @note This is a `Number Printing Function`
** @param nb `unsigned short`
** @return `int`
*/
void my_put_short_u_worker(unsigned short nb);

/*
** Prints an unsigned short number `nb` into "Standard Output" / STDOUT
**
** @note This is a `Number Printing Function`
** @param nb `unsigned short`
** @return `unsigned short`
*/
unsigned short my_put_short_u(unsigned short nb);

/*
** Prints an unsigned short number `nb` into "Standard Output" / STDOUT
** recursively
**
** @note This is a `Number Printing Function`
** @param nb `short`
** @return `NULL`
*/
void my_put_nbr_worker_lr(long nb);

/*
** Prints an unsigned short number `nb` into "Standard Output" / STDOUT
** recursively
**
** @note This is a `Number Printing Function`
** @param nb `short`
** @return `NULL`
*/
int my_put_nbr_lr(int nb);

/*
** Prints an unsigned long long number `nb` into "Standard Output"
** / STDOUT recursively
**
** Returns the number of characters printed
**
** @note This is a `Number Printing Function`
** @param nb `unsigned long long`
** @return `int`
*/
int my_put_llu_rc(unsigned long long nb);

/*
** Prints an unsigned long long number `nb` into "Standard Output"
** / STDOUT
**
** Return the printed number
**
** @note This is a `Number Printing Function`
** @param nb `unsigned long long`
** @return `long`
*/
long my_put_llu(unsigned long long nb);

/*
** Prints an unsigned long long number `nb` into "Standard Output"
** / STDOUT recursively
**
** @note This is a `Number Printing Function`
** @param nb `unsigned long long`
** @return `NULL`
*/
void my_put_llu_worker(unsigned long long nb);

/*
** Prints an unsigned short number `nb` into "Standard Output" / STDOUT
** recursively
**
** Returns the printed number
**
** @note This is a `Number Printing Function`
** @param nb `unsigned int`
** @return `unsigned int`
*/
unsigned int my_put_nbr_unsn(unsigned int nb);

/*
** Prints an unsigned short number `nb` into "Standard Output" / STDOUT
** recursively
**
** @note This is a `Number Printing Function`
** @param nb `unsigned int`
** @return `NULL`
*/
void my_put_nbr_unsn_worker(unsigned int nb);

/*
** Prints an unsigned short number `nb` into "Standard Output" / STDOUT
** recursively
**
** Returns the number of printed characters
**
** @note This is a `Number Printing Function`
** @param nb `unsigned int`
** @return `unsigned int`
*/
int my_put_nbr_un_retchrn(unsigned int nb);

/*
** Prints a long number `nb` into "Standard Output" / STDOUT
**
** Returns the printed number
**
** @note This is a `Number Printing Function`
** @param nb `long`
** @return `long`
*/
long my_put_long(long nb);

/*
** Prints a long number `nb` into "Standard Output" / STDOUT recursively
**
** @note This is a `Number Printing Function`
** @param nb `long`
** @return `NULL`
*/
void my_put_long_worker(long nb);

/*
** Prints a long long number `nb` into "Standard Output" / STDOUT
**
** Returns the number of characters printed
**
** @note This is a `Number Printing Function`
** @param nb `long long`
** @return `int`
*/
int my_put_long_long_rc(long long nb);

/*
** Prints a float number `n` into "Standard Output" / STDOUT
**
** Returns the number of characters printed
**
** @note This is a `Number Printing Function`
** @param n `float`
** @return `int`
*/
int my_print_float(float n);

/*
** Prints a double number `n` into "Standard Output" / STDOUT
**
** Returns the number of characters printed
**
** @note This is a `Number Printing Function`
** @param n `double`
** @param precision `int`
** @param force_dot `int` (boolean-like)
** @return `int`
*/
int my_print_double(double n, int precision, int force_dot);

/*
** Prints `zeros` number of zeroes into "Standard Output" / STDOUT
**
** Returns the number of characters printed
**
** @note This is a `Number Printing Function`
** @param zeros `int`
** @return `int`
*/
int my_print_zeros(int zeros);

#endif

// Get Functions
#ifndef MY_GET_H
    #define MY_GET_H

/*
** Obtains a number from a string `str`
**
** Returns the interpreted number from the string
**
** @note This is a `Get Function`
** @param str `const char *`
** @return `int`
*/
int my_getnbr(const char *str);

/*
** Obtains the number of decimals of a long long number
** `nb` recursively
**
** Returns the number of deciamls of `nb`
**
** @note This is a `Number Printing Function`
** @param nb `long long`
** @param count `int`
** @return `int`
*/
int my_get_nbr_decimals_ll(long long nb, int count);

/*
** Obtains the number of decimals of a short number
** `nb` recursively
**
** Returns the number of deciamls of `nb`
**
** @note This is a `Get Function`
** @param nb `short`
** @param count `int`
** @return `int`
*/
int my_get_nbr_decimals_s(short nb, int count);

/*
** Obtains the number of decimals of a number
** `nb` recursively
**
** Returns the number of deciamls of `nb`
**
** @note This is a `Get Function`
** @param nb `long`
** @param count `int`
** @return `int`
*/
int my_get_nbr_decimals(long nb, int count);

/*
** Obtains the number of decimals of an unsigned number
** `nb` recursively
**
** Returns the number of deciamls of `nb`
**
** @note This is a `Get Function`
** @param nb `unsigned int`
** @param count `int`
** @return `int`
*/
int my_get_nbr_decimals_u(unsigned int nb, int count);

/*
** Obtains the number of decimals of an unsigned
** long long number `nb` recursively
**
** Returns the number of deciamls of `nb`
**
** @note This is a `Get Function`
** @param nb `unsigned long long`
** @param count `int`
** @return `int`
*/
int my_get_nbr_decimals_ull(unsigned long long nb, int count);

/*
** Obtains the number of decimals of an unsigned
** short number `nb` recursively
**
** Returns the number of deciamls of `nb`
**
** @note This is a `Get Function`
** @param nb `unsigned short`
** @param count `int`
** @return `int`
*/
int my_get_nbr_decimals_uns(unsigned short nb, int count);

#endif

// Array Sorting Functions
#ifndef MY_ARR_SORT_H
    #define MY_ARR_SORT_H

/*
** Sorts a list of ints in alpha-numeric order
** using bubble sort
**
** @note This is an `Array Sorting Function`
** @param array `int *`
** @param size `int`
** @return `NULL`
*/
void my_sort_int_array(int *array, int size);

/*
** Obtains the index of the lowest number in an array
**
** Returns an index
**
** @note This is an `Array Sorting Function`
** @param array `int *`
** @param size `int`
** @param offset `int`
** @return `int`
*/
int find_index_min(int *array, int size, int offset);

#endif

// Number Compare Function
#ifndef MY_NUM_CMP_H
    #define MY_NUM_CMP_H

/*
** Prints to "Standard Output" / STDOUT if the
** number `nb` is positive or negative
**
** @note This is a `Number Compare Function`
** @param nb `int`
** @return `int`
*/
int my_isneg(int nb);

/*
** Returns if the number `nb` is a prime
**
** @note This is a `Number Compare Function`
** @param nb `int`
** @return `int`
*/
int my_is_prime(int nb);

#endif

// Number Functions
#ifndef MY_NUM_H
    #define MY_NUM_H

/*
** Template function
**
** @note Do not use
** @param nb `int`
** @return `int`
*/
int my_find_prime_sup(int nb);

/*
** Returns `nb` power of `p` recursively
**
** @note This is a `Number Function`
** @param nb `int`
** @param p `int`
** @return `int`
*/
int my_compute_power_rec(int nb, int p);

/*
** Returns `a` power of `n`
**
** @note This is a `Number Function`
** @param a `int`
** @param n `int`
** @return `long`
*/
long my_pow(int a, int n);

/*
** Returns the square root of `nb`
**
** @note This is a `Number Function`
** @param nb `int`
** @return `int`
*/
int my_compute_square_root(int nb);

/*
** Returns a number of zeroes after the dot of `n`
** with a precision of `precision`
**
** @note This is a `Number Function`
** @param n `double`
** @param precision `int`
** @return `int`
*/
int my_count_pre_zeros(double n, int precision);

/*
** Returns a number of zeroes after the dot of `n`
** with a precision of `precision`
**
** @note This is a `Number Function`
** @param n `long double`
** @param precision `int`
** @return `int`
*/
int my_count_pre_zeros_double(long double n, int precision);

/*
** Returns double `nb` power of `p`
**
** @note This is a `Number Function`
** @param n `double`
** @param p `int`
** @return `int`
*/
int my_power_double_rec(double nb, int p);

#endif

// Pointer Functions
#ifndef MY_PTR_H
    #define MY_PTR_H

/*
** Swaps the contents of numbers `a` and `b`
**
** @note This is a `Pointer Function`
** @param nb `int`
** @return `int`
*/
void my_swap(int *a, int *b);

/*
** Obtains the length of a board
**
** @note This is a `Pointer Function`
** @param tab `const void **`
** @return `int`
*/
int my_tablen(const void **tab);

/*
** Frees the malloc'd contents of a board
**
** @note This is a `Pointer Function`
** @param tab `void **`
** @return `int`
*/
int my_tabfree(void **tab);

#endif
