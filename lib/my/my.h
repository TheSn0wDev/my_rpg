/*
** EPITECH PROJECT, 2020
** MyLib
** File description:
** my.h
*/

#ifndef MYRPG_MY_H

#define MYRPG_MY_H

#include <math.h>

char *float_to_str(float nb, int point);
int my_putchar(char c);
int my_putstr(char const *str);
char **my_str_to_word_array(char const *str, char *separator);
int my_strcmp(char const *s1, char const *s2);
int my_strlen(char const *str);
char *my_strncpy(char *dest, char const *src, int n);
char *my_itoa(int number);
char *my_strcat(char *dest, const char *src);
int my_getnbr(char const *str);
char *to_str(int nb);
char *my_strdup(char *str);
int my_strncmp(char const *s1, char const *s2, int n);

#endif