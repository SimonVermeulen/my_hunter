/*
** EPITECH PROJECT, 2021
** C Pool Day 08
** File description:
** recreate my_strdup
*/

#include <stdlib.h>

char *my_strdup(const char *s)
{
    int i = 0;
    char *s2;

    while (s[i] != '\0')
        i++;
    s2 = malloc((i * 1) + 1);

    i = 0;
    while (s[i] != '\0') {
        s2[i] = s[i];
        i++;
    }
    s2[i] = '\0';
    return (s2);
}
