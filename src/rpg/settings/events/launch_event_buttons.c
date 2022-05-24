/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-clement.ozor
** File description:
** launch_event_buttons
*/

#include "struct.h"
#include "rpg.h"
#include "events.h"
#include "../settings.h"

void launch_videogui_events(all_t *a, sfVector2i mousepos)
{
    handle_vsync_status(a, mousepos);
    handle_maxfps_status(a, mousepos);
    handle_particles_status(a, mousepos);
}

void launch_volumegui_events(all_t *a, sfVector2i mousepos)
{
    handle_enable_sfx_status(a, mousepos);
    handle_enable_music_status(a, mousepos);
    handle_sfx_slider(a, mousepos);
    handle_music_slider(a, mousepos);
}

void launch_keybindsgui_events(all_t *a, sfEvent event, sfVector2i mousepos)
{
    static int value = 0;
    char *c = my_malloc(sizeof(char) * 2);

    c[1] = '\0';
    for (int index = 0; index <= 8 &&
    a->settings->changing_key == false; index++) {
        if (keybindings_buttons(a, a->settings[1].keygui[index],
        event, mousepos) == 1) {
            a->settings->changing_key = true;
            value = index;
            break;
        }
    }
    if (event.key.code >= 97 && event.key.code <= 122 &&
    a->settings->changing_key == true) {
        c[0] = event.key.code;
        sfText_setString(a->settings[1].keytxt[value].text, c);
        a->key_arr[value] = event.key.code;
        a->settings->changing_key = false;
    }
}

void handle_settings_buttons(all_t *a, sfEvent event)
{
    sfVector2i mousepos = sfMouse_getPositionRenderWindow(a->window);

    video_settings_button(a, mousepos);
    volume_settings_button(a, mousepos);
    keybinds_settings_button(a, mousepos);
    apply_settings_button(a, event, mousepos);
    if (a->settings->status == VIDEO) {
        launch_videogui_events(a, mousepos);
    }
    if (a->settings->status == VOLUME) {
        launch_volumegui_events(a, mousepos);
    }
    if (a->settings->status == KEYBINDS) {
        launch_keybindsgui_events(a, event, mousepos);
    }
}