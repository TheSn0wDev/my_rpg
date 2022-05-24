/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-clement.ozor
** File description:
** handle_menu_events
*/

#include "struct.h"
#include "rpg.h"
#include "events.h"
#include "../settings.h"

bool is_sprite_hovered(menu_object_t sprite, sfVector2i mouse);

void video_settings_button(all_t *a, sfVector2i mouse)
{
    if (is_sprite_hovered(a->settings[0].interface[2], mouse) &&
    sfMouse_isButtonPressed(sfMouseLeft)) {
        sfSprite_setTextureRect(a->settings[0].interface[2].s,
        (sfIntRect){0, 56, 303, 53});
        a->settings->status = VIDEO;
        play_sfx(a, a->sfx.click);
    }
    if (a->settings->status != VIDEO)
        sfSprite_setTextureRect(a->settings[0].interface[2].s,
        (sfIntRect){0, 0, 303, 53});
}

void volume_settings_button(all_t *a, sfVector2i mouse)
{
    if (is_sprite_hovered(a->settings[0].interface[3], mouse) &&
    sfMouse_isButtonPressed(sfMouseLeft)) {
        sfSprite_setTextureRect(a->settings[0].interface[3].s,
        (sfIntRect){0, 56, 303, 53});
        a->settings->status = VOLUME;
        play_sfx(a, a->sfx.click);
    }
    if (a->settings->status != VOLUME)
        sfSprite_setTextureRect(a->settings[0].interface[3].s,
        (sfIntRect){0, 0, 303, 53});
}

void keybinds_settings_button(all_t *a, sfVector2i mouse)
{
    if (is_sprite_hovered(a->settings[0].interface[4], mouse) &&
    sfMouse_isButtonPressed(sfMouseLeft)) {
        sfSprite_setTextureRect(a->settings[0].interface[4].s,
        (sfIntRect){0, 56, 303, 53});
        a->settings->status = KEYBINDS;
        play_sfx(a, a->sfx.click);
    }
    if (a->settings->status != KEYBINDS)
        sfSprite_setTextureRect(a->settings[0].interface[4].s,
        (sfIntRect){0, 0, 303, 53});
}

void apply_settings_button(all_t *a, sfEvent event, sfVector2i pos)
{
    static bool pressed = false;

    if (is_sprite_hovered(a->settings[0].interface[5], pos))
        sfSprite_setTextureRect(a->settings[0].interface[5].s,
        (sfIntRect){0, 37.3, 145, 37.3});
    else {
        sfSprite_setTextureRect(a->settings[0].interface[5].s,
        (sfIntRect){0, 0, 145, 37.3});
        pressed = false;
    }
    if (pressed == true || (is_sprite_hovered(a->settings[0].interface[5], pos)
    && sfMouse_isButtonPressed(sfMouseLeft))) {
        sfSprite_setTextureRect(a->settings[0].interface[5].s,
        (sfIntRect){0, 37.3 * 2, 145, 37.31});
        pressed = true;
        play_sfx(a, a->sfx.click);
    }
    if (is_sprite_hovered(a->settings[0].interface[5], pos))
        if (event.type == sfEvtMouseButtonReleased)
            a->scene = MENU;
}