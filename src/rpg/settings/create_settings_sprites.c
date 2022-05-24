/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-clement.ozor
** File description:
** create_settings_sprites
*/

#include "struct.h"
#include "rpg.h"
#include <string.h>

void check_boxes_sprites(all_t *a)
{
    menu_object_t tick = {0, 0, {1, 1}, {-500, -500}, 0, 0, {0, 0, 35, 37}, 0};

    for (int i = 6; i < 12; i++) {
        init_menu_object(&tick, "assets/settings/tick.png");
        a->settings[0].interface[i] = tick;
    }
}

void slider_sprites(all_t *a)
{
    menu_object_t slidersfx = {0, 0, {1, 1},
    {847, 403}, 0, 0, {0, 0, 20, 31}, 0};
    menu_object_t slidervolume = {0, 0, {1, 1},
    {847, 526}, 0, 0, {0, 0, 20, 31}, 0};

    init_menu_object(&slidersfx, "assets/settings/slider.png");
    init_menu_object(&slidervolume, "assets/settings/slider.png");
    a->settings[0].interface[13] = slidervolume;
    a->settings[0].interface[14] = slidersfx;
}

void create_apply_button_sprite(all_t *a)
{
    menu_object_t applysettings = {0, 0, {1, 1},
    {1350, 870}, 0, 0, {0, 0, 145, 37.3}, 0};

    init_menu_object(&applysettings, "assets/settings/applysettings.png");
    a->settings[0].interface[5] = applysettings;
    sfSprite_setScale(a->settings[0].interface[5].s, (sfVector2f){1.5, 1.5});
    a->settings[0].interface[5].rect.width *= 1.5;
    a->settings[0].interface[5].rect.height *= 1.5;
    check_boxes_sprites(a);
}

void create_volumegui_sprites(all_t *a)
{
    menu_object_t volumegui = {0, 0, {1, 1},
    {313, 104}, 0, 0, {0, 0, 1294, 864}, 0};
    menu_object_t keybindgui = {0, 0, {1, 1},
    {313, 104}, 0, 0, {0, 0, 1294, 864}, 0};
    menu_object_t volumeb = {0, 0, {1, 1},
    {370, 304}, 0, 0, {0, 0, 303, 53}, 0};

    init_menu_object(&volumeb, "assets/settings/sound_buttons.png");
    init_menu_object(&volumegui, "assets/settings/volume_settings.png");
    init_menu_object(&keybindgui, "assets/settings/keybind_settings.png");
    a->settings[0].interface[1] = volumegui;
    a->settings[0].interface[3] = volumeb;
    a->settings[0].interface[21] = keybindgui;
}

void create_settings_sprites(all_t *a)
{
    menu_object_t videogui = {0, 0, {1, 1},
    {313, 104}, 0, 0, {0, 0, 1294, 864}, 0};
    menu_object_t videob = {0, 0, {1, 1},
    {370, 250}, 0, 0, {0, 0, 303, 53}, 0};
    menu_object_t keybindsb = {0, 0, {1, 1},
    {370, 358}, 0, 0, {0, 0, 303, 53}, 0};

    init_menu_object(&videogui, "assets/settings/video_settings.png");
    init_menu_object(&videob, "assets/settings/video_buttons.png");
    init_menu_object(&keybindsb, "assets/settings/keybinds_button.png");
    a->settings[0].interface[0] = videogui;
    a->settings[0].interface[2] = videob;
    a->settings[0].interface[4] = keybindsb;
    sfSprite_setScale(a->settings[0].interface[4].s, (sfVector2f){1.01, 1});
    create_volumegui_sprites(a);
    create_apply_button_sprite(a);
}