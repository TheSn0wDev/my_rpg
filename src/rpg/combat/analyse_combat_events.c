/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** analyse_events.c
*/

#include <rpg.h>
#include <struct.h>
#include "combat.h"

void pause_game(all_t *a);

void change_state(sfEvent event, states_t *state, states_t on, states_t off)
{
    if (event.key.type == sfEvtKeyPressed)
        (*state) = on;
    if (event.key.type == sfEvtKeyReleased)
        (*state) = off;
}

void get_player_inputs(all_t *a, combat_t *combat, sfEvent event)
{
    states_t combat_state = combat->player.combat_state;

    if (combat_state == COOL && event.key.type != sfEvtKeyReleased)
        return;
    if (event.key.code == a->key_arr[6] - 97) {
        combat->player.current_attack = 0;
        change_state(event, &combat->player.combat_state, ATTACK, IDLE);
    }
    if (event.key.code == a->key_arr[7] - 97) {
        combat->player.current_attack = 1;
        change_state(event, &combat->player.combat_state, ATTACK, IDLE);
    }
    if (event.key.code == a->key_arr[8] - 97) {
        combat->player.current_attack = 2;
        change_state(event, &combat->player.combat_state, ATTACK, IDLE);
    }
}

void analyse_combat_events(all_t *a)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(a->window, &event)) {
        get_player_inputs(a, &a->combat, event);
        if (event.type == sfEvtClosed)
            a->scene = QUIT;
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            pause_game(a);
    }
}