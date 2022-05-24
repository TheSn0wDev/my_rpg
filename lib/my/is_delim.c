/*
** EPITECH PROJECT, 2020
** Lib
** File description:
** is_delim.c
*/

int is_delim(char c, char const *delim)
{
    for (int i = 0; delim[i]; i++)
        if (c == delim[i])
            return (-1);
    return (0);
}