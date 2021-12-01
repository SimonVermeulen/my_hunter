/*
** EPITECH PROJECT, 2021
** C Pool Day 06
** File description:
** reverse a given string
*/

static int mystrlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

static void myswap(char *a, char *b)
{
    char tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

char *my_revstr(char *str)
{
    int str_size = mystrlen(str);
    int j = str_size - 1;
    int i = 0;

    while (i != str_size / 2) {
        myswap(&str[i], &str[j]);
        i++;
        j--;
    }
    return (str);
}
