/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** check_collisions.c
*/

#include <rpg.h>
#include <struct.h>
#include "combat.h"

int are_colliding(enemy_t *player, enemy_t *enemy, int minus)
{
    int p_rect = player->p->rect.height;
    int e_rect = enemy->p->rect.height;
    sfVector2f p_pos = player->p->pos;
    sfVector2f e_pos = enemy->p->pos;

    e_rect *= enemy->p->scale.x;
    p_rect *= player->p->scale.x;
    e_rect += minus;
    p_rect += minus;
    e_pos.x -= minus;
    p_pos.x -= minus;
    if (e_pos.x <= p_pos.x + p_rect && e_pos.x + e_rect >= p_pos.x)
        return (1);
    return (0);
}

int hit_enemy(enemy_t *enemy, attack_t *attack)
{
    int a_rect = attack->stats.rect.height;
    int e_rect = enemy->p->rect.height;
    sfVector2f a_pos = attack->pos;
    sfVector2f e_pos = enemy->p->pos;

    e_rect *= enemy->p->scale.x;
    e_rect -= enemy->p->rect.height / 2;
    if (e_pos.x <= a_pos.x + a_rect && e_pos.x + e_rect >= a_pos.x)
        return (1);
    return (0);
}