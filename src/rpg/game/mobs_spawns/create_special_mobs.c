/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-clement.ozor
** File description:
** create_special_mobs
*/

#include "mobs.h"
#include "struct.h"
#include "rpg.h"

void create_special_mob_one(all_t *a)
{
    int w = get_maze_width(a->map.txtmap);
    int h = get_maze_height(a->map.txtmap);
    mobs_object_t tick = {0, 0, {5, 5}, {(151 * (a->map.map_dim.x / w)),
    (104 * (a->map.map_dim.y / h))}, 0, 0, {194, 33*7, 32, 32}, 0, 0, 2, 0};

    init_mobs_object(&tick, "assets/enemies3.png");
    tick.name = "DEMON_LORD";
    int_list_push_front(&a->mobs[0].mb_list, tick);
    a->mobs->mb_nb += 1;
}

void create_special_mob_two(all_t *a)
{
    int w = get_maze_width(a->map.txtmap);
    int h = get_maze_height(a->map.txtmap);
    mobs_object_t tick = {0, 0, {5, 5}, {(140 * (a->map.map_dim.x / w)),
    (170 * (a->map.map_dim.y / h))}, 0, 0, {194, 198, 32, 32}, 0, 0, 2, 0};

    init_mobs_object(&tick, "assets/enemies3.png");
    tick.name = "SCYTHE";
    int_list_push_front(&a->mobs[0].mb_list, tick);
    a->mobs->mb_nb += 1;
}