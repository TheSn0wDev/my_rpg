/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-clement.ozor
** File description:
** my_strdup
*/

#include "my.h"
#include "../../includes/garbage_collector.h"
#include <stdlib.h>

char *my_strdup(char *str)
{
    int len;
    char *clone;

    len = my_strlen(str) + 1;
    clone = my_malloc(sizeof(char) * len);

    clone = my_strncpy(clone, str, my_strlen(str));
    clone[len - 1] = '\0';
    return (clone);
}