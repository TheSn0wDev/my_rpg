/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** transition between maps
*/

#include "rpg.h"
#include "struct.h"

void make_transition_between_maps(all_t *a)
{
    sfClock *clock = create_clock();
    float seconds = 0;
    sfTime time;

    if (a->map.transition == true) {
        while (seconds < 1) {
            time = sfClock_getElapsedTime(clock);
            seconds = time.microseconds / 1000000.0;
            sfRenderWindow_clear(a->window, sfBlack);
            sfRenderWindow_drawSprite(a->window,
            a->map.tran_wall[0].s, NULL);
            sfRenderWindow_display(a->window);
        }
    }
    start_weather(a);
    a->map.transition = false;
}