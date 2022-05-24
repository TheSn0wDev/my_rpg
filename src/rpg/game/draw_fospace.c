/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-clement.ozor
** File description:
** draw_fospace
*/

#include "rpg.h"
#include "struct.h"

void must_draw_before_player_fospace(all_t *a)
{
    if (a->pause->paused == false)
        spawn_mobs(30, a);
}