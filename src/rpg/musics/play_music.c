/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-clement.ozor
** File description:
** play_music
*/

#include "struct.h"
#include "rpg.h"

void load_your_music(all_t *a, char *str, char t)
{
    static bool created = false;
    sfMusic *music;

    if (created == false) {
        music = create_music(str);
        sfMusic_play(music);
        sfMusic_setVolume(music, a->settings->sfx);
    }
}