/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** handle_combat.c
*/

#include <rpg.h>
#include <struct.h>
#include "combat.h"

void play_sfx(all_t *a, sfMusic *sfx)
{
    sfMusic_stop(sfx);
    sfMusic_setVolume(sfx, a->settings->sfx);
    sfMusic_play(sfx);
}

void handle_combat(all_t *a)
{
    while (a->scene == COMBAT) {
        analyse_combat_events(a);
        update_combat(a);
        sfRenderWindow_clear(a->window, sfBlack);
        display_combat(a);
        sfRenderWindow_display(a->window);
    }
    a->player->obj->pos = a->combat.save_pos;
}