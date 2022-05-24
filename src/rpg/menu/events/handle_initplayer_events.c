/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-clement.ozor
** File description:
** handle_initplayer_events
*/

#include "struct.h"
#include "rpg.h"
#include "events.h"

void scale_arrow_button(all_t *a, sfVector2i mouse)
{
    if (is_sprite_hovered(a->main_menu->button[4], mouse))
        sfSprite_setScale(a->main_menu->button[4].s, (sfVector2f){0.75, 0.75});
    else
        sfSprite_setScale(a->main_menu->button[4].s, (sfVector2f){0.65, 0.65});
}

void change_skin(all_t *a, sfEvent event)
{
    sfIntRect player_rect;

    if (event.type != sfEvtMouseButtonReleased)
        return;
    if (a->player->skin < 3)
        a->player->skin += 1;
    else if (a->player->skin == 3)
        a->player->skin = 0;
    player_rect = (sfIntRect){a->player->skin * (160 * 3), 0, 160, 135};
    a->main_menu->button[5].rect = player_rect;
    sfSprite_setTextureRect(a->main_menu->button[5].s, player_rect);
}

void arrow_button(all_t *a, sfEvent event, sfVector2i mouse)
{
    scale_arrow_button(a, mouse);
    if (is_sprite_hovered(a->main_menu->button[4], mouse))
        change_skin(a, event);
}

bool check_string_char(char *str, char c)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] != '\0' && str[i] != c)
            return (false);
    }
    return (true);
}