/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** cin_utility
*/

#include "struct.h"
#include "rpg.h"

float incr_to_wait_two(int to_display)
{
    if (to_display == 7)
        return (2.4);
    if (to_display == 8)
        return (3.4);
    if (to_display == 9)
        return (5.4);
    if (to_display == 10)
        return (5.4);
    if (to_display == 11)
        return (6.4);
    if (to_display == 12)
        return (7.4);
    if (to_display == 13)
        return (6.4);
    return (4.4);
}

float increment_to_wait(int to_display)
{
    if (to_display == 1)
        return (4.4);
    if (to_display == 2)
        return (4.4);
    if (to_display == 3)
        return (3);
    if (to_display == 4)
        return (3.4);
    if (to_display == 5)
        return (3.4);
    if (to_display == 6)
        return (2.4);
    return (incr_to_wait_two(to_display));
}

void destroy_cinematic_assets(all_t *a)
{
    sfMusic_stop(a->cin->monolog);
}