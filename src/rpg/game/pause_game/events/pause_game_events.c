/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-clement.ozor
** File description:
** pause_game_events
*/

#include "events.h"
#include "rpg.h"
#include "struct.h"

void handle_pausegame_events(all_t *a)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(a->window, &event)) {
        handle_pause_buttons(a, event);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape) {
            a->pause->status = a->scene;
        }
    }
}