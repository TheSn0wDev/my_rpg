/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** rpg
*/

#include "rpg.h"
#include "struct.h"

void update_stat(int *stat_to_modif, int to_add)
{
    *stat_to_modif += to_add;
}

void get_equipement_stat_update(player_t *player, int id, int option)
{
    if (id == 0)
        update_stat(&player->obj->stat.attack, 2 * option);
    if (id == 1) {
        update_stat(&player->obj->stat.hp, 5 * option);
        update_stat(&player->obj->stat.max_hp, 5 * option);
    }
    if (id > 1)
        update_stat(&player->obj->stat.defense, 1 * option);
}

void unequip_item_in_inv(all_t *a, int id, int i)
{
    add_item(0, i * 2 + 1, a);
    a->inventory.items[i].equiped = false;
    get_equipement_stat_update(a->player, id, -1);
}

void equip_item_in_inv(all_t *a, int id)
{
    add_item(1, id * 2 + 1, a);
    a->inventory.items[id].equiped = true;
    get_equipement_stat_update(a->player, id, 1);
}