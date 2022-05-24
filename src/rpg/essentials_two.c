/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** rpg
*/

#include "rpg.h"
#include "struct.h"

int get_bytes_nb(FILE *file)
{
    char *buffer = NULL;
    int ret = 0;
    int size = 0;
    size_t len = 0;

    ret = getline(&buffer, &len, file);
    for (; ret != -1; ret = getline(&buffer, &len, file)) {
        size += my_strlen(buffer);
    }
    free(buffer);
    return (size);
}

int get_file_bytes_nb(char *filepath)
{
    FILE *file = fopen(filepath, "r");

    if (file == NULL)
        return (0);
    return (get_bytes_nb(file));
}