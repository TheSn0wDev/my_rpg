/*
** EPITECH PROJECT, 2020
** My_RPG
** File description:
** nbr_to_str.c
*/

#include <stdlib.h>
#include "my.h"
#include "../../includes/garbage_collector.h"

int get_my_int_len(int nb)
{
    int len = 0;

    if (nb == 0)
        len++;
    for (; nb > 0; nb /= 10, len++);
    return (len);
}

char *to_str(int nb)
{
    int len = get_my_int_len(nb);
    int n = len - 1;
    char *strf = my_malloc(sizeof(char) * (len + 1));

    strf[len] = 0;
    for (int i = nb; n >= 0; i /= 10, n--)
        strf[n] = i % 10 + 48;
    return (strf);
}

char *float_to_str(float nb, int point)
{
    int i_part = (int)nb;
    float f_part = nb - (float)i_part;
    char *i_str = to_str(i_part);
    char *f_str = NULL;
    char *result = NULL;

    result = my_strcat(i_str, ".");
    f_part = f_part * pow(10, point);
    f_str = to_str((int)f_part);
    i_str = my_strcat(result, f_str);
    return (i_str);
}