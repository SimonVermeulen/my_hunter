/*
** EPITECH PROJECT, 2021
** C Pool Day 06
** File description:
** capitalizes the first letter of each word in a given string
*/

char *my_strlowcase(char *str);

static int is_digit(char c)
{
    if (c >= '1' && c <= '9')
        return (1);
    return (0);
}

static int is_alpha(char c)
{
    if (c >= 'a' && c <= 'z')
        return (1);
    return (0);
}

static int is_digit_or_alpha(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (0);
    if (!is_alpha(c) && !is_digit(c))
        return (1);
    else
        return (0);
}

char *my_strcapitalize(char *str)
{
    int i = 0;
    int last_char_space = 1;

    my_strlowcase(str);
    while (str[i] != '\0') {
        if (last_char_space == 1 && str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
            last_char_space = 0;
        }
        i++;
        last_char_space = is_digit_or_alpha(str[i - 1]);
    }
    return (str);
}
