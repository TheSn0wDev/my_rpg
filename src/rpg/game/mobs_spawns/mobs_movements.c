/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-clement.ozor
** File description:
** mobs_movements
*/

#include "mobs.h"
#include "struct.h"
#include "rpg.h"

bool is_mob_in_range(sfVector2f p_pos, sfVector2f m_pos)
{
    if (m_pos.x - 400 <= p_pos.x && p_pos.x <= m_pos.x + 400
    && m_pos.y - 400 <= p_pos.y && p_pos.y <= m_pos.y + 400)
        return (true);
    return (false);
}

int chase_player_two(all_t *a, mobs_object_t *mob, sfVector2f p_pos)
{
    int mobx = mob->pos.x + mob->rect.width * mob->scale.x;
    int moby = mob->pos.y + mob->rect.height * mob->scale.y;

    if (mobx >= p_pos.x && moby >= p_pos.y &&
    mb_colide(a, mob, (sfVector2i){mob->pos.x - 1, mob->pos.y - 2}) == 1) {
        mob->pos.x -= 1;
        mob->pos.y -= 1;
        return (1);
    }
    if (mobx <= p_pos.x && moby >= p_pos.y &&
    mb_colide(a, mob, (sfVector2i){mob->pos.x + 1, mob->pos.y - 2}) == 1) {
        mob->pos.x += 1;
        mob->pos.y -= 1;
        return (1);
    }
    return (0);
}

int chase_player(all_t *a, mobs_object_t *mob, sfVector2f p_pos)
{
    int mobx = mob->pos.x + mob->rect.width * mob->scale.x;
    int moby = mob->pos.y + mob->rect.height * mob->scale.y;

    if (mobx <= p_pos.x && moby <= p_pos.y &&
    mb_colide(a, mob, (sfVector2i){mob->pos.x + 1, mob->pos.y + 2}) == 1) {
        mob->pos.x += 1;
        mob->pos.y += 1;
        return (1);
    }
    if (mobx >= p_pos.x && moby <= p_pos.y &&
    mb_colide(a, mob, (sfVector2i){mob->pos.x - 1, mob->pos.y + 2}) == 1) {
        mob->pos.x -= 1;
        mob->pos.y += 1;
        return (1);
    }
    if (chase_player_two(a, mob, p_pos) == 1)
        return (1);
    return (-1);
}

void mobs_movements(all_t *a, mobs_object_t *mob)
{
    float row = a->player->obj->pos.y + a->map.map->rect.top;
    float col = a->player->obj->pos.x + a->map.map->rect.left;
    sfVector2f p_pos = {col, row};

    if (is_mob_in_range(p_pos, mob->pos) == false) {
        if (random_monster_movements(a, mob) == 1)
            change_dir_animation(mob, p_pos);
        return;
    }
    if (get_seconds(mob->clock) > 0.01) {
        if (chase_player(a, mob, p_pos) == 1)
            change_dir_animation(mob, p_pos);
        sfClock_restart(mob->clock);
    }
}