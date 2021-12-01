/*
** EPITECH PROJECT, 2021
** C Pool Day 06
** File description:
** check if a string is printable or not
*/

int my_str_isprintable(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 33 && str[i] <= 127)
            i++;
        else
            return (0);
    }
    return (1);
}
