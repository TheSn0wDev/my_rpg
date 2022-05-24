/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** rpg
*/

#include "rpg.h"
#include "struct.h"

void write_infos_inside_file(int fd, int info)
{
    write(fd, my_itoa(info), my_strlen(my_itoa(info)));
    write(fd, ":", 1);
}

void write_player_data_in_file(int fd, all_t *a)
{
    sfVector2f player_pos = {a->player->obj->pos.x,
    a->player->obj->pos.y};
    sfVector2f map_rect = {a->map.map->rect.left, a->map.map->rect.top};

    write(fd, a->main_menu->nickname, my_strlen(a->main_menu->nickname));
    write(fd, ":", 1);
    write_infos_inside_file(fd, player_pos.x);
    write_infos_inside_file(fd, player_pos.y);
    write_infos_inside_file(fd, a->map.quest_todo);
    write_infos_inside_file(fd, a->player->obj->rect.top);
    write_infos_inside_file(fd, a->player->obj->rect.left);
    write_infos_inside_file(fd, a->player->skin);
    write_infos_inside_file(fd, a->map.world);
    write_infos_inside_file(fd, map_rect.x);
    write_infos_inside_file(fd, map_rect.y);
}