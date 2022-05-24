/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-clement.ozor
** File description:
** handle_volumes_settings
*/

#include "rpg.h"
#include "events.h"
#include "struct.h"
#include "../settings.h"

void handle_enable_music_status(all_t *a, sfVector2i mousepos)
{
    if (sfMouse_isButtonPressed(sfMouseLeft))
        if (756 <= mousepos.x && mousepos.x <= 756 + 26 && 326 <= mousepos.y
        && mousepos.y <= 326 + 24) {
            a->settings->enable_music = !a->settings->enable_music;
            sfSprite_setPosition(a->settings[0].interface[9].s,
            (sfVector2f){750, 322});
            play_sfx(a, a->sfx.click);
        }
    if (a->settings->enable_music == true) {
        sfSprite_setPosition(a->settings[0].interface[9].s,
        (sfVector2f){750, 322});
    }
    if (a->settings->enable_music == false) {
        sfSprite_setPosition(a->settings[0].interface[9].s,
        (sfVector2f){-756, -419});
    }
}

void handle_enable_sfx_status(all_t *a, sfVector2i mousepos)
{
    if (sfMouse_isButtonPressed(sfMouseLeft))
        if (756 <= mousepos.x && mousepos.x <= 756 + 26 && 445 <= mousepos.y
        && mousepos.y <= 445 + 24) {
            a->settings->enable_sfx = !a->settings->enable_sfx;
            sfSprite_setPosition(a->settings[0].interface[10].s,
            (sfVector2f){750, 441});
            play_sfx(a, a->sfx.click);
        }
    if (a->settings->enable_sfx == true) {
        sfSprite_setPosition(a->settings[0].interface[10].s,
        (sfVector2f){750, 441});
    }
    if (a->settings->enable_sfx == false) {
        sfSprite_setPosition(a->settings[0].interface[10].s,
        (sfVector2f){-756, -419});
    }
}

void handle_sfx_slider(all_t *a, sfVector2i mousepos)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == true && 773 <= mousepos.x
    && mousepos.x <=  773 + 264 && 526 <= mousepos.y
    && mousepos.y <= 550 + 10) {
        sfSprite_setPosition(a->settings[0].interface[13].s,
        (sfVector2f){mousepos.x - 10, 526});
        a->settings->sfx = calc_sfx(a);
    }
}

void handle_music_slider(all_t *a, sfVector2i mousepos)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == true &&
    773 <= mousepos.x && mousepos.x <=  773 + 264 && 403 <= mousepos.y
    && mousepos.y <= 428 + 10) {
        sfSprite_setPosition(a->settings[0].interface[14].s,
        (sfVector2f){mousepos.x - 10, 403});
        a->settings->music = calc_volume(a);
    }
}