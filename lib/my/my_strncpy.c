/*
** EPITECH PROJECT, 2021
** C Pool Day 06
** File description:
** copy n char of a given string
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (i != n) {
        if (src[i] != '\0')
            dest[i] = src[i];
        else
            dest[i] = '\0';
        i++;
    }
    return (dest);
}
