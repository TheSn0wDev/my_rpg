/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-clement.ozor
** File description:
** events
*/

#ifndef EVENTS_H_
#define EVENTS_H_

void video_settings_button(all_t *a, sfVector2i mouse);
void keybinds_settings_button(all_t *a, sfVector2i mouse);
void volume_settings_button(all_t *a, sfVector2i mouse);
void apply_settings_button(all_t *a, sfEvent event, sfVector2i mouse);
void handle_settings_events(all_t *a);
void handle_settings_buttons(all_t *a, sfEvent event);
void handle_vsync_status(all_t *a, sfVector2i mousepos);
void handle_maxfps_status(all_t *a, sfVector2i mousepos);
void handle_particles_status(all_t *a, sfVector2i mousepos);
void handle_enable_sfx_status(all_t *a, sfVector2i mousepos);
void handle_enable_music_status(all_t *a, sfVector2i mousepos);
void handle_fps_slider(all_t *a, sfVector2i mousepos);
void handle_music_slider(all_t *a, sfVector2i mousepos);
void handle_sfx_slider(all_t *a, sfVector2i mousepos);
void assign_keybind(sfText **text, int *to_bind, char new_bind);
void create_keybinds_sprites(all_t *a, int n, menu_object_t keybinds,
text_object_t keybinds_txt);
void create_sliders_percent(all_t *a);
int keybindings_buttons(all_t *a, menu_object_t sprite,
sfEvent event, sfVector2i mouse);
int calc_fps(all_t *all);
int calc_volume(all_t *all);
int calc_sfx(all_t *a);

#endif /* !EVENTS_H_ */
