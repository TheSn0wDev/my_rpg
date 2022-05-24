/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-clement.ozor
** File description:
** handle_video_settings
*/

#include "rpg.h"
#include "events.h"
#include "struct.h"
#include "../settings.h"

bool is_sprite_hovered(menu_object_t sprite, sfVector2i mouse);

void handle_vsync_status(all_t *a, sfVector2i mousepos)
{
    if (sfMouse_isButtonPressed(sfMouseLeft))
        if (756 <= mousepos.x && mousepos.x <= 756 + 26 && 419 <= mousepos.y
        && mousepos.y <= 419 + 24) {
            a->settings->vsync = !a->settings->vsync;
            sfSprite_setPosition(a->settings[0].interface[6].s,
            (sfVector2f){750, 414});
            play_sfx(a, a->sfx.click);
        }
    if (a->settings->vsync == true) {
        sfSprite_setPosition(a->settings[0].interface[6].s,
        (sfVector2f){750, 414});
    }
    if (a->settings->vsync == false) {
        sfSprite_setPosition(a->settings[0].interface[6].s,
        (sfVector2f){-756, -419});
    }
}

void handle_particles_status(all_t *a, sfVector2i mousepos)
{
    if (sfMouse_isButtonPressed(sfMouseLeft))
        if (756 <= mousepos.x && mousepos.x <= 756 + 26 && 467 <= mousepos.y
        && mousepos.y <= 467 + 24) {
            a->settings->particles = !a->settings->particles;
            sfSprite_setPosition(a->settings[0].interface[7].s,
            (sfVector2f){750, 464});
            play_sfx(a, a->sfx.click);
        }
    if (a->settings->particles == true) {
        sfSprite_setPosition(a->settings[0].interface[7].s,
        (sfVector2f){750, 464});
    }
    if (a->settings->particles == false) {
        sfSprite_setPosition(a->settings[0].interface[7].s,
        (sfVector2f){-756, -419});
    }
}

void handle_maxfps_status(all_t *a, sfVector2i mousepos)
{
    if (sfMouse_isButtonPressed(sfMouseLeft))
        if (756 <= mousepos.x && mousepos.x <= 756 + 26 && 523 <= mousepos.y
        && mousepos.y <= 523 + 24) {
            a->settings->showfps = !a->settings->showfps;
            sfSprite_setPosition(a->settings[0].interface[8].s,
            (sfVector2f){750, 519});
            play_sfx(a, a->sfx.click);
        }
    if (a->settings->showfps == true) {
        sfSprite_setPosition(a->settings[0].interface[8].s,
        (sfVector2f){750, 519});
    }
    if (a->settings->showfps == false) {
        sfSprite_setPosition(a->settings[0].interface[8].s,
        (sfVector2f){-756, -419});
    }
}