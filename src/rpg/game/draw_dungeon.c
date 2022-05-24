/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-clement.ozor
** File description:
** draw_dungeon
*/

#include "rpg.h"
#include "struct.h"

void must_draw_before_player_dungeon(all_t *a)
{
    if (a->pause->paused == false)
        spawn_mobs(100, a);
    if (a->mobs[0].miniboss == false && a->mobs[0].mb_nb != 0
    && a->mobs[0].minibossnb == 0) {
        create_special_mob_two(a);
        a->mobs[0].minibossnb += 1;
    }
}

void must_draw_before_player_dungeon_boss(all_t *a)
{
    if (a->pause->paused == false) {
        spawn_mobs(100, a);
    if (a->mobs[0].boss == false && a->mobs[0].mb_nb != 0
    && a->mobs[0].bossnb == 0) {
            create_special_mob_one(a);
            a->mobs[0].bossnb += 1;
        }
    }
}