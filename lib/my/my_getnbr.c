/*
** EPITECH PROJECT, 2020
** Day10
** File description:
** my_nbr.c
*/

int my_compute_power_rec(int nb, int p);

int my_char_isnum(char c)
{
    if (c < 48 || c > 57)
        return (0);
    return (1);
}

int my_start_num(char const *str)
{
    int i = 0;
    for (; str[i]; i++) {
        if (my_char_isnum(str[i]))
            return (i);
    }
    return (i);
}

int my_getnbr(char const *str)
{
    int nbr = 0;
    int len = 0;
    int f_nbr = my_start_num(str);
    int p = 0;
    int s = 1;

    for (int i = 0; i < f_nbr; i++)
        if (str[i] == '-')
            s = -s;
    for (int i = f_nbr; str[i] >= 48 && str[i] <= 57; i++)
            len = len + 1;
    p = len - 1;
    for (int i = f_nbr; i < (f_nbr + len); i++, p--)
        nbr = nbr + (str[i] - 48) * my_compute_power_rec(10, p);
    if (nbr == -2147483648)
        return (-2147483648);
    else if (nbr < 0)
        return (0);
    return (nbr * s);
}
