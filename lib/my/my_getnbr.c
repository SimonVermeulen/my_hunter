/*
** EPITECH PROJECT, 2021
** C Pool Day04
** File description:
** return a number given as parameter
*/

#include <stdlib.h>

int my_compute_power_rec(int nb, int p);

static int get_number_of_minus(char const *str)
{
    int i = 0;
    int nb_minus = 0;

    if (str == NULL)
        return (0);
    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            nb_minus++;
        i++;
    }
    return (nb_minus);
}

static int skip_minplus(char const *str)
{
    int i = 0;

    while (str[i] == '-' || str[i] == '+')
        i++;
    return (i);
}

static int skip_numbers(char const *str, int nb)
{
    while (str[nb] != '\0' && str[nb] <= '9' && str[nb] >= '0')
        nb++;
    return (nb);
}

static long my_aatoi(char const *str)
{
    int nb_minplus = 0;
    int nb_numbers = 0;
    int j = 0;
    long nb = 0;

    if (str == NULL)
        return (0);
    nb_minplus = skip_minplus(str);
    nb_numbers = skip_numbers(str, nb_minplus);
    if ((nb_numbers - nb_minplus) > 10)
        return (0);
    while (nb_numbers != nb_minplus) {
        nb_numbers--;
        nb = nb + ((str[nb_numbers] - 48) * my_compute_power_rec(10, j));
        j++;
    }
    return (nb);
}

int my_getnbr(char const *str)
{
    int nb_min = get_number_of_minus(str);
    long nb = my_aatoi(str);
    int result = 0;
    int i = 0;

    if ((nb_min % 2) != 0 && nb != 0)
        nb = nb * (-1);
    i++;
    if (nb > 2147483647 || nb < -2147483648)
        return (0);
    else
        result = (int)nb;
    return (result);
}
