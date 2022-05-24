/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-clement.ozor
** File description:
** rm_from_data_files
*/

#include "rpg.h"
#include "struct.h"

void rm_from_file_quest(all_t *a, int fd, char **file_arr, int line)
{
    for (int i = 0; file_arr[i]; i++) {
        if (i == line) {
            continue;
        } else
            write(fd, file_arr[i], my_strlen(file_arr[i]));
        write(fd, "\n", 1);
    }
    close(fd);
}

void rm_from_data_files(all_t *a)
{
    char **file_arr = NULL;
    int line = 0;
    int fd = 0;

    if (a->main_menu->nickname[0] == '\0')
        return;
    file_arr = read_arr_file("data/players/player_data.txt");
    line = get_data_line_in_arr(file_arr, a->main_menu->nickname);
    fd = open("data/players/player_data.txt", O_TRUNC | O_WRONLY, 0666);
    rm_from_file_quest(a, fd, file_arr, line);
    file_arr = read_arr_file("data/players/player.txt");
    line = get_data_line_in_arr(file_arr, a->main_menu->nickname);
    fd = open("data/players/player.txt", O_TRUNC | O_WRONLY, 0666);
    rm_from_file_quest(a, fd, file_arr, line);
    file_arr = read_arr_file("data/players/inventory.txt");
    line = get_data_line_in_arr(file_arr, a->main_menu->nickname);
    fd = open("data/players/inventory.txt", O_TRUNC | O_WRONLY, 0666);
    rm_from_file_quest(a, fd, file_arr, line);
}
