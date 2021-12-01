/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** my_atoi
*/

#include "my.h"

int my_atoi(char const *str)
{
    int result = 0;
    int power = 0;

    for (; is_number(str[power]); power++);
    for (int i = 0; str[i] != '\0' && is_number(str[i]); i++, power--)
        result += (str[i] - 48) * my_compute_power_rec(10, power - 1);
    return (result);
}
