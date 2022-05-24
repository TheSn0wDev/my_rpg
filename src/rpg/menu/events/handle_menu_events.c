/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-clement.ozor
** File description:
** handle_menu_events
*/
/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** game events
*/

#include "rpg.h"
#include "events.h"
#include "struct.h"

bool nicknamebar_over(all_t *a, sfVector2i mouse)
{
    if (is_sprite_hovered(a->main_menu->button[3], mouse) == true) {
        return (true);
    }
    return (false);
}

int nickname_bar_event_two(all_t *a, sfEvent event, int index)
{
    if (event.type == sfEvtKeyReleased && event.key.code == sfKeyBackspace) {
        if (index > 0) {
            a->main_menu->pseudo_taken = is_nickname_taken(a);
            a->main_menu->nickname[index - 1] = '\0';
            index--;
        }
    }
    return (index);
}

char *nickname_bar_event(all_t *a, sfEvent event, sfVector2i mouse)
{
    static bool enternick = false;
    static int index = 0;

    if (nicknamebar_over(a, mouse) == false)
        enternick = false;
    else
        enternick = true;
    if (enternick == true && event.key.code >= 97 &&
    event.key.code <= 122 && index < 8) {
        a->main_menu->nickname[index] =
        event.key.code;
        index++;
        enternick = false;
        a->main_menu->pseudo_taken = is_nickname_taken(a);
    }
    index = nickname_bar_event_two(a, event, index);
    return (NULL);
}

void handle_menu_events(all_t *a)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(a->window, &event)) {
        handle_menu_buttons(a, event);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            a->scene = QUIT;
        if (event.type == sfEvtClosed)
            a->scene = QUIT;
    }
}