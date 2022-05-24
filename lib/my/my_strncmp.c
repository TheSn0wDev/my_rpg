/*
** EPITECH PROJECT, 2021
** my_strncmp
** File description:
** oue
*/

#include "my.h"

int is_delim(char c, char const *delim)
{
    for (int i = 0; delim[i]; i++)
        if (c == delim[i])
            return (-1);
    return (0);
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int size_s1 = 0;
    int size_s2 = 0;
    int i = 0;

    while (i < n && s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
        i = i + 1;
    if (i == n)
        i = i - 1;
    size_s1 = s1[i];
    size_s2 = s2[i];
    if (size_s1 == size_s2)
        return (0);
    return (size_s1 - size_s2);
}