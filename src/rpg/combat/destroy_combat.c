/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** destroy game
*/

#include <rpg.h>
#include <struct.h>
#include "combat.h"

void destroy_combat(all_t *a)
{
    sfSprite_setScale(a->player->obj->s, (sfVector2f){0.6, 0.6});
    destroy_attacks(&a->combat.enemy.my_attacks);
    destroy_attacks(&a->combat.player.my_attacks);
}