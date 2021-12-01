/*
** EPITECH PROJECT, 2021
** C Pool Day 04
** File description:
** returns the number of character of a string
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}
