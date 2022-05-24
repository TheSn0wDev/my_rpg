/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** show_particles.c
*/

#include "rpg.h"
#include "struct.h"

void update_weather(all_t *a)
{
    if (a->settings->particles == false || a->particles.weather == 0)
        return;
    if (sfKeyboard_isKeyPressed(a->key_arr[0] - 97))
        a->particles.speed = 20;
    else
        a->particles.speed = 15;
    if (get_seconds(a->particles.clock) > 0.02) {
        add_particles(&a->particles, 6, a->particles.weather);
        for (size_t index = 0; index != 1000; index++)
            update_particle(&a->particles, &a->particles.particle[index]);
        sfClock_restart(a->particles.clock);
    }
}

void display_weather(all_t *a)
{
    if (a->settings->particles == false || a->particles.weather == 0)
        return;
    if (a->map.world == BOSS || a->map.world == DUNGEON)
        return;
    display_particles(a, &a->particles);
}

void start_weather(all_t *a)
{
    int nb = rand() % 3;
    sfColor color = {0, 0, 0, 200};

    if (nb == 1) {
        a->particles.weather = 1;
        color.g = 40;
        color.b = 150;
    } else if (nb == 2) {
        a->particles.weather = 2;
        color.r = 255;
        color.g = 255;
        color.b = 255;
    } else
        a->particles.weather = 0;
    if (a->map.world == BOSS || a->map.world == DUNGEON)
        a->particles.weather = 0;
    init_particles(&a->particles, color);
}