/*
** EPITECH PROJECT, 2021
** C Pool Day 05
** File description:
** returns 1 if the number is prime
*/

int my_is_prime(int nb)
{
    int i = 1;

    if (nb <= 1)
        return (0);
    while (i < nb - 1) {
        i++;
        if (nb % i == 0)
            return (0);
    }
    return (1);
}
