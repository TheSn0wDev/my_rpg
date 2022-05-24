/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** show player move
*/

#include "rpg.h"
#include "struct.h"

void show_skin_walking_in_menu(all_t *a)
{
    player_skin_t player_skin = a->player->skin;

    if (get_seconds(a->main_menu->button[5].clock) > 0.2) {
        if (a->main_menu->button[5].rect.left ==
        (int){player_skin} * (160 * 3)) {
            a->main_menu->button[5].rect.left = player_skin * (160 * 3) + 320;
        } else {
            a->main_menu->button[5].rect.left -= 160;
        }
        sfSprite_setTextureRect(a->main_menu->button[5].s,
        a->main_menu->button[5].rect);
        sfClock_restart(a->main_menu->button[5].clock);
    }
}