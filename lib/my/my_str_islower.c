/*
** EPITECH PROJECT, 2021
** C Pool Day 06
** File description:
** check if the given strings is in lowercase
*/

int my_str_islower(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z')
            i++;
        else
            return (0);
    }
    return (1);
}
