/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-clement.ozor
** File description:
** settings
*/

#ifndef SETTINGS_H_
#define SETTINGS_H_

typedef enum settings_status {
    VIDEO,
    VOLUME,
    KEYBINDS
} settings_status;

void create_settings_sprites(all_t *a);
void create_keybinds_sprites(all_t *a, int n, menu_object_t keybinds,
text_object_t keybinds_txt);
void create_sliders_percent(all_t *a);

#endif /* !SETTINGS_H_ */