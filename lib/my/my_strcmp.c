/*
** EPITECH PROJECT, 2021
** C Pool Day 06
** File description:
** compares two given strings
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int result = 0;

    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
        i++;
    result = s1[i] - s2[i];
    return (result);
}
