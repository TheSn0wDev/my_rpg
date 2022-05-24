/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-clement.ozor
** File description:
** quest
*/

#ifndef QUEST_H_
#define QUEST_H_

#include "struct.h"

void init_quests(all_t *a, int id);
void init_quest_ui(all_t *a);
void handle_chief_quest(all_t *a);
void handle_blacksmith_quest(all_t *a);
void handle_old_guy_quest(all_t *a);
void handle_skeleton_quest(all_t *a);
void handle_boss_quest(all_t *a);
void handle_quests_display(all_t *a);
void handle_location_display(all_t *a);

#endif /* !QUEST_H_ */