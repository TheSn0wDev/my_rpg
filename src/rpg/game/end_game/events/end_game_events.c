/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-clement.ozor
** File description:
** end_game_events
*/

#include "rpg.h"
#include "struct.h"

void handle_end_game_events(all_t *a)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(a->window, &event)) {
        if (event.type == sfEvtKeyReleased && event.key.code == sfKeySpace)
            check_interaction(a);
        if (event.type == sfEvtClosed)
            a->scene = QUIT;
    }
}