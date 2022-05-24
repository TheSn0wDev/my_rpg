/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** collisions
*/

#include "rpg.h"
#include "struct.h"

int get_maze_height(char **maze)
{
    int i = 0;

    for ( ; maze[i] != 0; i++);
    return (i);
}

int get_maze_width(char **maze)
{
    int i = 0;

    for ( ; maze[0][i] != '\0'; i++);
    return (i);
}

int can_read_case(all_t *a, int casex, int casey)
{
    if (casex > 0 && casey > 0 && casex < get_maze_width(a->map.txtmap)
    && casey < get_maze_height(a->map.txtmap)) {
        return (1);
    }
    return (0);
}

int handle_other_interactions(all_t *a, int casex, int casey)
{
    if (can_read_case(a, casex, casey)) {
        if (a->map.txtmap[casey][casex] == 'N')
            return (9);
        if (a->map.txtmap[casey][casex] == 'P')
            return (8);
    }
    return (0);
}

int is_colliding(all_t *a, sfKeyCode code)
{
    float row = a->player->obj->pos.y + a->map.map->rect.top;
    float col = a->player->obj->pos.x + a->map.map->rect.left;
    float map_pct_y = (row / a->map.map_dim.y) * 100;
    float map_pct_x = (col / a->map.map_dim.x) * 100;
    int casey = (map_pct_y / 100) * get_maze_height(a->map.txtmap);
    int casex = (map_pct_x / 100) * get_maze_width(a->map.txtmap);

    if (code == a->key_arr[0] - 97 && can_read_case(a, casex, casey - 1)
    && a->map.txtmap[casey - 1][casex] == '0')
        return (1);
    if (code == a->key_arr[3] - 97 && can_read_case(a, casex + 1, casey)
    && a->map.txtmap[casey][casex + 1] == '0')
        return (1);
    if (code == a->key_arr[1] - 97 && can_read_case(a, casex - 1, casey)
    && a->map.txtmap[casey][casex - 1] == '0')
        return (1);
    if (code == a->key_arr[2] - 97 && can_read_case(a, casex, casey + 1)
    && a->map.txtmap[casey + 1][casex] == '0')
        return (1);
    return (handle_other_interactions(a, casex, casey));
}