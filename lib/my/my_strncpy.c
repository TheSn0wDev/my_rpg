/*
** EPITECH PROJECT, 2020
** my_strncpy.c
** File description:
** A program that copy n characters in a string
*/

int my_strlen(char const *str);

char *my_strncpy(char *dest, char *src, int n)
{
    for (int i = 0; i < n; i++)
        dest[i] = src[i];
    if (n > my_strlen(src))
        dest[my_strlen(src)] = '\0';
    return (dest);
}
