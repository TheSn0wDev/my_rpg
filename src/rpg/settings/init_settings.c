/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-clement.ozor
** File description:
** init_settings
*/

#include "rpg.h"
#include "settings.h"
#include "struct.h"

void init_settings(all_t *a)
{
    int n = 8;
    sfColor color =  sfColor_fromRGBA(220, 118, 51, 255);
    menu_object_t keybinds = {0, 0, {0.8, 0.5},
    {1154, 350}, 0, 0, {0, 0, 465, 84}, 0};
    text_object_t keybinds_txt = {0, 0, {1330, 350}, 19, color, 0};

    a->settings->fps_clock = create_clock();
    a->settings->status = VIDEO;
    a->settings->changing_key = false;
    a->settings[1].keytxt = my_malloc(sizeof(text_object_t) * ((n + 1) * 2));
    a->settings[1].keygui = my_malloc(sizeof(menu_object_t) * (n + 1));
    create_sliders_percent(a);
    create_settings_sprites(a);
    create_keybinds_sprites(a, n, keybinds, keybinds_txt);
}