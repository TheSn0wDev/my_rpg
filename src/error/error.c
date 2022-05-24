/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** error handling
*/

#include "rpg.h"

int error_handling(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        print_help();
        return (1);
    }
    if (ac != 1)
        return (84);
    return (0);
}