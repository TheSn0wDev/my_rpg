/*
** EPITECH PROJECT, 2020
** My_RPG
** File description:
** essentials.c
*/

#include <rpg.h>

char *my_memset(char *str, char c, int size)
{
    for (int i = 0; i < size; i++) {
        str[i] = c;
    }
    return (str);
}

float get_seconds(sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = time.microseconds / 1000000.0;

    return (seconds);
}

float round_float(float nb, int x)
{
    float new_nb = (int)(nb * pow(10, x));

    new_nb /= pow(10, x);
    return (new_nb);
}

int rand_nbr(int lower, int upper)
{
    int nbr = (rand() % (upper - lower + 1)) + lower;

    return (nbr);
}

char **read_arr_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *buff;
    char **array = NULL;
    int bytes_nb = get_file_bytes_nb(filepath);

    if (fd < 0)
        return (NULL);
    if (bytes_nb == 0)
        return (NULL);
    buff = my_malloc(bytes_nb + 1);
    if (buff == NULL)
        return (NULL);
    buff[bytes_nb] = 0;
    if (read(fd, buff, bytes_nb) < 0)
        return (NULL);
    array = my_str_to_word_array(buff, "\n");
    return (array);
}