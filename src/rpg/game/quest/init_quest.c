/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** quests init
*/

#include "rpg.h"
#include "struct.h"

void init_quests(all_t *a, int id)
{
    if (id == QUESTMASTER)
        questmaster(a);
    if (id == SPAWNNPC)
        spawnnpc(a);
    if (id == FORGERON)
        forgeron(a);
    if (id == OLDIDK)
        oldidk(a);
    if (id == SKELETON)
        skeleton(a);
}

void check_npc_interaction(all_t *a)
{
    int id = 0;

    if ((id = is_npc_in_range(a)) != -1) {
        handle_interaction_button(a, id);
        if (sfKeyboard_isKeyPressed(a->key_arr[4] - 97)) {
            init_quests(a, id);
        }
    }
}