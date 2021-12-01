/*
** EPITECH PROJECT, 2021
** C Pool Day 06
** File description:
** find a substring in a string
*/

static int mystrle(char const *str)
{
    int i = 0;

    if (!str)
        return (0);
    while (str[i] != '\0')
        i++;
    return (i);
}

static int check_to_find(char *str, char const *to_find, int i)
{
    int j = 0;
    int k = 0;
    int first = 0;

    if (str[i] == to_find[j]) {
        k = i;
        first = i;
        while (str[k] == to_find[j] && to_find[j] != '\0') {
            k++;
            j++;
        }
    }
    return (j);
}

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int j = 0;
    int size = mystrle(to_find);

    if (size == 0)
        return (str);
    while (str[i] != '\0' && j != size) {
        j = check_to_find(str, to_find, i);
        i++;
    }
    i--;
    if (j == size)
        return (&str[i]);
    return (0);
}
