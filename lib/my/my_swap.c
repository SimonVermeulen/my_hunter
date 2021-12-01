/*
** EPITECH PROJECT, 2021
** C Pool Day04
** File description:
** swap the content of two integers
*/

void    my_swap(int *a, int *b)
{
    int tmp = 0;

    tmp = *a;
    *a = *b;
    *b = tmp;
}
