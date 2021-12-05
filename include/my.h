/*
** EPITECH PROJECT, 2021
** C Pool Day 09
** File description:
** includes all the prototypes of libmy
*/

#include <stdarg.h>

#ifndef MY_H_
    #define MY_H_

    #define is_number(c) (c >= '0' && c <= '9') ? 1 : 0

    #define is_printable(c) (c >= 32 && c < 127) ? 1 : 0

void my_putchar(char c);
int my_isneg(int nb);
char *my_itos(int nb);
int my_put_unsigned_nbr(unsigned int nb);
int my_put_nbr_base(int nb, char *base);
int my_put_nbr_base_long(long long nb, char *base);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
void my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int my_show_word_array(char *const *tab);
char **my_str_to_word_array(char const *str);
char *my_strdup(const char *s);
int my_get_index(char converted_char, char *str);
char *my_convert_base(int nb, char *base);
int my_printf(const char *format, ...);
int my_atoi(char const *str);

//----------------------MY_PRINTF-----------------------------

int handler_put_nbr_decimal(va_list ap, char *arguments);

int handler_put_unsigned_nbr(va_list ap, char *arguments);

int handler_put_nbr_long(va_list ap, char *arguments);

int handler_convert_base_binary(va_list ap, char *argument);

int handler_convert_base_octal(va_list ap, char *argument);

int handler_convert_base_hexa(va_list ap, char *argument);

int handler_convert_base_maj_hexa(va_list ap, char *argument);

int handler_putchar_basic(va_list ap, char *arguments);

int handler_putchar_percentage(va_list ap, char *arguments);

int handler_putstr(va_list ap, char *arguments);

int handler_showstr(va_list ap, char *arguments);

#endif
