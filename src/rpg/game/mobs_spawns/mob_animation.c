/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-clement.ozor
** File description:
** mob_animation
*/

#include "mobs.h"
#include "struct.h"
#include "rpg.h"

void change_mob_rect(mobs_object_t *mob, int left)
{
    if (get_seconds(mob->rectclock) > 0.1) {
        if (mob->rect.left <= left + (mob->rect.width * 1)) {
            mob->rect.left += mob->rect.width;
            sfSprite_setTextureRect(mob->sprite, mob->rect);
        } else {
            mob->rect.left = left;
            sfSprite_setTextureRect(mob->sprite, mob->rect);
        }
        sfClock_restart(mob->rectclock);
    }
}

bool change_dir_animation_two(mobs_object_t *mob,
sfVector2f p_pos, bool change_dir)
{
    if (p_pos.x < mob->pos.x) {
        if (change_dir == false) {
            mob->rect.left = 288;
            sfSprite_setTextureRect(mob->sprite, mob->rect);
            change_dir = true;
        }
        change_mob_rect(mob, 288);
        return (change_dir);
    }
    if (p_pos.x > mob->pos.x) {
        if (change_dir == false) {
            mob->rect.left = 95;
            sfSprite_setTextureRect(mob->sprite, mob->rect);
            change_dir = true;
        }
        change_mob_rect(mob, 95);
        return (change_dir);
    }
    return (change_dir);
}

void change_dir_animation(mobs_object_t *mob, sfVector2f p_pos)
{
    static bool change_dir = false;

    if (p_pos.y < mob->pos.y && p_pos.y + 90 < mob->pos.y) {
        if (change_dir == false) {
            mob->rect.left = 192;
            sfSprite_setTextureRect(mob->sprite, mob->rect);
            change_dir = true;
        }
        change_mob_rect(mob, 192);
    } else if (p_pos.y > mob->pos.y && p_pos.y - 90 > mob->pos.y) {
        if (change_dir == false) {
            mob->rect.left = 0;
            sfSprite_setTextureRect(mob->sprite, mob->rect);
            change_dir = true;
        }
        change_mob_rect(mob, 0);
    } else
        change_dir = change_dir_animation_two(mob, p_pos, change_dir);
}