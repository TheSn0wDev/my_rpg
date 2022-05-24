/*
** EPITECH PROJECT, 2020
** my_strcat.c
** File description:
** A program that copy n characters in a string
*/

#include <stdlib.h>
#include "../../includes/garbage_collector.h"

int my_strlen(char const *str);

char *my_strcat(char *dest, const char *src)
{
    int i = 0;
    char *clone = dest;
    dest = my_malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));

    for (i = 0; clone[i]; i++)
        dest[i] = clone[i];
    for (int s = 0; src[s] != '\0'; s++) {
        dest[i] = src[s];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
