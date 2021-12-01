/*
** EPITECH PROJECT, 2021
** C Pool Day 07
** File description:
** concatenate n char of a src in dest
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int j = 0;

    while (dest[i] != '\0')
        i++;
    while (src[j] != '\0' && j != nb) {
        dest[j + i] = src[j];
        j++;
    }
    dest[i + j] = '\0';
    return (dest);
}
