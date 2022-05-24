/*
** EPITECH PROJECT, 2020
** my_put_char.c
** File description:
** A simple program that print a char
*/

#include <unistd.h>

int my_putchar(char c)
{
    if (write(1, &c, 1) == -1)
        return (84);
    else
        return (0);
}
