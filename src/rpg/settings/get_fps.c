/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-clement.ozor
** File description:
** get_fps
*/

#include "rpg.h"
#include "struct.h"
#include "settings.h"
#include "./events/events.h"

void get_fps(all_t *a)
{
    int fps_nb = 0;
    float current_time = 0;

    current_time = sfTime_asSeconds(sfClock_restart(a->settings->fps_clock));
    fps_nb = 1.f / current_time;
    sfText_setString(a->settings->fps, my_itoa(fps_nb));
    sfRenderWindow_drawText(a->window, a->settings->fps, NULL);
}

void set_music_volumes(all_t *a, float volume)
{
    sfMusic_setVolume(a->main_menu->menu_music, volume);
}

void set_sfx_volumes(all_t *a, float volume)
{
    a->settings->sfx = volume;
}

void activate_options_settings(all_t *a)
{
    if (a->settings->vsync == true)
        sfRenderWindow_setVerticalSyncEnabled(a->window, sfTrue);
    else
        sfRenderWindow_setVerticalSyncEnabled(a->window, sfFalse);
    if (a->settings->showfps == true)
        get_fps(a);
    if (a->settings->enable_music == false)
        set_music_volumes(a, 0);
    else
        set_music_volumes(a, a->settings->music);
    if (a->settings->enable_sfx == false)
        set_sfx_volumes(a, 0);
    else
        set_sfx_volumes(a, a->settings->sfx);
}