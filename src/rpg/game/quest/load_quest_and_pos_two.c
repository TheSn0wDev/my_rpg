/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** rpg
*/

#include "rpg.h"
#include "struct.h"

int get_data_line_in_arr(char **arr, char *data)
{
    char **arr_two;
    int i = 0;

    if (arr == NULL)
        return (-1);
    for (; arr[i]; i++) {
        arr_two = my_str_to_word_array(arr[i], ": ");
        if (my_strcmp(arr_two[0], data) == 0)
            return (i);
    }
    return (-1);
}

void write_data_in_file(int line, char **file_arr, all_t *a)
{
    int fd = open("data/players/player_data.txt", O_TRUNC | O_WRONLY, 0666);
    bool found_nickname = false;

    if (file_arr == NULL) {
        write_player_data_in_file(fd, a);
        return;
    }
    for (int i = 0; file_arr[i]; i++) {
        if (i == line) {
            write_player_data_in_file(fd, a);
            found_nickname = true;
        } else
            write(fd, file_arr[i], my_strlen(file_arr[i]));
        write(fd, "\n", 1);
    }
    if (found_nickname == false && a->main_menu->nickname[0] != 0)
        write_player_data_in_file(fd, a);
}

void load_map_with_save(all_t *a)
{
    char *map[4] = {"assets/maps/small_castle_map.png",
    "assets/maps/fopenspace.png", "assets/maps/DUNGEON.png",
    "assets/maps/boss.png"};
    char *txt[4] = {"src/rpg/game/map/test.txt", "src/rpg/game/map/fos.txt",
    "src/rpg/game/map/dungeon.txt", "src/rpg/game/map/dungeon_boss.txt"};
    sfIntRect pos[4] = {{500, 1500, 500, 500}, {a->map.map->rect.left, 1248,
    a->player->obj->pos.x, 1000}, {400, 1300, 800, 700}, {0, 1600, 250, 500}};

    reload_map(a, map[a->map.world], txt[a->map.world]);
    reloard_map_player_pos(a, pos[a->map.world]);
    reloard_minimap(a, map[a->map.world]);
}

void load_player_pos_save(all_t *a, char **line_arr, int lin, char ** file_arr)
{
    line_arr = my_str_to_word_array(file_arr[lin], ":");
    a->map.quest_todo = my_getnbr(line_arr[3]);
    a->player->obj->rect.top = my_getnbr(line_arr[4]);
    a->player->obj->rect.left = my_getnbr(line_arr[5]);
    a->player->skin = my_getnbr(line_arr[6]);
    a->map.world = my_getnbr(line_arr[7]);
    sfSprite_setTextureRect(a->player->obj->s, a->player->obj->rect);
    load_map_with_save(a);
    a->player->obj->pos.x = (float){my_getnbr(line_arr[1])};
    a->player->obj->pos.y = (float){my_getnbr(line_arr[2])};
    a->map.map->rect.left = my_getnbr(line_arr[8]);
    a->map.map->rect.top = my_getnbr(line_arr[9]);
    sfSprite_setTextureRect(a->map.map->s, a->map.map->rect);
    sfSprite_setPosition(a->player->obj->s, (sfVector2f)
    {a->player->obj->pos.x + a->map.map->rect.left,
    a->player->obj->pos.y + a->map.map->rect.top});
    init_minimap_and_location(a);
}