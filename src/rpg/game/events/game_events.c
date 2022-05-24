/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** game events
*/

#include "rpg.h"
#include "struct.h"

void pause_game(all_t *a);

void inventory_events(all_t *a, sfEvent event);

int get_key(all_t *a)
{
    if (sfKeyboard_isKeyPressed(a->key_arr[0] - 97)) {
        return (a->key_arr[0] - 97);
    }
    if (sfKeyboard_isKeyPressed(a->key_arr[1] - 97)) {
        return (a->key_arr[1] - 97);
    }
    if (sfKeyboard_isKeyPressed(a->key_arr[2] - 97)) {
        return (a->key_arr[2] - 97);
    }
    if (sfKeyboard_isKeyPressed(a->key_arr[3] - 97)) {
        return (a->key_arr[3] - 97);
    }
    return (0);
}

void player_input(all_t *a)
{
    if (!a->in_dialogue && get_key(a) != 0) {
        make_player_walk(a, get_key(a));
        if (push_map(a, get_key(a)) == 0) {
            move_player(a, get_key(a));
        }
    }
}

void handle_game_events(all_t *a)
{
    sfEvent event;

    player_input(a);
    check_npc_interaction(a);
    while (sfRenderWindow_pollEvent(a->window, &event)) {
        inventory_events(a, event);
        if (event.type == sfEvtClosed)
            a->scene = QUIT;
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape) {
            pause_game(a);
        }
        if (event.type == sfEvtKeyReleased && event.key.code == sfKeySpace)
            check_interaction(a);
        if (event.type == sfEvtClosed)
            a->scene = QUIT;
    }
}