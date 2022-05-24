/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** main.c
*/

#include "rpg.h"
#include "struct.h"

int main(int ac, char **av)
{
    if (error_handling(ac, av) == 1) {
        return (0);
    } else if (error_handling(ac, av) == 84) {
        return (84);
    }
    srand(0);
    init_rpg();
    return (0);
}