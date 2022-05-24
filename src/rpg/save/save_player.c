/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** save_player.c
*/

#include "rpg.h"
#include "struct.h"

void write_player_quest_and_pos(all_t *a)
{
    char **file_arr = read_arr_file("data/players/player_data.txt");
    int line = get_data_line_in_arr(file_arr, a->main_menu->nickname);

    write_data_in_file(line, file_arr, a);
}

void write_stats(int fd, int stat)
{
    char *str_stat = to_str(stat);

    write(fd, str_stat, my_strlen(str_stat));
    write(fd, "     ", 5);
}

void write_player_stats(all_t *a, int fd, stat_t *stat)
{
    int speed = (int) stat->speed;

    write(fd, a->main_menu->nickname, my_strlen(a->main_menu->nickname));
    write(fd, "          ", 10);
    write_stats(fd, stat->level);
    write_stats(fd, stat->attack);
    write_stats(fd, stat->defense);
    write_stats(fd, stat->hp);
    write_stats(fd, stat->max_hp);
    write_stats(fd, speed);
    write_stats(fd, stat->exp);
    write_stats(fd, stat->max_exp);
    write_stats(fd, stat->gold);
}

void save_player_stats(all_t *a, stat_t *stat)
{
    char **info = read_arr_file("data/players/player.txt");
    int fd = open("data/players/player.txt", O_WRONLY | O_TRUNC);
    char **player = NULL;
    bool found_player = false;

    write_player_quest_and_pos(a);
    for (int i = 0; info[i]; i++) {
        player = my_str_to_word_array(info[i], " ");
        if (my_strcmp(player[0], a->main_menu->nickname) == 0) {
            write_player_stats(a, fd, stat);
            found_player = true;
        } else
            write(fd, info[i], my_strlen(info[i]));
        write(fd, "\n", 1);
    }
    if (found_player == false && a->main_menu->nickname[0] != 0) {
        write_player_stats(a, fd, stat);
        write(fd, "\n", 1);
    }
    close(fd);
}