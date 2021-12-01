/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** handles all the putnbr
*/

#include <stdarg.h>
#include <stdlib.h>
#include "../my.h"

int handler_put_nbr_decimal(va_list ap, char *arguments)
{
    if (ap && (arguments == NULL || arguments[0] == '#')) {
        my_put_nbr_base(va_arg(ap, int), "0123456789");
        return (1);
    } else {
        return (0);
    }
}

int handler_put_nbr_long(va_list ap, char *arguments)
{
    if (ap && (arguments == NULL || arguments[0] == '#')) {
        my_putstr("0x");
        my_put_nbr_base_long(va_arg(ap, long long), "0123456789abcdef");
        return (1);
    } else {
        return (0);
    }
}

int handler_put_unsigned_nbr(va_list ap, char *arguments)
{
    if (ap && (arguments == NULL || arguments[0] == '#')) {
        my_put_unsigned_nbr(va_arg(ap, unsigned int));
        return (1);
    } else {
        return (0);
    }
}