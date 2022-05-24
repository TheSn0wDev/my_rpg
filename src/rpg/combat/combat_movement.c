/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** combat_movement.c
*/

#include <rpg.h>
#include <struct.h>
#include "combat.h"

void update_dir_pos(enemy_t *player, enemy_t *enemy, int x, float value)
{
    float add = x * value;

    if (player->state == JUMPING)
        add = (add / 5) * 4;
    player->x_mul = add;
    if (player->p->pos.x + add > 0 && player->p->pos.x + add < 1870) {
        player->p->pos.x += add;
        if (are_colliding(player, enemy, -40)) {
            player->p->pos.x -= add;
        }
    } else {
        player->dir_state = IDLE;
    }
}

void attack(all_t *a, enemy_t *player, enemy_t *enemy)
{
    attack_stats_t *attack = NULL;

    if (player->current_attack >= player->nb_attacks)
        return;
    attack = &player->attacks[player->current_attack];
    if (enemy->p->stat.hp > 0 && get_seconds(attack->clock) > attack->cool) {
        push_front_attack(&player->my_attacks, attack, player);
        play_sfx(a, a->sfx.attack);
        player->combat_state = COOL;
        sfClock_restart(attack->clock);
    }
}

void continue_player_action(all_t *a, enemy_t *player, enemy_t *enemy)
{
    int *key_arr = a->key_arr;

    if (sfKeyboard_isKeyPressed(key_arr[1] - 97)) {
        player->dir_state = LEFT;
        update_dir_pos(player, enemy, -1, player->p->stat.max_speed);
    } else if (sfKeyboard_isKeyPressed(key_arr[3] - 97)) {
        player->dir_state = RIGHT;
        update_dir_pos(player, enemy, 1, player->p->stat.max_speed);
    } else
        player->dir_state = IDLE;
    if (sfKeyboard_isKeyPressed(key_arr[0] - 97) && player->state == GROUNDED)
        player->state = JUMPING;
    if (player->combat_state == ATTACK)
        attack(a, player, enemy);
}

void continue_action(all_t *a, enemy_t *player, enemy_t *enemy)
{
    if (player->dir_state == LEFT)
        update_dir_pos(player, enemy, -1, player->p->stat.max_speed);
    if (player->dir_state == RIGHT)
        update_dir_pos(player, enemy, 1, player->p->stat.max_speed);
    if (player->combat_state == ATTACK)
        attack(a, player, enemy);
}