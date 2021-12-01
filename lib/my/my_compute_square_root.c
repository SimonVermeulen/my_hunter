/*
** EPITECH PROJECT, 2021
** C Pool Day 05
** File description:
** returns the sqrt of a given number
*/

int my_compute_square_root(int nb)
{
    int i = 1;
    int result = 0;

    if (nb <= 0)
        return (0);
    while (result < nb && result != nb && nb != 1) {
        i++;
        result = i * i;
    }
    if (result > nb)
        return (0);
    return (i);
}
