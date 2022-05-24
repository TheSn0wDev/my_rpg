/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** rpg
*/

#include "rpg.h"
#include "struct.h"

void move_minimap(all_t *a, sfVector2f dir)
{
    if (dir.x != 0)
        a->map.mini_map->rect.left += dir.x / a->map.map->scale.x;
    else
        a->map.mini_map->rect.top += dir.y / a->map.map->scale.y;
    sfSprite_setTextureRect(a->map.mini_map->s, a->map.mini_map->rect);
}

void handle_location_display(all_t *a)
{
    if (a->map.world == SPAWN)
        sfText_setString(a->map.location, "VILLAGE");
    if (a->map.world == FOPSPACE)
        sfText_setString(a->map.location, "PLAIN");
    if (a->map.world == DUNGEON)
        sfText_setString(a->map.location, "DUNGEON");
    if (a->map.world == BOSS)
        sfText_setString(a->map.location, "BOSS ROOM");
}

void handle_quests_display(all_t *a)
{
    if (a->map.quest_todo == CHIEF_QUEST)
        sfText_setString(a->map.quest, "Talk to the\nvillage chief.");
    if (a->map.quest_todo == BLACKSMITH_QUEST)
        sfText_setString(a->map.quest, "Find the\nblacksmith.");
    if (a->map.quest_todo == OLDGUY_QUEST)
        sfText_setString(a->map.quest, "Find the\nelder man.");
    if (a->map.quest_todo == SKELETON_QUEST)
        sfText_setString(a->map.quest, "Kill\nDiabolo.");
    if (a->map.quest_todo == BOSS_QUEST)
        sfText_setString(a->map.quest, "Kill\nDiabolo.");
}