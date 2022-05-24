/*
** EPITECH PROJECT, 2020
** my_strlen.c
** File description:
** A program that counts the numbers of characters
*/

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i]; i++);
    return (i);
}
