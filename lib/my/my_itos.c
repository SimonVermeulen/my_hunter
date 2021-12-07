/*
** EPITECH PROJECT, 2021
** lib_my
** File description:
** converts and print a decimal int to a given base
*/

#include "my.h"

char *my_itos(int nb)
{
    char *str = my_convert_base(nb, "0123456789");
    return (str);
}
