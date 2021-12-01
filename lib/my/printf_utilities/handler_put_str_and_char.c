/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** handles all the putstr and putchar
*/

#include <stdarg.h>
#include <stdlib.h>
#include "../my.h"

int handler_putchar_basic(va_list ap, char *arguments)
{
    if (ap && (arguments == NULL || arguments[0] == '#')) {
        my_putchar(va_arg(ap, int));
        return (1);
    } else {
        return (0);
    }
}

int handler_putchar_percentage(va_list ap, char *arguments)
{
    if (ap && (arguments == NULL || arguments[0] == '#')) {
        my_putchar('%');
        return (1);
    } else {
        return (0);
    }
}

int handler_putstr(va_list ap, char *arguments)
{
    if (ap && (arguments == NULL || arguments[0] == '#')) {
        my_putstr(va_arg(ap, char *));
        return (1);
    } else {
        return (0);
    }
}

int handler_showstr(va_list ap, char *arguments)
{
    if (ap && (arguments == NULL || arguments[0] == '#')) {
        my_showstr(va_arg(ap, char *));
        return (1);
    } else {
        return (0);
    }
}
