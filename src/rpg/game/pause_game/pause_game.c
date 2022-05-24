/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-clement.ozor
** File description:
** pause_game
*/

#include "rpg.h"
#include "struct.h"
#include "pause_game.h"
#include "./events/events.h"

void status_changes_two(all_t *a)
{
    if (a->pause->status == SETTINGS) {
        a->scene = SETTINGS;
        init_settings(a);
        handle_settings(a);
        a->scene = GAME;
        a->pause->status = -9;
    }
}

int status_changes(all_t *a)
{
    if (a->pause->status == QUIT) {
        a->scene = QUIT;
        return (-1);
    }
    if (a->pause->status == GAME) {
        a->scene = GAME;
        return (-1);
    }
    if (a->pause->status == COMBAT) {
        a->scene = COMBAT;
        return (-1);
    }
    status_changes_two(a);
    if (a->pause->status == MENU) {
        a->pause->status = a->scene;
        a->scene = MENU;
        return (-1);
    }
    return (0);
}

void show_skin_walking_in_pause(all_t *a)
{
    if (get_seconds(a->pause->interface[4].clock) > 0.2) {
        if (a->pause->interface[4].rect.left ==
        (int){a->player->skin * (160 * 3)}) {
            a->pause->interface[4].rect.left =
            a->player->skin * (160 * 3) + 320;
        } else {
            a->pause->interface[4].rect.left -= 160;
        }
        sfSprite_setTextureRect(a->pause->interface[4].s,
        a->pause->interface[4].rect);
        sfClock_restart(a->pause->interface[4].clock);
    }
}

void display_pause(all_t *a)
{
    sfRenderWindow_drawRectangleShape(a->window, a->pause->blacklayer, NULL);
    sfRenderWindow_drawSprite(a->window, a->pause[0].interface[0].s, NULL);
    sfRenderWindow_drawSprite(a->window, a->pause[0].interface[1].s, NULL);
    sfRenderWindow_drawSprite(a->window, a->pause[0].interface[2].s, NULL);
    sfRenderWindow_drawSprite(a->window, a->pause[0].interface[4].s, NULL);
    sfRenderWindow_drawSprite(a->window, a->pause[0].interface[3].s, NULL);
    sfRenderWindow_drawText(a->window, a->pause->nickname, NULL);
}

void pause_game(all_t *a)
{
    a->pause->status = 99;
    create_black_layer(a);
    create_pausegame_sprites(a);
    a->pause->paused = true;
    while (a->pause->paused == true) {
        sfRenderWindow_clear(a->window, sfBlack);
        handle_pausegame_events(a);
        if (a->scene == GAME)
            display_game(a);
        if (a->scene == COMBAT)
            display_combat(a);
        if (status_changes(a) == -1)
            a->pause->paused = false;
        display_pause(a);
        show_skin_walking_in_pause(a);
        sfRenderWindow_display(a->window);
    }
}