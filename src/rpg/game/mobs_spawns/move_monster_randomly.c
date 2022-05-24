/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-clement.ozor
** File description:
** move_monster_randomly
*/

#include "mobs.h"
#include "struct.h"
#include "rpg.h"

int randomly_moves_two(all_t *a, mobs_object_t *mob, int dir)
{
    if (dir == 2 && mb_colide(a, mob,
    (sfVector2i) {mob->pos.x - 2, mob->pos.y - 2}) == 1) {
        mob->pos.x -= 1;
        mob->pos.y -= 1;
        return (1);
    }
    if (dir == 3 && mb_colide(a, mob,
    (sfVector2i) {mob->pos.x + 2, mob->pos.y - 2}) == 1) {
        mob->pos.x += 1;
        mob->pos.y -= 1;
        return (1);
    }
    return (0);
}

int randomly_moves(all_t *a, mobs_object_t *mob, int dir)
{
    if (dir == 0 && mb_colide(a, mob,
    (sfVector2i) {mob->pos.x + 2, mob->pos.y + 2}) == 1) {
        mob->pos.x += 1;
        mob->pos.y += 1;
        return (1);
    }
    if (dir == 1 && mb_colide(a, mob,
    (sfVector2i) {mob->pos.x - 2, mob->pos.y + 2}) == 1) {
        mob->pos.x -= 1;
        mob->pos.y += 1;
        return (1);
    }
    if (randomly_moves_two(a, mob, dir) == 1)
        return (1);
    return (-1);
}

int random_monster_movements(all_t *a, mobs_object_t *mob)
{
    int ret = 0;
    int dir = rand_nbr(0, 5);

    if (get_seconds(a->mobs[0].rdm_move) > 0.1) {
        ret = randomly_moves(a, mob, dir);
        sfClock_restart(a->mobs[0].rdm_move);
    }
    return (ret);
}