/*
** EPITECH PROJECT, 2021
** C Pool Day 05
** File description:
** power recursively
*/

static int check_max(long result)
{
    int nb = 0;
    if (result > 2147483647)
        return (0);
    nb = (int)result;
    return (nb);
}

int my_compute_power_rec(int nb, int p)
{
    long max_result = nb;
    int result = 0;

    if (p == 0)
        return (1);
    else if (p < 0)
        return (0);
    else
        max_result = max_result * my_compute_power_rec(nb, p - 1);
    result = check_max(max_result);
    return (result);
}
