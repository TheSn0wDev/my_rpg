/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** update_combat.c
*/

#include <rpg.h>
#include <struct.h>
#include "combat.h"

void check_end_game(all_t *a)
{
    if (a->combat.player.hp.value == 0)
        a->scene = GAME_OVER;
    if (a->combat.enemy.hp.value == 0) {
        a->scene = COMBAT_WIN;
    }
}

void update_combat(all_t *a)
{
    analyse_combat_events(a);
    if (get_seconds(a->combat.clock) > 0.03) {
        continue_player_action(a, &a->combat.player, &a->combat.enemy);
        update_attacks(a, &a->combat.enemy, &a->combat.player.my_attacks);
        update_enemy(a, &a->combat.player, a->combat.player.ground, 0);
        update_cooldowns(a, &a->combat.player);
        update_gauge_hp(&a->combat.player.hp, &a->combat.player);
        get_next_action(a, &a->combat.enemy, &a->combat.player);
        update_attacks(a, &a->combat.player, &a->combat.enemy.my_attacks);
        update_enemy(a, &a->combat.enemy, a->combat.enemy.ground, 1);
        update_gauge_hp(&a->combat.enemy.hp, &a->combat.enemy);
        sfClock_restart(a->combat.clock);
    }
    check_end_game(a);
}

void draw_attacks(sfRenderWindow *window, attack_t **attacks)
{
    attack_t *temp = (*attacks);

    for (int i = 0; temp; temp = temp->next, i++)
        sfRenderWindow_drawSprite(window, temp->s, NULL);
}

void display_combat(all_t *a)
{
    sfRenderWindow_drawSprite(a->window, a->combat.map.s, NULL);
    sfRenderWindow_drawSprite(a->window, a->combat.enemy.p->s, NULL);
    sfRenderWindow_drawSprite(a->window, a->combat.player.p->s, NULL);
    display_cooldowns(a->window, &a->combat.player);
    draw_attacks(a->window, &a->combat.player.my_attacks);
    draw_attacks(a->window, &a->combat.enemy.my_attacks);
    draw_gauge(a->window, &a->combat.player.hp);
    draw_gauge(a->window, &a->combat.enemy.hp);
}