/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-clement.ozor
** File description:
** handle_settings_events
*/

#include "rpg.h"
#include "events.h"
#include "struct.h"
#include "../settings.h"

void handle_settings_events(all_t *a)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(a->window, &event)) {
        handle_settings_buttons(a, event);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            a->scene = QUIT;
        if (event.type == sfEvtClosed)
            a->scene = QUIT;
    }
}