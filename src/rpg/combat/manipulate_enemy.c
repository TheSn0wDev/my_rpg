/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** manipulate_enemy.c
*/

#include <rpg.h>
#include <struct.h>
#include "combat.h"

void shift_enemy_rect(enemy_t *enemy)
{
    int base = 3 * enemy->p->rect.height;

    if (get_seconds(enemy->clock) < 0.1)
        return;
    if (enemy->dir_state != IDLE && enemy->state == GROUNDED) {
        if (enemy->p->rect.left >= base + 2 * enemy->p->rect.height)
            enemy->p->rect.left = base;
        else
            enemy->p->rect.left += enemy->p->rect.height;
    } else if (enemy->state == JUMPING) {
        enemy->p->rect.left = base;
    }  else {
        enemy->p->rect.left = base + enemy->p->rect.height;
    }
    sfSprite_setTextureRect(enemy->p->s, enemy->p->rect);
    sfClock_restart(enemy->clock);
}

void shift_combat_player_rect(all_t *a, enemy_t *enemy)
{
    int left_rect = a->player->skin * (160 * 3);

    if (get_seconds(enemy->clock) < 0.1)
        return;
    if (enemy->dir_state != IDLE && enemy->state == GROUNDED) {
        if (enemy->p->rect.left == left_rect)
            enemy->p->rect.left = left_rect + 320;
        else
            enemy->p->rect.left -= enemy->p->rect.width;
    } else {
        enemy->p->rect.left = left_rect;
    }
    sfSprite_setTextureRect(enemy->p->s, enemy->p->rect);
    sfClock_restart(enemy->clock);
}

void update_enemy(all_t *a, enemy_t *enemy, int ground, int identity)
{
    if (enemy->state == JUMPING) {
        enemy->p->pos.y += enemy->p->stat.speed * enemy->y_mul;
        enemy->p->stat.speed += 0.4 * enemy->y_mul;
        if (enemy->p->pos.y >= ground) {
            enemy->state = GROUNDED;
            enemy->p->pos.y = ground;
            enemy->y_mul = -1;
            enemy->p->stat.speed = enemy->p->stat.max_speed;
        } else if (enemy->p->pos.y <= ground - 50) {
            enemy->y_mul = 1;
        }
    }
    if (identity == 0)
        shift_combat_player_rect(a, enemy);
    else
        shift_enemy_rect(enemy);
    sfSprite_setPosition(enemy->p->s, enemy->p->pos);
}