/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-clement.ozor
** File description:
** lauch_right_dialogue
*/

#include "rpg.h"
#include "struct.h"

void questmaster(all_t *a)
{
    if (a->npc[0].npc_arr[FORGERON].quest)
        start_dialogue(a, "assets/dialogue/questmaster_unequiped.txt");
    else
        start_dialogue(a, "assets/dialogue/questmaster_equiped.txt");
}

void forgeron(all_t *a)
{
    if (a->map.quest_todo != BLACKSMITH_QUEST)
        return;
    a->npc[0].npc_arr[FORGERON].quest = false;
    start_dialogue(a, "assets/dialogue/blacksmith.txt");
    add_item(0, 0, a);
    a->map.quest_todo = OLDGUY_QUEST;
}

void spawnnpc(all_t *a)
{
    if (a->map.quest_todo != CHIEF_QUEST)
        return;
    start_dialogue(a, "assets/dialogue/chief.txt");
    a->map.quest_todo = BLACKSMITH_QUEST;
}

void oldidk(all_t *a)
{
    if (a->map.quest_todo != OLDGUY_QUEST)
        return;
    a->npc[0].obj[OLDIDK].quest = true;
    start_dialogue(a, "assets/dialogue/old.txt");
    add_item(1, 2, a);
    add_item(2, 4, a);
    add_item(3, 6, a);
    add_item(4, 8, a);
    a->map.quest_todo = SKELETON_QUEST;
}

void skeleton(all_t *a)
{
    if (a->map.quest_todo != SKELETON_QUEST
    && a->map.quest_todo != OLDGUY_QUEST)
        return;
    if (a->map.quest_todo == OLDGUY_QUEST) {
        start_dialogue(a, "assets/dialogue/skel_uneq.txt");
        return;
    }
    start_dialogue(a, "assets/dialogue/skel_eq.txt");
    a->map.quest_todo = BOSS_QUEST;
}