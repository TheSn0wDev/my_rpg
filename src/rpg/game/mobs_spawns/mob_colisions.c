/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-clement.ozor
** File description:
** mob_colisions
*/

#include "mobs.h"
#include "struct.h"
#include "rpg.h"

sfVector2i get_mob_case(all_t *a, mobs_object_t *mob, sfVector2i mobpos)
{
    sfVector2i arr = {0, 0};
    float map_pct_y = (((float) mobpos.y +
    mob->rect.height * mob->scale.y) / a->map.map_dim.y) * 100;
    float map_pct_x = (((float) mobpos.x +
    mob->rect.width * mob->scale.x) / a->map.map_dim.x) * 100;

    arr.y = (map_pct_y / 100) * get_maze_height(a->map.txtmap);
    arr.x = (map_pct_x / 100) * get_maze_width(a->map.txtmap);
    return (arr);
}

sfVector2i get_player_case(all_t *a)
{
    sfVector2i arr = {0, 0};
    float row = a->player->obj->pos.y + a->map.map->rect.top;
    float col = a->player->obj->pos.x + a->map.map->rect.left;
    float map_pct_y = (row / a->map.map_dim.y) * 100;
    float map_pct_x = (col / a->map.map_dim.x) * 100;

    arr.y = (map_pct_y / 100) * get_maze_height(a->map.txtmap);
    arr.x = (map_pct_x / 100) * get_maze_width(a->map.txtmap);
    return (arr);
}

int mb_colide(all_t *a, mobs_object_t *mob, sfVector2i coods)
{
    sfVector2i mb_pos = get_mob_case(a, mob, coods);

    if (can_read_case(a, mb_pos.x, mb_pos.y) == 1) {
        if (a->map.txtmap[mb_pos.y][mb_pos.x] != '0')
            return (1);
    }
    return (0);
}