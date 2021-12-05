/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** main file of my_hunter
*/

#include "../include/my_hunter.h"
#include "../include/my.h"
#include <unistd.h>

int main(int ac, char **av)
{
    if (ac > 2)
        return (84);
    else if (ac == 2 && !my_strcmp(av[1], "-h")) {
        write(1, DESC_STR, 48);
        write(1, DESCT_STR_2, 41);
        return (0);
    }
    launch_game();
    return (0);
}
