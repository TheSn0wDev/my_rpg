/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** set players position
*/

#include "rpg.h"
#include "struct.h"

void change_player_rect(all_t *a, int top)
{
    if (get_seconds(a->player->obj->clock) > 0.05) {
        if (a->player->obj->rect.left == (int){a->player->skin * (160 * 3)}) {
            a->player->obj->rect.left = a->player->skin * (160 * 3) + 320;
        } else {
            a->player->obj->rect.left -= 160;
        }
        a->player->obj->rect.top = top;
        sfSprite_setTextureRect(a->player->obj->s, a->player->obj->rect);
        sfClock_restart(a->player->obj->clock);
    }
}

void make_player_walk(all_t *a, sfKeyCode code)
{
    if (code == a->key_arr[0] - 97) {
        change_player_rect(a, 407);
    }
    if (code == a->key_arr[1] - 97) {
        change_player_rect(a, 137);
    }
    if (code == a->key_arr[2] - 97) {
        change_player_rect(a, 2);
    }
    if (code == a->key_arr[3] - 97) {
        change_player_rect(a, 272);
    }
}

void move_player(all_t *a, sfKeyCode code)
{
    a->player->obj->velocity = (sfVector2f){0, 0};
    if (code == a->key_arr[0] - 97 && is_colliding(a, code) != 1) {
        a->player->obj->velocity.y = -4;
    }
    if (code == a->key_arr[2] - 97 && is_colliding(a, code) != 1) {
        a->player->obj->velocity.y = 4;
    }
    if (code == a->key_arr[1] - 97 && is_colliding(a, code) != 1) {
        a->player->obj->velocity.x = -4;
    }
    if (code == a->key_arr[3] - 97 && is_colliding(a, code) != 1) {
        a->player->obj->velocity.x = 4;
    }
}

void set_player_pos(all_t *a)
{
    if (get_seconds(a->player->movement) > 0.01) {
        a->player->obj->pos.x += a->player->obj->velocity.x;
        a->player->obj->pos.y += a->player->obj->velocity.y;
        sfSprite_setPosition(a->player->obj->s, a->player->obj->pos);
        a->player->obj->velocity = (sfVector2f){0, 0};
        sfClock_restart(a->player->movement);
    }
}