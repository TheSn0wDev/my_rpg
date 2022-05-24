/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** enemy_ai.c
*/

#include <rpg.h>
#include <struct.h>
#include "combat.h"

void choose_new_action(enemy_t *enemy)
{
    int nb = enemy->dir_state;
    int jump = rand_nbr(0, 3);

    if (jump == 3) {
        enemy->state = JUMPING;
        return;
    }
    while (nb == (int)enemy->dir_state)
        nb = rand_nbr(2, 4);
    enemy->dir_state = nb;
}

void get_next_attack(enemy_t *enemy, enemy_t *player)
{
    int nb = rand_nbr(0, enemy->nb_attacks - 1);
    int range = 0;

    for (int i = 0; i < enemy->nb_attacks; i++) {
        range = enemy->attacks[i].range;
        if (nb == i && are_colliding(enemy, player, range)) {
            enemy->current_attack = i;
            enemy->combat_state = ATTACK;
        }
    }
}

void get_action(enemy_t *enemy, enemy_t *player)
{
    attack_t *attacks = player->my_attacks;
    sfVector2f save_pos = enemy->p->pos;
    int nb = rand_nbr(0, 25);

    enemy->p->pos.x += 100;
    enemy->dir_state = RIGHT;
    if (nb == 0 && enemy->state == GROUNDED)
        enemy->state = JUMPING;
    for (; attacks; attacks = attacks->next) {
        if (hit_enemy(enemy, attacks))
            enemy->dir_state = LEFT;
    }
    enemy->p->pos = save_pos;
}

void get_next_action(all_t *a, enemy_t *enemy, enemy_t *player)
{
    int nb = rand_nbr(0, 5);

    if (nb == 1)
        get_next_attack(enemy, player);
    else
        get_action(enemy, player);
    continue_action(a, enemy, player);
}