/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** rpg
*/

#include "rpg.h"
#include "struct.h"

void forgeron_interact(all_t *a)
{
    sfSprite_setPosition(a->npc->dotex[0].s, (sfVector2f)
    {a->npc[0].npc_arr[QUESTMASTER].pos.x + 45 - a->map.map->rect.left,
    a->npc[0].npc_arr[QUESTMASTER].pos.y - 55 - a->map.map->rect.top});
    a->npc->ex = true;
    start_dialogue(a, "assets/dialogue/questmaster_unequiped.txt");
    a->player->blocked = true;
}

void questmaster_interact(all_t *a)
{
    sfSprite_setPosition(a->npc->dotex[0].s, (sfVector2f)
    {a->npc[0].npc_arr[SKELETON].pos.x + 45 - a->map.map->rect.left,
    a->npc[0].npc_arr[SKELETON].pos.y - 55 - a->map.map->rect.top});
    a->npc->ex = true;
    start_dialogue(a, "assets/dialogue/skel_uneq.txt");
    a->player->blocked = true;
}