/*
** EPITECH PROJECT, 2021
** C Pool Day03
** File description:
** check if an int is positive or negative
*/

#include <unistd.h>

void my_putchar(char c);

int my_isneg(int n)
{
    if (n < 0)
        my_putchar('N');
    else
        my_putchar('P');
    return (0);
}
