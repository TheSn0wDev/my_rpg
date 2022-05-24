/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-clement.ozor
** File description:
** init_mob
*/

#include "mobs.h"
#include "struct.h"
#include "rpg.h"

void printlist(mobs_lists_t *list)
{
    while (list != NULL) {
        list = list->next;
    }
}

void create_mob(all_t *a, sfVector2i pos)
{
    int top = rand_nbr(0, 5);
    int w = get_maze_width(a->map.txtmap);
    int h = get_maze_height(a->map.txtmap);
    mobs_object_t tick = {0, 0, {2.5, 2.5}, {(pos.x * (a->map.map_dim.x / w)),
    (pos.y * (a->map.map_dim.y / h))}, 0, 0, {194, 33 * top, 32, 32},
    0, 0, 0, 0};

    init_mobs_name(&tick, top);
    init_mobs_object(&tick, "assets/enemies3.png");
    int_list_push_front(&a->mobs[0].mb_list, tick);
    a->mobs->mb_nb += 1;
}

bool check_for_colision(all_t *a, mobs_object_t mobs)
{
    float row = a->player->obj->pos.y + a->map.map->rect.top;
    float col = a->player->obj->pos.x + a->map.map->rect.left;

    if (mobs.pos.x <= col &&
    col <= mobs.pos.x + mobs.rect.width * mobs.scale.x
    && mobs.pos.y <= row &&
    row <= mobs.pos.y + mobs.rect.height * mobs.scale.y) {
        return (true);
    }
    return (false);
}